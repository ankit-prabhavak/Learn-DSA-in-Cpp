import os
import csv
import json
import glob
from collections import defaultdict
import openpyxl
from openpyxl.styles import Font, PatternFill, Alignment, Border, Side
from openpyxl.utils import get_column_letter

ACCOUNT_ENVIRONMENTS = {
    "468681639671": "DEV & UAT",
    "611950011201": "DEMO",
}

ENV_SORT_ORDER = {
    "DEV & UAT": 1,
    "DEMO": 2,
}import os
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

FONT_FAMILY = "Aptos Narrow"

# Typography
FONT_TITLE = Font(name=FONT_FAMILY, size=15, bold=True, color="FFFFFF")
FONT_SUBTITLE = Font(name=FONT_FAMILY, size=10, italic=True, color="E0F2FE")
FONT_SEC_HDR = Font(name=FONT_FAMILY, size=11, bold=True, color="0F172A")
FONT_TBL_HDR = Font(name=FONT_FAMILY, size=10, bold=True, color="FFFFFF")
FONT_DATA = Font(name=FONT_FAMILY, size=10, bold=False, color="0F172A")
FONT_BOLD = Font(name=FONT_FAMILY, size=10, bold=True, color="0F172A")
FONT_TOTAL = Font(name=FONT_FAMILY, size=10, bold=True, color="0F172A")

# Bright, Crisp, High-Visibility Palette
FILL_BANNER = PatternFill("solid", fgColor="0284C7")      # Bright Cerulean Blue
FILL_SUBBANNER = PatternFill("solid", fgColor="0369A1")   # Vivid Ocean Blue
FILL_HEADER = PatternFill("solid", fgColor="2563EB")      # Royal Bright Blue
FILL_ZEBRA = PatternFill("solid", fgColor="F8FAFC")       # Crisp Cool Tint
FILL_WHITE = PatternFill("solid", fgColor="FFFFFF")       # Pure White
FILL_TOTAL = PatternFill("solid", fgColor="E0F2FE")       # Bright Sky Blue Tint
FILL_REMARKS = PatternFill("solid", fgColor="FFFBEB")     # Soft Warm Cream for editable notes

# Environment Badges
FILL_ENV_DEV = PatternFill("solid", fgColor="DBEAFE")     # Bright Sky Blue
FONT_ENV_DEV = Font(name=FONT_FAMILY, size=10, bold=True, color="1D4ED8")

FILL_ENV_DEMO = PatternFill("solid", fgColor="FEF3C7")    # Bright Amber Cream
FONT_ENV_DEMO = Font(name=FONT_FAMILY, size=10, bold=True, color="B45309")

# Action / Priority Badges (Bright & Readable)
FILL_SAFE_DELETE = PatternFill("solid", fgColor="BBF7D0") # Crisp Mint Green
FONT_SAFE_DELETE = Font(name=FONT_FAMILY, size=10, bold=True, color="15803D")

FILL_VERIFY_DEV = PatternFill("solid", fgColor="FED7AA")  # Bright Peach / Amber
FONT_VERIFY_DEV = Font(name=FONT_FAMILY, size=10, bold=True, color="C2410C")

FILL_CONFIG_OPT = PatternFill("solid", fgColor="BAE6FD")  # Vivid Light Cyan
FONT_CONFIG_OPT = Font(name=FONT_FAMILY, size=10, bold=True, color="0369A1")

FILL_HYGIENE = PatternFill("solid", fgColor="E9D5FF")     # Bright Lavender
FONT_HYGIENE = Font(name=FONT_FAMILY, size=10, bold=True, color="7E22CE")

# Sharp Single-Line Borders (No Double Borders)
THIN_SLATE = Side(style="thin", color="CBD5E1")
MED_BLUE = Side(style="medium", color="1D4ED8")

BORDER_DATA = Border(left=THIN_SLATE, right=THIN_SLATE, top=THIN_SLATE, bottom=THIN_SLATE)
BORDER_HEADER = Border(left=THIN_SLATE, right=THIN_SLATE, top=MED_BLUE, bottom=MED_BLUE)
BORDER_TOTAL = Border(left=THIN_SLATE, right=THIN_SLATE, top=MED_BLUE, bottom=MED_BLUE)


def get_category_from_filename(filename):
    base = os.path.basename(filename)
    for prefix, cat_name in CATEGORY_MAP.items():
        if base.startswith(prefix):
            return cat_name
    return "Other_Resources"


def classify_priority(action_text, savings):
    act = action_text.lower()
    if "keep" in act or "already scheduled" in act:
        return "Active / No Action Needed"
    if "verify" in act or "review" in act or "deregister" in act:
        return "Verify with Dev / Owner First"
    if savings == 0 or "iam" in act or "cleanup" in act or "dangling" in act:
        return "Security & Hygiene ($0 Direct)"
    if "retention" in act or "lifecycle" in act or "schedule" in act or "right-size" in act:
        return "Configuration / Policy Optimization"
    return "Safe to Delete / Release"


def style_action_cell(cell, action_text, savings):
    act = action_text.lower()
    if "keep" in act or "already scheduled" in act:
        cell.fill = FILL_ZEBRA
        cell.font = FONT_DATA
    elif "verify" in act or "review" in act or "deregister" in act:
        cell.fill = FILL_VERIFY_DEV
        cell.font = FONT_VERIFY_DEV
    elif savings == 0 or "iam" in act or "cleanup" in act or "dangling" in act:
        cell.fill = FILL_HYGIENE
        cell.font = FONT_HYGIENE
    elif "retention" in act or "lifecycle" in act or "schedule" in act or "right-size" in act:
        cell.fill = FILL_CONFIG_OPT
        cell.font = FONT_CONFIG_OPT
    else:
        cell.fill = FILL_SAFE_DELETE
        cell.font = FONT_SAFE_DELETE


def style_environment_cell(cell, env_val):
    if env_val == "DEV & UAT":
        cell.fill = FILL_ENV_DEV
        cell.font = FONT_ENV_DEV
    elif env_val == "DEMO":
        cell.fill = FILL_ENV_DEMO
        cell.font = FONT_ENV_DEMO
    else:
        cell.font = FONT_BOLD


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
            annual = round(monthly * 12, 2)
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
                "Est_Annual_Savings_USD": annual,
                "Priority_Bucket": classify_priority(action, monthly),
                "Recommended_Action": action,
                "Remarks / Comments": "",
            }
            by_category[category].append(row)
            all_records.append(row)

    for cat in by_category:
        by_category[cat] = sort_records(by_category[cat])
    all_records = sort_records(all_records)

    return by_category, all_records


def add_banner(ws, title, subtitle, max_col):
    ws.merge_cells(start_row=1, start_column=1, end_row=1, end_column=max_col)
    ws.merge_cells(start_row=2, start_column=1, end_row=2, end_column=max_col)

    for r_idx in (1, 2):
        for c_idx in range(1, max_col + 1):
            cell = ws.cell(row=r_idx, column=c_idx)
            cell.fill = FILL_BANNER if r_idx == 1 else FILL_SUBBANNER
            cell.border = BORDER_HEADER

    c1 = ws.cell(row=1, column=1, value=title)
    c1.font = FONT_TITLE
    c1.alignment = Alignment(horizontal="left", vertical="center", indent=1)
    ws.row_dimensions[1].height = 32

    c2 = ws.cell(row=2, column=1, value=subtitle)
    c2.font = FONT_SUBTITLE
    c2.alignment = Alignment(horizontal="left", vertical="center", indent=1)
    ws.row_dimensions[2].height = 22
    ws.row_dimensions[3].height = 10


def auto_fit_columns(ws, start_row=4):
    for col in ws.columns:
        col_idx = col[0].column
        col_letter = get_column_letter(col_idx)
        header_val = str(ws.cell(row=start_row, column=col_idx).value or "")
        max_len = len(header_val)

        for cell in col[start_row:]:
            val = str(cell.value or "")
            if val.startswith("="):
                val = "$999,999.99"
            max_len = max(max_len, min(len(val), 60))

        if "Details" in header_val or "ID" in header_val:
            ws.column_dimensions[col_letter].width = max(36, min(max_len + 5, 58))
        elif "Remarks" in header_val:
            ws.column_dimensions[col_letter].width = 34
        elif "Action" in header_val or "Name" in header_val:
            ws.column_dimensions[col_letter].width = max(26, min(max_len + 5, 44))
        elif "Environment" in header_val or "Product" in header_val:
            ws.column_dimensions[col_letter].width = max(16, max_len + 5)
        else:
            ws.column_dimensions[col_letter].width = max(15, max_len + 5)


def build_resource_sheet(wb, sheet_name, rows, include_category_col=False):
    ws = wb.create_sheet(title=sheet_name[:31])
    ws.views.sheetView[0].showGridLines = True

    headers = [
        "Product",
        "Environment",
        "Account_ID",
        "Region",
        "Resource_Type",
        "Resource_Name",
        "Resource_ID",
        "Status_Details",
        "Est_Monthly_Savings_USD",
        "Est_Annual_Savings_USD",
        "Priority_Bucket",
        "Recommended_Action",
        "Remarks / Comments",
    ]
    if include_category_col:
        headers.insert(1, "Category")

    max_col = len(headers)
    display_title = (
        "ALL AWS RESOURCES — MASTER INVENTORY (DEV & UAT + DEMO)"
        if include_category_col
        else f"AWS RESOURCE AUDIT — {sheet_name.replace('_', ' ').upper()}"
    )
    add_banner(
        ws,
        display_title,
        f"Product: {PRODUCT_NAME} | Ordered by Environment (DEV & UAT first, DEMO below) | Total Flagged Items: {len(rows)}",
        max_col,
    )

    header_row = 4
    ws.row_dimensions[header_row].height = 28

    for col_idx, text in enumerate(headers, start=1):
        cell = ws.cell(row=header_row, column=col_idx, value=text)
        cell.font = FONT_TBL_HDR
        cell.fill = FILL_HEADER
        cell.border = BORDER_HEADER
        cell.alignment = Alignment(
            horizontal="center" if "USD" in text or text in ("Product", "Environment", "Account_ID", "Region") else "left",
            vertical="center",
            wrap_text=True,
        )

    data_start = header_row + 1
    for idx, row_data in enumerate(rows):
        r = data_start + idx
        ws.row_dimensions[r].height = 24
        row_fill = FILL_WHITE if idx % 2 == 0 else FILL_ZEBRA

        for col_idx, key in enumerate(headers, start=1):
            val = row_data.get(key, "")
            cell = ws.cell(row=r, column=col_idx, value=val)
            cell.font = FONT_DATA
            cell.fill = row_fill
            cell.border = BORDER_DATA

            if key in ("Est_Monthly_Savings_USD", "Est_Annual_Savings_USD"):
                cell.number_format = "$#,##0.00"
                cell.alignment = Alignment(horizontal="right", vertical="center")
                cell.font = FONT_BOLD
            elif key in ("Product", "Account_ID", "Region"):
                cell.alignment = Alignment(horizontal="center", vertical="center")
                if key == "Product":
                    cell.font = FONT_BOLD
            elif key == "Environment":
                cell.alignment = Alignment(horizontal="center", vertical="center")
                style_environment_cell(cell, val)
            elif key == "Recommended_Action":
                cell.alignment = Alignment(horizontal="left", vertical="center", wrap_text=True)
                style_action_cell(cell, val, row_data["Est_Monthly_Savings_USD"])
            elif key == "Remarks / Comments":
                cell.fill = FILL_REMARKS
                cell.alignment = Alignment(horizontal="left", vertical="center", wrap_text=True)
            else:
                cell.alignment = Alignment(horizontal="left", vertical="center", wrap_text=True)

    # Grand Total Row
    total_row = data_start + len(rows)
    ws.row_dimensions[total_row].height = 26
    monthly_col_idx = headers.index("Est_Monthly_Savings_USD") + 1
    annual_col_idx = headers.index("Est_Annual_Savings_USD") + 1

    for col_idx in range(1, max_col + 1):
        cell = ws.cell(row=total_row, column=col_idx)
        cell.fill = FILL_TOTAL
        cell.font = FONT_TOTAL
        cell.border = BORDER_TOTAL

        if col_idx == 1:
            cell.value = "GRAND TOTAL"
            cell.alignment = Alignment(horizontal="left", vertical="center", indent=1)
        elif col_idx == monthly_col_idx and rows:
            col_let = get_column_letter(col_idx)
            cell.value = f"=SUM({col_let}{data_start}:{col_let}{total_row - 1})"
            cell.number_format = "$#,##0.00"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif col_idx == annual_col_idx and rows:
            col_let = get_column_letter(col_idx)
            cell.value = f"=SUM({col_let}{data_start}:{col_let}{total_row - 1})"
            cell.number_format = "$#,##0.00"
            cell.alignment = Alignment(horizontal="right", vertical="center")

    ws.freeze_panes = f"A{data_start}"
    ws.auto_filter.ref = f"A{header_row}:{get_column_letter(max_col)}{total_row - 1}"
    auto_fit_columns(ws, start_row=header_row)


def build_executive_summary(wb, by_category, all_records):
    ws = wb.active
    ws.title = "Executive_Summary"
    ws.views.sheetView[0].showGridLines = True

    max_col = 7
    add_banner(
        ws,
        "AWS COST OPTIMIZATION — EXECUTIVE SUMMARY",
        f"Product: {PRODUCT_NAME} | Environments: DEV & UAT (468681639671) & DEMO (611950011201)",
        max_col,
    )

    master_last_row = 4 + len(all_records)
    env_range = f"All_Resources_Master!$C$5:$C${master_last_row}"
    cat_range = f"All_Resources_Master!$B$5:$B${master_last_row}"
    pri_range = f"All_Resources_Master!$M$5:$M${master_last_row}"
    mon_range = f"All_Resources_Master!$J$5:$J${master_last_row}"
    ann_range = f"All_Resources_Master!$K$5:$K${master_last_row}"

    def write_table_header(row_num, section_title, col_headers):
        ws.cell(row=row_num - 1, column=1, value=section_title).font = FONT_SEC_HDR
        ws.row_dimensions[row_num - 1].height = 24
        ws.row_dimensions[row_num].height = 26
        for idx, h in enumerate(col_headers, start=1):
            c = ws.cell(row=row_num, column=idx, value=h)
            c.font = FONT_TBL_HDR
            c.fill = FILL_HEADER
            c.border = BORDER_HEADER
            c.alignment = Alignment(
                horizontal="right" if "Savings" in h or "Count" in h or "Share" in h else "center" if idx <= 2 else "left",
                vertical="center",
            )

    # Section 1: Breakdown by Environment
    sec1_hdr = 5
    write_table_header(
        sec1_hdr,
        "1. SAVINGS BREAKDOWN BY ENVIRONMENT",
        ["Product", "Environment", "Account_ID", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "Remarks / Notes"],
    )

    envs = [
        ("DEV & UAT", "468681639671"),
        ("DEMO", "611950011201"),
    ]
    for i, (env_name, acc_id) in enumerate(envs):
        r = sec1_hdr + 1 + i
        ws.row_dimensions[r].height = 24
        fill = FILL_WHITE if i % 2 == 0 else FILL_ZEBRA

        vals = [
            PRODUCT_NAME,
            env_name,
            acc_id,
            f'=COUNTIF({env_range}, "{env_name}")' if all_records else 0,
            f'=SUMIF({env_range}, "{env_name}", {mon_range})' if all_records else 0,
            f'=SUMIF({env_range}, "{env_name}", {ann_range})' if all_records else 0,
            "",
        ]
        for c_idx, v in enumerate(vals, start=1):
            cell = ws.cell(row=r, column=c_idx, value=v)
            cell.font = FONT_DATA
            cell.fill = fill
            cell.border = BORDER_DATA
            if c_idx == 1:
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="center", vertical="center")
            elif c_idx == 2:
                cell.alignment = Alignment(horizontal="center", vertical="center")
                style_environment_cell(cell, env_name)
            elif c_idx == 3:
                cell.alignment = Alignment(horizontal="center", vertical="center")
            elif c_idx == 4:
                cell.number_format = "#,##0"
                cell.alignment = Alignment(horizontal="right", vertical="center")
            elif c_idx in (5, 6):
                cell.number_format = "$#,##0.00"
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="right", vertical="center")
            else:
                cell.fill = FILL_REMARKS

    sec1_tot = sec1_hdr + 1 + len(envs)
    ws.row_dimensions[sec1_tot].height = 25
    for c_idx in range(1, max_col + 1):
        cell = ws.cell(row=sec1_tot, column=c_idx)
        cell.fill = FILL_TOTAL
        cell.font = FONT_TOTAL
        cell.border = BORDER_TOTAL
        if c_idx == 1:
            cell.value = "TOTAL"
            cell.alignment = Alignment(horizontal="center", vertical="center")
        elif c_idx == 4:
            cell.value = f"=SUM(D{sec1_hdr+1}:D{sec1_tot-1})"
            cell.number_format = "#,##0"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif c_idx in (5, 6):
            let = get_column_letter(c_idx)
            cell.value = f"=SUM({let}{sec1_hdr+1}:{let}{sec1_tot-1})"
            cell.number_format = "$#,##0.00"
            cell.alignment = Alignment(horizontal="right", vertical="center")

    # Section 2: Breakdown by Action Priority
    sec2_hdr = sec1_tot + 3
    write_table_header(
        sec2_hdr,
        "2. SAVINGS BREAKDOWN BY ACTION PRIORITY BUCKET",
        ["Product", "Priority Bucket", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "% of Total Savings", "Remarks / Notes"],
    )

    priorities = [
        "Safe to Delete / Release",
        "Configuration / Policy Optimization",
        "Verify with Dev / Owner First",
        "Security & Hygiene ($0 Direct)",
        "Active / No Action Needed",
    ]
    sec2_tot = sec2_hdr + 1 + len(priorities)

    for i, pri in enumerate(priorities):
        r = sec2_hdr + 1 + i
        ws.row_dimensions[r].height = 24
        fill = FILL_WHITE if i % 2 == 0 else FILL_ZEBRA

        vals = [
            PRODUCT_NAME,
            pri,
            f'=COUNTIF({pri_range}, "{pri}")' if all_records else 0,
            f'=SUMIF({pri_range}, "{pri}", {mon_range})' if all_records else 0,
            f'=SUMIF({pri_range}, "{pri}", {ann_range})' if all_records else 0,
            f"=IF($D${sec2_tot}>0, D{r}/$D${sec2_tot}, 0)",
            "",
        ]
        for c_idx, v in enumerate(vals, start=1):
            cell = ws.cell(row=r, column=c_idx, value=v)
            cell.font = FONT_DATA
            cell.fill = fill
            cell.border = BORDER_DATA
            if c_idx == 1:
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="center", vertical="center")
            elif c_idx == 2:
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="left", vertical="center")
            elif c_idx == 3:
                cell.number_format = "#,##0"
                cell.alignment = Alignment(horizontal="right", vertical="center")
            elif c_idx in (4, 5):
                cell.number_format = "$#,##0.00"
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="right", vertical="center")
            elif c_idx == 6:
                cell.number_format = "0.0%"
                cell.alignment = Alignment(horizontal="right", vertical="center")
            else:
                cell.fill = FILL_REMARKS

    ws.row_dimensions[sec2_tot].height = 25
    for c_idx in range(1, max_col + 1):
        cell = ws.cell(row=sec2_tot, column=c_idx)
        cell.fill = FILL_TOTAL
        cell.font = FONT_TOTAL
        cell.border = BORDER_TOTAL
        if c_idx == 1:
            cell.value = "TOTAL"
            cell.alignment = Alignment(horizontal="center", vertical="center")
        elif c_idx == 3:
            cell.value = f"=SUM(C{sec2_hdr+1}:C{sec2_tot-1})"
            cell.number_format = "#,##0"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif c_idx in (4, 5):
            let = get_column_letter(c_idx)
            cell.value = f"=SUM({let}{sec2_hdr+1}:{let}{sec2_tot-1})"
            cell.number_format = "$#,##0.00"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif c_idx == 6:
            cell.value = f"=SUM(F{sec2_hdr+1}:F{sec2_tot-1})"
            cell.number_format = "0.0%"
            cell.alignment = Alignment(horizontal="right", vertical="center")

    # Section 3: Breakdown by AWS Service Category
    sec3_hdr = sec2_tot + 3
    write_table_header(
        sec3_hdr,
        "3. SAVINGS BREAKDOWN BY AWS SERVICE CATEGORY",
        ["Product", "Service Category", "Flagged Resources", "Est. Monthly Savings", "Est. Annual Savings", "% of Total Savings", "Remarks / Notes"],
    )

    ordered_cats = list(CATEGORY_MAP.values())
    for extra_cat in sorted(by_category.keys()):
        if extra_cat not in ordered_cats:
            ordered_cats.append(extra_cat)

    active_cats = [c for c in ordered_cats if by_category.get(c)]
    sec3_tot = sec3_hdr + 1 + len(active_cats)

    for i, cat_key in enumerate(active_cats):
        r = sec3_hdr + 1 + i
        ws.row_dimensions[r].height = 24
        fill = FILL_WHITE if i % 2 == 0 else FILL_ZEBRA
        cat_label = cat_key.replace("_", " ")

        vals = [
            PRODUCT_NAME,
            cat_label,
            f'=COUNTIF({cat_range}, "{cat_label}")',
            f'=SUMIF({cat_range}, "{cat_label}", {mon_range})',
            f'=SUMIF({cat_range}, "{cat_label}", {ann_range})',
            f"=IF($D${sec3_tot}>0, D{r}/$D${sec3_tot}, 0)",
            "",
        ]
        for c_idx, v in enumerate(vals, start=1):
            cell = ws.cell(row=r, column=c_idx, value=v)
            cell.font = FONT_DATA
            cell.fill = fill
            cell.border = BORDER_DATA
            if c_idx == 1:
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="center", vertical="center")
            elif c_idx == 2:
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="left", vertical="center")
            elif c_idx == 3:
                cell.number_format = "#,##0"
                cell.alignment = Alignment(horizontal="right", vertical="center")
            elif c_idx in (4, 5):
                cell.number_format = "$#,##0.00"
                cell.font = FONT_BOLD
                cell.alignment = Alignment(horizontal="right", vertical="center")
            elif c_idx == 6:
                cell.number_format = "0.0%"
                cell.alignment = Alignment(horizontal="right", vertical="center")
            else:
                cell.fill = FILL_REMARKS

    ws.row_dimensions[sec3_tot].height = 25
    for c_idx in range(1, max_col + 1):
        cell = ws.cell(row=sec3_tot, column=c_idx)
        cell.fill = FILL_TOTAL
        cell.font = FONT_TOTAL
        cell.border = BORDER_TOTAL
        if c_idx == 1:
            cell.value = "GRAND TOTAL"
            cell.alignment = Alignment(horizontal="center", vertical="center")
        elif c_idx == 3:
            cell.value = f"=SUM(C{sec3_hdr+1}:C{sec3_tot-1})"
            cell.number_format = "#,##0"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif c_idx in (4, 5):
            let = get_column_letter(c_idx)
            cell.value = f"=SUM({let}{sec3_hdr+1}:{let}{sec3_tot-1})"
            cell.number_format = "$#,##0.00"
            cell.alignment = Alignment(horizontal="right", vertical="center")
        elif c_idx == 6:
            cell.value = f"=SUM(F{sec3_hdr+1}:F{sec3_tot-1})"
            cell.number_format = "0.0%"
            cell.alignment = Alignment(horizontal="right", vertical="center")

    col_widths = {
        "A": 16,
        "B": 34,
        "C": 20,
        "D": 22,
        "E": 22,
        "F": 20,
        "G": 34,
    }
    for col_let, width in col_widths.items():
        ws.column_dimensions[col_let].width = width


def export_master_csv(all_records):
    fieldnames = [
        "Product",
        "Category",
        "Environment",
        "Account_ID",
        "Region",
        "Resource_Type",
        "Resource_Name",
        "Resource_ID",
        "Status_Details",
        "Est_Monthly_Savings_USD",
        "Est_Annual_Savings_USD",
        "Priority_Bucket",
        "Recommended_Action",
        "Remarks / Comments",
    ]
    with open(CSV_PATH, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(all_records)


def main():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    by_category, all_records = load_all_data()

    wb = openpyxl.Workbook()
    build_executive_summary(wb, by_category, all_records)
    build_resource_sheet(wb, "All_Resources_Master", all_records, include_category_col=True)

    ordered_cats = list(CATEGORY_MAP.values())
    for extra_cat in sorted(by_category.keys()):
        if extra_cat not in ordered_cats:
            ordered_cats.append(extra_cat)

    for cat_key in ordered_cats:
        rows = by_category.get(cat_key, [])
        if rows:
            build_resource_sheet(wb, cat_key, rows, include_category_col=False)

    wb.save(EXCEL_PATH)
    export_master_csv(all_records)
    print(f"Successfully generated Excel report: {EXCEL_PATH}")
    print(f"Successfully generated CSV report:   {CSV_PATH}")


if __name__ == "__main__":
    main()
