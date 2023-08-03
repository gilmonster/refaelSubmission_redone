#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool containsOnlyDigits(const string& str)
{
    for (char ch : str) 
    {
        if (!isdigit(ch)) 
        {
            return false;
        }
    }
    return true;
}

bool containsOnlyCharacters(const string& str)
{
    for (char ch : str)
    {
        if (!isalpha(ch)) 
        {
            return false;
        }
    }
    return true;
}
class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string number, string name, double initialBalance)
    {

        accountNumber = number;
        accountHolderName = name;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. Current balance: " << balance << endl;
        }
        else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds. Current balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    void checkBalance()
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }

    string get_account__holder_name()
    {
        return accountHolderName;
    }

    string get_account_number()
    {
        return accountNumber;
    }
};

int main() {
    int choice;
    double amount;
    string accountNumber, accountHolder;
    double initialBalance;

    BankAccount myAccount("0000000000", "Place Holder", 0.0);

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Change to differnt Account" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if ((myAccount.get_account_number() == "0000000000") && choice > 0 && choice < 4)
        {
            cout << "Please initate an acount before any traceaction" << endl;
            choice = 6;
        }
        switch (choice)
        {
        case 1:
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.checkBalance();
            break;
        case 4:
            cout << "Enter the account number (10 digits): ";
            cin >> accountNumber;
            if (accountNumber.length() != 10)
            {
                cout << "Account number must be 10 digits!" << endl;
                break;
            }
            if (!containsOnlyDigits(accountNumber)) 
            {
                cout << "Account number must have only digits!" << endl;
            }
            cout << "Enter the account holder name: ";
            cin.ignore();
            getline(cin, accountHolder);
            if (accountHolder.length() != 0)
            {
                if (!containsOnlyCharacters(accountHolder))
                {
                    cout << "accunt name must only containes characters" << endl;
                    break;
                }
            }
            cout << "Enter the initial balance: ";
            cin >> initialBalance;
            myAccount = BankAccount(accountNumber, accountHolder, initialBalance);
            cout << "Account created successfully." << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}


