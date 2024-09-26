#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

// Namespace for the Banking System to organize related classes
namespace Banking
{
    // Base class representing a bank account
    class BankAccount
    {
    private:
        string owner;                    // Name of the account owner
        double balance;                  // Balance of the account
        static int accountNumberCounter; // Static counter to generate unique account numbers
        int accountNumber;               // Unique account number for each account

    public:
        // Constructor to initialize the account with the owner's name and initial balance
        BankAccount(string ownerName, double initialBalance)
            : owner(ownerName), balance(initialBalance)
        {
            // Increment the static counter and assign a unique account number to the new account
            accountNumber = ++accountNumberCounter;
            cout << "Account created for " << owner << " with account number: " << accountNumber << endl;
        }

        // Destructor to display a message when the account is closed
        virtual ~BankAccount()
        {
            cout << "Account for " << owner << " with account number: " << accountNumber << " closed." << endl;
        }

        // Getters for accessing private data members
        int getAccountNumber() const { return accountNumber; }
        string getOwner() const { return owner; }
        double getBalance() const { return balance; }

        // Function to deposit money into the account
        virtual void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount; // Increase balance by the deposit amount
                cout << "Deposited: $" << amount << " into account number: " << accountNumber << endl;
            }
        }

        // Withdraw money from the account with exception handling for insufficient funds
        virtual void withdraw(double amount)
        {
            if (amount > balance)
            {
                throw runtime_error("Insufficient funds!"); // Throw an exception if balance is not enough
            }
            balance -= amount; // Reduce the balance by the withdrawn amount
            cout << "Withdrew: $" << amount << " from account number: " << accountNumber << endl;
        }

        // Display the account's basic information
        virtual void displayAccountInfo() const
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Owner: " << owner << endl;
            cout << "Balance: $" << balance << endl;
        }
    };

    // Static member initialization to start the account number counter at 0
    int BankAccount::accountNumberCounter = 0;

    // Derived class representing a savings account
    class SavingsAccount : public BankAccount
    {
    private:
        double interestRate; // Interest rate specific to the savings account

    public:
        // Constructor that initializes the savings account with the owner's name, balance, and interest rate
        SavingsAccount(string ownerName, double initialBalance, double rate)
            : BankAccount(ownerName, initialBalance), interestRate(rate) {}

        // Function to apply interest to the savings account balance
        void applyInterest()
        {
            double interest = getBalance() * interestRate; // Calculate interest based on current balance
            deposit(interest);                             // Deposit the interest into the account
            cout << "Applied interest: $" << interest << " to account number: " << getAccountNumber() << endl;
        }

        // Override display function to show additional information specific to savings account
        void displayAccountInfo() const override
        {
            BankAccount::displayAccountInfo();                              // Call base class function
            cout << "Interest Rate: " << interestRate * 100 << "%" << endl; // Show interest rate as a percentage
        }
    };

    // Derived class representing a checking account with overdraft protection
    class CheckingAccount : public BankAccount
    {
    private:
        double overdraftFee; // Overdraft fee specific to the checking account

    public:
        // Constructor that initializes the checking account with the owner's name, balance, and overdraft fee
        CheckingAccount(string ownerName, double initialBalance, double fee)
            : BankAccount(ownerName, initialBalance), overdraftFee(fee) {}

        // Override withdraw function to handle overdraft scenarios
        void withdraw(double amount) override
        {
            if (amount > getBalance()) // If withdrawal amount exceeds balance
            {
                cout << "Overdraft! Applying overdraft fee of $" << overdraftFee << endl;
                BankAccount::withdraw(getBalance()); // Withdraw remaining balance to set it to zero
                BankAccount::withdraw(overdraftFee); // Apply overdraft fee
            }
            else
            {
                BankAccount::withdraw(amount); // Perform normal withdrawal if sufficient balance
            }
        }

        // Override display function to show additional information specific to checking account
        void displayAccountInfo() const override
        {
            BankAccount::displayAccountInfo();                  // Call base class function
            cout << "Overdraft Fee: $" << overdraftFee << endl; // Display overdraft fee
        }
    };
}

// Function to display the main menu options
void displayMenu()
{
    cout << "\n=== Banking System Menu ===" << endl;
    cout << "1. Create Savings Account" << endl;
    cout << "2. Create Checking Account" << endl;
    cout << "3. Deposit Money" << endl;
    cout << "4. Withdraw Money" << endl;
    cout << "5. View Account Info" << endl;
    cout << "6. Apply Interest (Savings Accounts Only)" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
    // Map to store all created bank accounts using account number as the key
    map<int, Banking::BankAccount *> bankAccounts;
    int choice = 0; // Variable to store user's menu choice

    try
    {
        // Main loop for menu-based user interaction
        while (choice != 7)
        {
            displayMenu(); // Display menu options
            cin >> choice; // Get user's choice

            if (choice == 1) // Create a new savings account
            {
                string owner;
                double balance, rate;
                cout << "Enter owner's name: ";
                cin >> owner;
                cout << "Enter initial balance: ";
                cin >> balance;
                cout << "Enter interest rate (as a decimal): ";
                cin >> rate;

                // Create a new SavingsAccount and store it in the map
                Banking::SavingsAccount *newAccount = new Banking::SavingsAccount(owner, balance, rate);
                bankAccounts[newAccount->getAccountNumber()] = newAccount;
            }
            else if (choice == 2) // Create a new checking account
            {
                string owner;
                double balance, fee;
                cout << "Enter owner's name: ";
                cin >> owner;
                cout << "Enter initial balance: ";
                cin >> balance;
                cout << "Enter overdraft fee: ";
                cin >> fee;

                // Create a new CheckingAccount and store it in the map
                Banking::CheckingAccount *newAccount = new Banking::CheckingAccount(owner, balance, fee);
                bankAccounts[newAccount->getAccountNumber()] = newAccount;
            }
            else if (choice == 3) // Deposit money into an account
            {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;

                if (bankAccounts.find(accountNumber) != bankAccounts.end()) // Check if account exists
                {
                    bankAccounts[accountNumber]->deposit(amount); // Deposit money into the account
                }
                else
                {
                    cout << "Account not found!" << endl;
                }
            }
            else if (choice == 4) // Withdraw money from an account
            {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (bankAccounts.find(accountNumber) != bankAccounts.end()) // Check if account exists
                {
                    bankAccounts[accountNumber]->withdraw(amount); // Withdraw money from the account
                }
                else
                {
                    cout << "Account not found!" << endl;
                }
            }
            else if (choice == 5) // View account information
            {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;

                if (bankAccounts.find(accountNumber) != bankAccounts.end()) // Check if account exists
                {
                    bankAccounts[accountNumber]->displayAccountInfo(); // Display account information
                }
                else
                {
                    cout << "Account not found!" << endl;
                }
            }
            else if (choice == 6) // Apply interest to a savings account
            {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;

                // Use dynamic_cast to check if the account is a savings account
                Banking::SavingsAccount *savingsAccount = dynamic_cast<Banking::SavingsAccount *>(bankAccounts[accountNumber]);
                if (savingsAccount)
                {
                    savingsAccount->applyInterest(); // Apply interest if it is a savings account
                }
                else
                {
                    cout << "Not a savings account or account not found!" << endl;
                }
            }
        }
    }
    catch (exception &e)
    {
        // Catch any runtime errors and display a message
        cout << "Error: " << e.what() << endl;
    }

    // Clean up dynamically allocated memory by deleting all accounts in the map
    for (auto &pair : bankAccounts)
    {
        delete pair.second; // Delete each BankAccount object
    }

    cout << "Exiting the Banking System." << endl;
    return 0;
}
