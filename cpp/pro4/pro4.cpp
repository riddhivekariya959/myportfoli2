#include <iostream>
#include <string>
using namespace std;


class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

protected:
    void updateBalance(double amount)
    {
        balance = amount;
    }

public:
    BankAccount(int number, string name, double bal)
    {
        accountNumber = number;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
            cout << "Invalid amount!\n";
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
            cout << "Insufficient balance or invalid amount!\n";
    }

    double getBalance() const
    {
        return balance;
    }

    virtual double calculateInterest() const
    {
        return 0;
    }

    virtual void displayAccountInfo() const
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: Rs. " << balance << endl;
    }

    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int n, string name, double b, double rate)
        : BankAccount(n, name, b)
    {
        interestRate = rate;
    }

    double calculateInterest() const override
    {
        return getBalance() * interestRate / 100;
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Savings Account ---";
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int n, string name, double b, double limit)
        : BankAccount(n, name, b)
    {
        overdraftLimit = limit;
    }

    bool checkOverdraft(double amount) const
    {
        return amount > getBalance() &&
               amount <= getBalance() + overdraftLimit;
    }

    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
        }
        else if (amount <= getBalance())
        {
            BankAccount::withdraw(amount);
        }
        else if (checkOverdraft(amount))
        {
            updateBalance(getBalance() - amount);
            cout << "Withdrawal successful using overdraft.\n";
        }
        else
        {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Checking Account ---";
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int n, string name, double b,
                        int months, double rate)
        : BankAccount(n, name, b)
    {
        term = months;
        interestRate = rate;
    }

    double calculateInterest() const override
    {
        return getBalance() * interestRate * term / 1200.0;
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Fixed Deposit Account ---";
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months\n";
        cout << "Interest Rate: " << interestRate << "% per year\n";
    }
};

int main()
{
   
    SavingsAccount savings(101, "Riddhi", 10000, 5);
    CheckingAccount checking(102, "Riddhi", 5000, 2000);
    FixedDepositAccount fixed(103, "Riddhi", 20000, 12, 7);

  
    BankAccount *accounts[3] = {&savings, &checking, &fixed};

    int choice, accountType;
    double amount;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Calculate Interest\n";
        cout << "5. Check Balance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > 5)
        {
            cout << "Invalid menu choice!\n";
            continue;
        }

        cout << "\nSelect Account Type:\n";
        cout << "1. Savings Account\n";
        cout << "2. Checking Account\n";
        cout << "3. Fixed Deposit Account\n";
        cout << "Enter account type: ";
        cin >> accountType;

        if (accountType < 1 || accountType > 3)
        {
            cout << "Invalid account type!\n";
            continue;
        }

        BankAccount *account = accounts[accountType - 1];

        switch (choice)
        {
        case 1:
            account->displayAccountInfo();
            break;

        case 2:
            cout << "Enter deposit amount: Rs. ";
            cin >> amount;
            account->deposit(amount);
            break;

        case 3:
            cout << "Enter withdrawal amount: Rs. ";
            cin >> amount;
            account->withdraw(amount);
            break;

        case 4:
            cout << "Interest: Rs. "
                 << account->calculateInterest() << endl;
            break;

        case 5:
            cout << "Current Balance: Rs. "
                 << account->getBalance() << endl;
            break;
        }

    } while (choice != 0);

    cout << "\nThank you for using the Bank Management System!\n";

    return 0;
}
