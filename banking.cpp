#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string number, std::string name, double initialBalance)
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
            std::cout << "Deposit successful. Current balance: " << balance << std::endl;
        }
        else {
            std::cout << "Invalid deposit amount. Please enter a positive value." << std::endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            std::cout << "Withdrawal successful. Current balance: " << balance << std::endl;
        }
        else if (amount > balance)
        {
            std::cout << "Insufficient funds. Current balance: " << balance << std::endl;
        }
        else 
        {
            std::cout << "Invalid withdrawal amount. Please enter a positive value." << std::endl;
        }
    }

    void checkBalance() 
    {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: " << balance << std::endl;
    }
};

int main() 
{
    // Creating a new bank account
    BankAccount myAccount("5255687456875", "Gil Liran", 15000.0);

    // Performing some transactions
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.checkBalance();

    return 0;
}
