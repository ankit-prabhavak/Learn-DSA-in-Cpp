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
}

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
