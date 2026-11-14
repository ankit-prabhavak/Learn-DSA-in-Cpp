import os
import csv
import json
import glob
from collections import defaultdict

import openpyxl
from openpyxl.styles import Font, PatternFill, Alignment, Border, Side
from openpyxl.utils import get_column_letter
from openpyxl.formatting.rule import DataBarRule
from openpyxl.worksheet.properties import PageSetupProperties

# ---------------------------------------------------------------------------
# CONFIG
# ---------------------------------------------------------------------------
ACCOUNT_ENVIRONMENTS = {
    "468681639671": "DEV & UAT",
    "611950011201": "DEMO",
}
ENV_SORT_ORDER = {"DEV & UAT": 1, "DEMO": 2}

PRODUCT_NAME = "Manage"

INPUT_DIR = "raw_json"
OUTPUT_DIR = "output_combined"
EXCEL_PATH = os.path.join(OUTPUT_DIR, "AWS_Cost_Optimization_Master_Report.xlsx")
CSV_PATH = os.path.join(OUTPUT_DIR, "AWS_Cost_Optimization_Master_Report.csv")

CATEGORY_MAP = {
    "1_": "ASG_&_LoadBalancers",
    "2_": "CloudWatch_Logs",
    "3_": "Snapshots",
    "4_": "EC2_Instances",
    "5_": "EBS_Volumes",
    "6_": "Elastic_IPs",
    "7_": "ECR_Repositories",
    "8_": "S3_Buckets",
    "9_": "RDS_Databases",
    "10_": "Secrets_Manager",
    "11_": "MSK_Kafka",
    "12_": "OffHours_Schedules",
    "13_": "IAM_Users",
    "14_": "VPC_Networking",
    "15_": "Route53_DNS",
    "16_": "EFS_Storage",
    "17_": "Amazon_Bedrock",
    "18_": "EKS_Clusters",
    "19_": "NAT_Gateways",
    "20_": "ElastiCache",
    "21_": "OpenSearch",
    "22_": "KMS_Keys",
}

MASTER_SHEET = "All_Resources_Master"

# ---------------------------------------------------------------------------
# DESIGN SYSTEM  (one navy family + one teal accent + soft semantic badges)
# ---------------------------------------------------------------------------
FONT_FAMILY = "Calibri"

NAVY = "14213D"        # title banner
NAVY_SOFT = "1F3358"   # subtitle bar / table header
ACCENT = "0EA5A4"      # thin accent line under the title
INK = "1E293B"         # body text
MUTED = "64748B"       # secondary text
LINE = "D5DBE3"        # cell borders
ZEBRA = "F6F8FB"
TOTAL_BG = "E6ECF5"
NOTES_BG = "FFFDF5"


def fill(hex_color):
    return PatternFill("solid", fgColor=hex_color)


def font(size=10, bold=False, color=INK, italic=False):
    return Font(name=FONT_FAMILY, size=size, bold=bold, italic=italic, color=color)


FONT_TITLE = font(18, True, "FFFFFF")
FONT_SUBTITLE = font(10, False, "C7D2E5")
FONT_SEC = font(12, True, NAVY)
FONT_TH = font(10, True, "FFFFFF")
FONT_DATA = font(10)
FONT_BOLD = font(10, True)
FONT_MUTED = font(10, False, MUTED)
FONT_KPI_LABEL = font(9, True, MUTED)
FONT_KPI_VALUE = font(20, True, NAVY)

FILL_NAVY = fill(NAVY)
FILL_NAVY_SOFT = fill(NAVY_SOFT)
FILL_ACCENT = fill(ACCENT)
FILL_WHITE = fill("FFFFFF")
FILL_ZEBRA = fill(ZEBRA)
FILL_TOTAL = fill(TOTAL_BG)
FILL_NOTES = fill(NOTES_BG)
FILL_KPI = fill("F1F5FA")

THIN = Side(style="thin", color=LINE)
HAIR = Side(style="hair", color=LINE)
STRONG = Side(style="medium", color=NAVY)
BORDER_DATA = Border(left=HAIR, right=HAIR, top=THIN, bottom=THIN)
BORDER_TH = Border(left=Side(style="thin", color="3A4F78"), right=Side(style="thin", color="3A4F78"),
                   top=STRONG, bottom=STRONG)
BORDER_TOTAL = Border(left=HAIR, right=HAIR, top=STRONG, bottom=STRONG)
BORDER_KPI = Border(left=THIN, right=THIN, top=THIN, bottom=THIN)

# Environment badges
ENV_STYLE = {
    "DEV & UAT": (fill("DCEBFE"), font(10, True, "1E40AF")),
    "DEMO": (fill("FDEBD0"), font(10, True, "9A5B0B")),
}

# Priority badges
PRIORITY_STYLE = {
    "Safe to Delete / Release": (fill("D7F2E3"), font(10, True, "166534")),
    "Configuration / Policy Optimization": (fill("DCEBFE"), font(10, True, "1E40AF")),
    "Verify with Dev / Owner First": (fill("FDEBD0"), font(10, True, "9A5B0B")),
    "Security & Hygiene ($0 Direct)": (fill("EADDFB"), font(10, True, "5B21B6")),
    "Active / No Action Needed": (fill("EDF0F4"), font(10, True, "475569")),
}
PRIORITY_ORDER = list(PRIORITY_STYLE.keys())

MONEY_FMT = '"$"#,##0.00;[Red]-"$"#,##0.00;"–"'
INT_FMT = "#,##0"
PCT_FMT = "0.0%"

# Master sheet column letters (used by Executive Summary formulas)
MASTER_COLS = [
    "Product", "Category", "Environment", "Account_ID", "Region", "Resource_Type",
    "Resource_Name", "Resource_ID", "Status_Details", "Est_Monthly_Savings_USD",
    "Est_Annual_Savings_USD", "Priority_Bucket", "Recommended_Action", "Remarks / Comments",
]
MCOL = {name: get_column_letter(i) for i, name in enumerate(MASTER_COLS, start=1)}

# Friendly header labels shown in the sheets
HEADER_LABELS = {
    "Product": "Product",
    "Category": "Service Category",
    "Environment": "Environment",
    "Account_ID": "Account ID",
    "Region": "Region",
    "Resource_Type": "Resource Type",
    "Resource_Name": "Resource Name",
    "Resource_ID": "Resource ID",
    "Status_Details": "Status / Details",
    "Est_Monthly_Savings_USD": "Est. Monthly Savings (USD)",
    "Est_Annual_Savings_USD": "Est. Annual Savings (USD)",
    "Priority_Bucket": "Priority",
    "Recommended_Action": "Recommended Action",
    "Remarks / Comments": "Remarks / Comments",
}

COL_WIDTH = {
    "Product": 11,
    "Category": 24,
    "Environment": 14,
    "Account_ID": 16,
    "Region": 14,
    "Resource_Type": 22,
    "Resource_Name": 34,
    "Resource_ID": 30,
    "Status_Details": 46,
    "Est_Monthly_Savings_USD": 17,
    "Est_Annual_Savings_USD": 17,
    "Priority_Bucket": 31,
    "Recommended_Action": 40,
    "Remarks / Comments": 34,
}


# ---------------------------------------------------------------------------
# DATA
# ---------------------------------------------------------------------------
def get_category_from_filename(filename):
    base = os.path.basename(filename)
    # longest prefix first so "10_" is never captured by "1_"
    for prefix in sorted(CATEGORY_MAP, key=len, reverse=True):
        if base.startswith(prefix):
            return CATEGORY_MAP[prefix]
    return "Other_Resources"


def classify_priority(action_text, savings):
    act = (action_text or "").lower()
    if "keep" in act or "already scheduled" in act:
        return "Active / No Action Needed"
    if "verify" in act or "review" in act or "deregister" in act:
        return "Verify with Dev / Owner First"
    if savings == 0 or "iam" in act or "cleanup" in act or "dangling" in act:
        return "Security & Hygiene ($0 Direct)"
    if "retention" in act or "lifecycle" in act or "schedule" in act or "right-size" in act:
        return "Configuration / Policy Optimization"
    return "Safe to Delete / Release"


def sort_records(rows):
    return sorted(
        rows,
        key=lambda r: (
            ENV_SORT_ORDER.get(r["Environment"], 99),
            -r["Est_Monthly_Savings_USD"],
            r["Region"],
            r["Resource_Name"],
        ),
    )


def load_all_data():
    json_files = sorted(glob.glob(os.path.join(INPUT_DIR, "*.json")))
    if not json_files:
        raise FileNotFoundError(
            f"No .json files found in '{INPUT_DIR}/'. Please copy your jumphost JSON files there."
        )

    by_category = defaultdict(list)
    all_records = []

    for filepath in json_files:
        category = get_category_from_filename(filepath)
        with open(filepath, "r", encoding="utf-8") as f:
            try:
                items = json.load(f)
            except json.JSONDecodeError as e:
                print(f"Skipping invalid JSON {filepath}: {e}")
                continue

        if not isinstance(items, list):
            continue

        for item in items:
            acc_id = str(item.get("Account_ID", "Unknown"))
            env_label = ACCOUNT_ENVIRONMENTS.get(acc_id, acc_id)
            monthly = float(item.get("Est_Monthly_Savings_USD", 0) or 0)
            action = item.get("Action", "")

            row = {
                "Category": category.replace("_", " "),
                "Product": PRODUCT_NAME,
                "Environment": env_label,
                "Account_ID": acc_id,
                "Region": item.get("Region", ""),
                "Resource_Type": item.get("Resource_Type", ""),
                "Resource_Name": item.get("Resource_Name", ""),
                "Resource_ID": item.get("Resource_ID", ""),
                "Status_Details": item.get("Status_Details", ""),
                "Est_Monthly_Savings_USD": monthly,
                "Est_Annual_Savings_USD": round(monthly * 12, 2),
                "Priority_Bucket": classify_priority(action, monthly),
                "Recommended_Action": action,
                "Remarks / Comments": "",
            }
            by_category[category].append(row)
            all_records.append(row)

    for cat in by_category:
        by_category[cat] = sort_records(by_category[cat])
    return by_category, sort_records(all_records)


# ---------------------------------------------------------------------------
# STYLING HELPERS
# ---------------------------------------------------------------------------
def add_banner(ws, title, subtitle, max_col):
    """Row 1: title, Row 2: subtitle, Row 3: thin accent line. Header starts row 4."""
    for r in (1, 2):
        ws.merge_cells(start_row=r, start_column=1, end_row=r, end_column=max_col)
        for c in range(1, max_col + 1):
            ws.cell(row=r, column=c).fill = FILL_NAVY if r == 1 else FILL_NAVY_SOFT
    for c in range(1, max_col + 1):
        ws.cell(row=3, column=c).fill = FILL_ACCENT

    t = ws.cell(row=1, column=1, value=title)
    t.font = FONT_TITLE
    t.alignment = Alignment(horizontal="left", vertical="center", indent=1)
    s = ws.cell(row=2, column=1, value=subtitle)
    s.font = FONT_SUBTITLE
    s.alignment = Alignment(horizontal="left", vertical="center", indent=1)

    ws.row_dimensions[1].height = 38
    ws.row_dimensions[2].height = 22
    ws.row_dimensions[3].height = 4


def style_header_cell(cell, text, align="left"):
    cell.value = text
    cell.font = FONT_TH
    cell.fill = FILL_NAVY_SOFT
    cell.border = BORDER_TH
    cell.alignment = Alignment(horizontal=align, vertical="center", wrap_text=True, indent=1 if align == "left" else 0)


def style_badge(cell, mapping, key):
    if key in mapping:
        cell.fill, cell.font = mapping[key]
    cell.alignment = Alignment(horizontal="center", vertical="center", wrap_text=True)


def set_print_setup(ws, title_rows=None):
    ws.page_setup.orientation = "landscape"
    ws.page_setup.paperSize = ws.PAPERSIZE_A4
    ws.page_setup.fitToWidth = 1
    ws.page_setup.fitToHeight = 0
    ws.sheet_properties.pageSetUpPr = PageSetupProperties(fitToPage=True)
    ws.print_options.horizontalCentered = True
    ws.page_margins.left = ws.page_margins.right = 0.4
    ws.page_margins.top = ws.page_margins.bottom = 0.5
    ws.oddFooter.center.text = "Page &P of &N"
    ws.oddFooter.left.text = "&A"
    if title_rows:
        ws.print_title_rows = title_rows


# ---------------------------------------------------------------------------
# RESOURCE SHEETS
# ---------------------------------------------------------------------------
def build_resource_sheet(wb, sheet_name, rows, is_master=False):
    ws = wb.create_sheet(title=sheet_name[:31])
    ws.sheet_view.showGridLines = False
    ws.sheet_properties.tabColor = NAVY if is_master else ACCENT

    keys = list(MASTER_COLS)
    if not is_master:
        keys.remove("Category")
    max_col = len(keys)

    pretty = sheet_name.replace("_", " ")
    title = "Master Inventory  |  All Flagged AWS Resources" if is_master else pretty
    total_monthly = sum(r["Est_Monthly_Savings_USD"] for r in rows)
    subtitle = (
        f"Product: {PRODUCT_NAME}   •   Environments: DEV & UAT, DEMO   •   "
        f"Flagged items: {len(rows):,}   •   Est. monthly savings: ${total_monthly:,.2f}"
    )
    add_banner(ws, title, subtitle, max_col)

    header_row = 4
    ws.row_dimensions[header_row].height = 34
    centered_hdrs = {"Product", "Environment", "Account_ID", "Region", "Priority_Bucket"}
    for ci, key in enumerate(keys, start=1):
        align = "right" if "USD" in key else "center" if key in centered_hdrs else "left"
        style_header_cell(ws.cell(row=header_row, column=ci), HEADER_LABELS[key], align)

    data_start = header_row + 1
    for idx, row in enumerate(rows):
        r = data_start + idx
        ws.row_dimensions[r].height = 22
        base_fill = FILL_WHITE if idx % 2 == 0 else FILL_ZEBRA

        for ci, key in enumerate(keys, start=1):
            cell = ws.cell(row=r, column=ci, value=row.get(key, ""))
            cell.font = FONT_DATA
            cell.fill = base_fill
            cell.border = BORDER_DATA
            cell.alignment = Alignment(horizontal="left", vertical="center", wrap_text=True, indent=1)

            if key in ("Est_Monthly_Savings_USD", "Est_Annual_Savings_USD"):
                cell.number_format = MONEY_FMT
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="right", vertical="center", indent=1)
            elif key in ("Product", "Account_ID", "Region"):
                cell.alignment = Alignment(horizontal="center", vertical="center")
                if key == "Product":
                    cell.font = FONT_BOLD
            elif key == "Environment":
                style_badge(cell, ENV_STYLE, row[key])
            elif key == "Priority_Bucket":
                style_badge(cell, PRIORITY_STYLE, row[key])
            elif key == "Resource_Name":
                cell.font = FONT_BOLD
            elif key == "Remarks / Comments":
                cell.fill = FILL_NOTES

    # Grand total
    total_row = data_start + len(rows)
    ws.row_dimensions[total_row].height = 26
    m_idx = keys.index("Est_Monthly_Savings_USD") + 1
    a_idx = keys.index("Est_Annual_Savings_USD") + 1
    for ci in range(1, max_col + 1):
        cell = ws.cell(row=total_row, column=ci)
        cell.fill = FILL_TOTAL
        cell.font = font(10, True, NAVY)
        cell.border = BORDER_TOTAL
        if ci == 1:
            cell.value = "GRAND TOTAL"
            cell.alignment = Alignment(horizontal="left", vertical="center", indent=1)
        elif ci in (m_idx, a_idx) and rows:
            let = get_column_letter(ci)
            cell.value = f"=SUBTOTAL(109,{let}{data_start}:{let}{total_row - 1})"  # respects filters
            cell.number_format = MONEY_FMT
            cell.alignment = Alignment(horizontal="right", vertical="center", indent=1)

    if rows:
        m_let = get_column_letter(m_idx)
        ws.conditional_formatting.add(
            f"{m_let}{data_start}:{m_let}{total_row - 1}",
            DataBarRule(start_type="num", start_value=0, end_type="max", color="8FB4E3", showValue=True),
        )

    for ci, key in enumerate(keys, start=1):
        ws.column_dimensions[get_column_letter(ci)].width = COL_WIDTH[key]

    ws.freeze_panes = ws.cell(row=data_start, column=4 if is_master else 3)
    ws.auto_filter.ref = f"A{header_row}:{get_column_letter(max_col)}{max(total_row - 1, header_row)}"
    set_print_setup(ws, title_rows="1:4")
    return ws


# ---------------------------------------------------------------------------
# EXECUTIVE SUMMARY
# ---------------------------------------------------------------------------
def build_executive_summary(wb, by_category, all_records):
    ws = wb.active
    ws.title = "Executive_Summary"
    ws.sheet_view.showGridLines = False
    ws.sheet_properties.tabColor = ACCENT

    max_col = 7
    add_banner(
        ws,
        "AWS Cost Optimization  |  Executive Summary",
        f"Product: {PRODUCT_NAME}   •   DEV & UAT (468681639671)   •   DEMO (611950011201)",
        max_col,
    )

    last = 4 + len(all_records)
    rng = lambda key: f"{MASTER_SHEET}!${MCOL[key]}$5:${MCOL[key]}${last}"
    env_r, cat_r, pri_r = rng("Environment"), rng("Category"), rng("Priority_Bucket")
    mon_r, ann_r = rng("Est_Monthly_Savings_USD"), rng("Est_Annual_Savings_USD")
    has = bool(all_records)

    # ---- KPI cards (rows 5-6) -------------------------------------------
    cards = [
        (1, 2, "FLAGGED RESOURCES", f"=COUNTA({rng('Product')})" if has else 0, INT_FMT),
        (3, 4, "EST. MONTHLY SAVINGS", f"=SUM({mon_r})" if has else 0, MONEY_FMT),
        (5, 6, "EST. ANNUAL SAVINGS", f"=SUM({ann_r})" if has else 0, MONEY_FMT),
        (7, 7, "SAFE TO DELETE (MONTHLY)",
         f'=SUMIF({pri_r},"Safe to Delete / Release",{mon_r})' if has else 0, MONEY_FMT),
    ]
    ws.row_dimensions[4].height = 10
    ws.row_dimensions[5].height = 22
    ws.row_dimensions[6].height = 40
    for c1, c2, label, formula, fmt in cards:
        for r in (5, 6):
            if c2 > c1:
                ws.merge_cells(start_row=r, start_column=c1, end_row=r, end_column=c2)
            for c in range(c1, c2 + 1):
                cell = ws.cell(row=r, column=c)
                cell.fill = FILL_KPI
                cell.border = Border(
                    left=Side(style="thick", color=ACCENT) if c == c1 else THIN,
                    right=THIN if c == c2 else None,
                    top=THIN if r == 5 else None,
                    bottom=THIN if r == 6 else None,
                )
        lbl = ws.cell(row=5, column=c1, value=label)
        lbl.font = FONT_KPI_LABEL
        lbl.alignment = Alignment(horizontal="left", vertical="bottom", indent=1)
        val = ws.cell(row=6, column=c1, value=formula)
        val.font = FONT_KPI_VALUE
        val.number_format = fmt
        val.alignment = Alignment(horizontal="left", vertical="center", indent=1)

    # ---- generic table writer -------------------------------------------
    def write_section(title_row, title, headers, body_rows, total_label, total_cols, fmts, badge=None):
        """body_rows: list of (values_list, badge_key). Returns total row number."""
        ws.row_dimensions[title_row - 1].height = 10
        t = ws.cell(row=title_row, column=1, value=title)
        t.font = FONT_SEC
        t.alignment = Alignment(vertical="center")
        for c in range(1, max_col + 1):
            ws.cell(row=title_row, column=c).border = Border(bottom=Side(style="medium", color=ACCENT))
        ws.row_dimensions[title_row].height = 26

        hdr = title_row + 1
        ws.row_dimensions[hdr].height = 28
        for ci, h in enumerate(headers, start=1):
            numeric = fmts.get(ci) is not None
            style_header_cell(ws.cell(row=hdr, column=ci), h, "right" if numeric else "left" if ci > 2 else "center")
        # first column always centered (Product)
        ws.cell(row=hdr, column=1).alignment = Alignment(horizontal="center", vertical="center")

        for i, (vals, bkey) in enumerate(body_rows):
            r = hdr + 1 + i
            ws.row_dimensions[r].height = 24
            base = FILL_WHITE if i % 2 == 0 else FILL_ZEBRA
            for ci, v in enumerate(vals, start=1):
                cell = ws.cell(row=r, column=ci, value=v)
                cell.font = FONT_DATA
                cell.fill = base
                cell.border = BORDER_DATA
                cell.alignment = Alignment(horizontal="left", vertical="center", indent=1)
                if ci == 1:
                    cell.font = FONT_BOLD
                    cell.alignment = Alignment(horizontal="center", vertical="center")
                elif fmts.get(ci):
                    cell.number_format = fmts[ci]
                    cell.alignment = Alignment(horizontal="right", vertical="center", indent=1)
                    if fmts[ci] == MONEY_FMT:
                        cell.font = FONT_BOLD
                elif ci == max_col:
                    cell.fill = FILL_NOTES
            if badge == "env":
                style_badge(ws.cell(row=r, column=2), ENV_STYLE, bkey)
            elif badge == "pri":
                style_badge(ws.cell(row=r, column=2), PRIORITY_STYLE, bkey)
                ws.cell(row=r, column=2).alignment = Alignment(horizontal="left", vertical="center", indent=1)
            elif badge == "bold":
                ws.cell(row=r, column=2).font = FONT_BOLD

        tot = hdr + 1 + len(body_rows)
        ws.row_dimensions[tot].height = 26
        first, lastr = hdr + 1, tot - 1
        for ci in range(1, max_col + 1):
            cell = ws.cell(row=tot, column=ci)
            cell.fill = FILL_TOTAL
            cell.font = font(10, True, NAVY)
            cell.border = BORDER_TOTAL
            if ci == 1:
                cell.value = total_label
                cell.alignment = Alignment(horizontal="center", vertical="center")
            elif ci in total_cols and body_rows:
                let = get_column_letter(ci)
                cell.value = f"=SUM({let}{first}:{let}{lastr})"
                cell.number_format = fmts[ci]
                cell.alignment = Alignment(horizontal="right", vertical="center", indent=1)
        return hdr, tot

    # ---- 1. by environment ----------------------------------------------
    envs = [("DEV & UAT", "468681639671"), ("DEMO", "611950011201")]
    body = [
        ([PRODUCT_NAME, env, acc,
          f'=COUNTIF({env_r},"{env}")' if has else 0,
          f'=SUMIF({env_r},"{env}",{mon_r})' if has else 0,
          f'=SUMIF({env_r},"{env}",{ann_r})' if has else 0, ""], env)
        for env, acc in envs
    ]
    _, tot1 = write_section(
        9, "1.  Savings by Environment",
        ["Product", "Environment", "Account ID", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "Remarks / Notes"],
        body, "TOTAL", (4, 5, 6), {4: INT_FMT, 5: MONEY_FMT, 6: MONEY_FMT}, badge="env",
    )
    for r in range(11, tot1):
        ws.cell(row=r, column=3).alignment = Alignment(horizontal="center", vertical="center")

    # ---- 2. by priority -------------------------------------------------
    sec2_title = tot1 + 3
    sec2_tot = sec2_title + 2 + len(PRIORITY_ORDER)
    body = []
    for i, pri in enumerate(PRIORITY_ORDER):
        r = sec2_title + 2 + i
        body.append((
            [PRODUCT_NAME, pri,
             f'=COUNTIF({pri_r},"{pri}")' if has else 0,
             f'=SUMIF({pri_r},"{pri}",{mon_r})' if has else 0,
             f'=SUMIF({pri_r},"{pri}",{ann_r})' if has else 0,
             f"=IF($D${sec2_tot}>0,D{r}/$D${sec2_tot},0)", ""], pri))
    _, tot2 = write_section(
        sec2_title, "2.  Savings by Action Priority",
        ["Product", "Priority", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "% of Total Savings", "Remarks / Notes"],
        body, "TOTAL", (3, 4, 5, 6), {3: INT_FMT, 4: MONEY_FMT, 5: MONEY_FMT, 6: PCT_FMT}, badge="pri",
    )

    # ---- 3. by service category -----------------------------------------
    ordered = list(CATEGORY_MAP.values())
    ordered += [c for c in sorted(by_category) if c not in ordered]
    active = [c for c in ordered if by_category.get(c)]
    sec3_title = tot2 + 3
    sec3_tot = sec3_title + 2 + len(active)
    body = []
    for i, cat in enumerate(active):
        r = sec3_title + 2 + i
        label = cat.replace("_", " ")
        body.append((
            [PRODUCT_NAME, label,
             f'=COUNTIF({cat_r},"{label}")',
             f'=SUMIF({cat_r},"{label}",{mon_r})',
             f'=SUMIF({cat_r},"{label}",{ann_r})',
             f"=IF($D${sec3_tot}>0,D{r}/$D${sec3_tot},0)", ""], label))
    hdr3, tot3 = write_section(
        sec3_title, "3.  Savings by AWS Service Category",
        ["Product", "Service Category", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "% of Total Savings", "Remarks / Notes"],
        body, "GRAND TOTAL", (3, 4, 5, 6), {3: INT_FMT, 4: MONEY_FMT, 5: MONEY_FMT, 6: PCT_FMT}, badge="bold",
    )
    if active:
        ws.conditional_formatting.add(
            f"D{hdr3 + 1}:D{tot3 - 1}",
            DataBarRule(start_type="num", start_value=0, end_type="max", color="8FB4E3", showValue=True),
        )

    for let, w in {"A": 16, "B": 38, "C": 20, "D": 24, "E": 24, "F": 22, "G": 36}.items():
        ws.column_dimensions[let].width = w

    ws.freeze_panes = "A4"
    set_print_setup(ws)


# ---------------------------------------------------------------------------
# CSV + MAIN
# ---------------------------------------------------------------------------
def export_master_csv(all_records):
    with open(CSV_PATH, "w", newline="", encoding="utf-8-sig") as f:
        writer = csv.DictWriter(f, fieldnames=MASTER_COLS)
        writer.writeheader()
        writer.writerows(all_records)


def main():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    by_category, all_records = load_all_data()

    wb = openpyxl.Workbook()
    build_executive_summary(wb, by_category, all_records)
    build_resource_sheet(wb, MASTER_SHEET, all_records, is_master=True)

    ordered = list(CATEGORY_MAP.values())
    ordered += [c for c in sorted(by_category) if c not in ordered]
    for cat in ordered:
        rows = by_category.get(cat, [])
        if rows:
            build_resource_sheet(wb, cat, rows)

    wb.save(EXCEL_PATH)
    export_master_csv(all_records)
    print(f"Successfully generated Excel report: {EXCEL_PATH}")
    print(f"Successfully generated CSV report:   {CSV_PATH}")


if __name__ == "__main__":
    main()
