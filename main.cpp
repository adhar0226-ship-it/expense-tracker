#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

struct Expense {
    std::string description;
    double amount;
    std::string category;
};

void showMenu() {
    std::cout << "\n=== MENU-DRIVEN EXPENSE TRACKER ===\n";
    std::cout << "1. Add Expense\n";
    std::cout << "2. List All Expenses\n";
    std::cout << "3. View Category Total\n";
    std::cout << "4. View Overall Total\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

double getValidAmount() {
    double amount;
    while (true) {
        std::cout << "Enter amount ($): ";
        if (std::cin >> amount && amount > 0) {
            return amount;
        }
        std::cout << "Invalid input. Please enter a positive number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::vector<Expense> expenses;
    int choice;

    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Expense exp;
                std::cout << "Enter description: ";
                std::getline(std::cin, exp.description);
                exp.amount = getValidAmount();
                std::cout << "Enter category (e.g., Food, Transport, Utilities): ";
                std::getline(std::cin, exp.category);
                
                expenses.push_back(exp);
                std::cout << "Expense added successfully!\n";
                break;
            }
            case 2: {
                if (expenses.empty()) {
                    std::cout << "No expenses recorded yet.\n";
                    break;
                }
                std::cout << "\n--- All Expenses ---\n";
                std::cout << std::left << std::setw(20) << "Description" 
                          << std::right << std::setw(10) << "Amount" 
                          << std::left << "  Category" << "\n";
                std::cout << "----------------------------------------\n";
                for (const auto& e : expenses) {
                    std::cout << std::left << std::setw(20) << e.description 
                              << "$" << std::right << std::setw(9) << std::fixed << std::setprecision(2) << e.amount 
                              << "  " << std::left << e.category << "\n";
                }
                break;
            }
            case 3: {
                if (expenses.empty()) {
                    std::cout << "No expenses recorded yet.\n";
                    break;
                }
                std::string targetCategory;
                std::cout << "Enter category to total: ";
                std::getline(std::cin, targetCategory);

                double catTotal = 0.0;
                for (const auto& e : expenses) {
                    if (e.category == targetCategory) {
                        catTotal += e.amount;
                    }
                }
                std::cout << "Total for category '" << targetCategory << "': $" << std::fixed << std::setprecision(2) << catTotal << "\n";
                break;
            }
            case 4: {
                double overallTotal = 0.0;
                for (const auto& e : expenses) {
                    overallTotal += e.amount;
                }
                std::cout << "Overall Total Expenses: $" << std::fixed << std::setprecision(2) << overallTotal << "\n";
                break;
            }
            case 5:
                std::cout << "Exiting Expense Tracker. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please select an option from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
