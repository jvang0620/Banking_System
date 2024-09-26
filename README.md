# C++ Banking System

This project is a **Banking System** built using C++ that demonstrates several key programming concepts, including Object-Oriented Programming (OOP), inheritance, polymorphism, and Standard Template Library (STL) usage. The program allows users to create different types of bank accounts, manage deposits and withdrawals, and view account details through a menu-driven interface.

## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Getting Started](#getting-started)
4. [How to Use](#how-to-use)
5. [Class Structure](#class-structure)
6. [Future Enhancements](#future-enhancements)
7. [License](#license)

## Overview

This C++ application simulates a simple banking system that provides functionality for creating different types of bank accounts, performing financial transactions, and applying bank-specific rules like interest calculation and overdraft handling. The project showcases C++ features such as:

- Object-Oriented Programming (OOP) principles including classes, inheritance, and polymorphism.
- Function Overloading and overriding.
- Exception handling with `try`, `catch`, and `throw`.
- Use of STL containers like `std::map` for managing bank accounts.

## Features

1. **Account Management**: Create `SavingsAccount` or `CheckingAccount` with unique account numbers.
2. **Deposit and Withdrawal**: Perform deposit and withdrawal operations with validation.
3. **Interest Application**: Apply interest to `SavingsAccount` balances.
4. **Overdraft Handling**: `CheckingAccount` supports overdraft protection with fees.
5. **Exception Handling**: Safely handle scenarios like insufficient funds during withdrawal.
6. **Polymorphism**: Use polymorphism to handle account types dynamically.
7. **Menu-Based Interface**: Easy-to-use menu for user interaction and managing accounts.

## Getting Started

### Prerequisites

- **C++ Compiler**: Any modern C++ compiler like `g++` (GCC), `clang++`, or Microsoft Visual Studio is recommended.
- **Development Environment**: An IDE like Visual Studio, CLion, Code::Blocks, or a simple text editor like `VS Code` or `Sublime Text`.

### Installation

1. Clone the repository or download the source code files.
   ```bash
   git clone https://github.com/yourusername/banking-system-cpp.git
   ```
2. Navigate to the project directory.

   ```bash
   cd banking-system-cpp
   ```

3. Compile the program using a C++ compiler. For example, using `g++`:

   ```bash
   g++ -std=c++17 -o banking_system banking_system.cpp
   ```

4. Run the compiled executable:
   ```bash
   ./banking_system
   ```

## How to Use

After launching the application, the following menu options will be displayed:

```bash
=== Banking System Menu ===

Create Savings Account
Create Checking Account
Deposit Money
Withdraw Money
View Account Info
Apply Interest (Savings Accounts Only)
Exit Choose an option:
```

1. **Create Savings Account**: Input the owner's name, initial balance, and interest rate to create a savings account.
2. **Create Checking Account**: Input the owner's name, initial balance, and overdraft fee to create a checking account.
3. **Deposit Money**: Choose an account by number and specify the deposit amount.
4. **Withdraw Money**: Choose an account by number and specify the withdrawal amount. Overdrafts will apply if the account has insufficient funds.
5. **View Account Info**: Enter the account number to view details like owner, balance, and account type.
6. **Apply Interest**: Apply the interest rate to savings accounts to see the balance grow.
7. **Exit**: Quit the application.

## Class Structure

The project consists of the following classes:

### `BankAccount`

- Base class representing a generic bank account.
- Holds common attributes like `owner`, `balance`, and `accountNumber`.
- Virtual functions like `deposit()`, `withdraw()`, and `displayAccountInfo()` to be overridden by derived classes.

### `SavingsAccount` (Inherits from `BankAccount`)

- Adds interest rate functionality.
- Function to apply interest to the balance.
- Overrides `displayAccountInfo()` to include interest rate information.

### `CheckingAccount` (Inherits from `BankAccount`)

- Adds overdraft handling with an overdraft fee.
- Overrides `withdraw()` to handle overdraft cases.

### `main()`

- Manages the user interface, processes user input, and manages accounts using an `std::map` to store accounts by account number.

## Future Enhancements

- **Transaction History**: Implement a transaction log for each account.
- **File Storage**: Save and load account information from files.
- **Additional Account Types**: Add support for other account types like `BusinessAccount` or `StudentAccount`.
- **User Authentication**: Implement user authentication for enhanced security.

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.
# Banking_System
