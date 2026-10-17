# Reliable Command-Line Utility: Expense Tracker

A beginner-friendly menu-driven C++ terminal application designed with robust input validation, vector storage, and clear formatted output.

## Features
- **Add Expense**: Record description, positive numerical amount, and category.
- **List All Expenses**: Display records in a clean tabular view.
- **Category Totals**: Filter and sum up expenses belonging to a specific category.
- **Overall Total**: Compute aggregate spending.
- **Robust Error Handling**: Prevents infinite loops and application crashes on incorrect data types or invalid menu choices.

## How to Compile and Run

1. Open your terminal in the directory containing `main.cpp`.
2. Compile using a C++ compiler (e.g., GCC/Clang):
   ```bash
   g++ -O3 main.cpp -o expense_tracker
