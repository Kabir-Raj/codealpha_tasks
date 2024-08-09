#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
    int customerID;
    string name;
    string address;
    string phoneNumber;
    string email;

public:
    // Constructor
    Customer(int id, string n, string addr, string phone, string mail)
        : customerID(id), name(n), address(addr), phoneNumber(phone), email(mail) {}

    // Method to create a new customer
    void createCustomer(int id, string n, string addr, string phone, string mail)
    {
        customerID = id;
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    // Method to view customer information
    void viewCustomerInfo() const
    {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};
class Account
{
private:
    int accountID;
    int customerID;
    double balance;

public:
    // Constructor
    Account(int accID, int custID, double bal)
        : accountID(accID), customerID(custID), balance(bal) {}

    // Method to create a new account
    void createAccount(int accID, int custID, double bal)
    {
        accountID = accID;
        customerID = custID;
        balance = bal;
    }

    // Method to view account information
    void viewAccountInfo() const
    {
        cout << "Account ID: " << accountID << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Balance: " << balance << endl;
    }

    // Method to deposit money
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "New Balance: " << balance << endl;
    }

    // Method to withdraw money
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            cout << "New Balance: " << balance << endl;
        }
    }

    // Method to transfer money
    void transfer(Account &toAccount, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balance -= amount;
            toAccount.deposit(amount);
            cout << "Transferred: " << amount << " to Account ID: " << toAccount.accountID << endl;
        }
    }
};
class Transaction
{
private:
    int transactionID;
    int accountID;
    string type;
    double amount;
    string date;

public:
    // Constructor
    Transaction(int transID, int accID, string t, double amt, string d)
        : transactionID(transID), accountID(accID), type(t), amount(amt), date(d) {}

    // Method to create a new transaction
    void createTransaction(int transID, int accID, string t, double amt, string d)
    {
        transactionID = transID;
        accountID = accID;
        type = t;
        amount = amt;
        date = d;
    }

    // Method to view transaction information
    void viewTransactionInfo() const
    {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Account ID: " << accountID << endl;
        cout << "Type: " << type << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << date << endl;
    }
};
class BankingService
{
public:
    // Method to perform a deposit
    static void performDeposit(Account &account, double amount)
    {
        account.deposit(amount);
    }

    // Method to perform a withdrawal
    static void performWithdrawal(Account &account, double amount)
    {
        account.withdraw(amount);
    }

    // Method to perform a transfer
    static void performTransfer(Account &fromAccount, Account &toAccount, double amount)
    {
        fromAccount.transfer(toAccount, amount);
    }
};
int main()
{
    // Create a customer
    Customer customer1(1, "John Doe", "123 Main St", "123-456-7890", "john@example.com");
    customer1.viewCustomerInfo();

    // Create accounts for the customer
    Account account1(1001, 1, 500.0);
    Account account2(1002, 1, 1000.0);

    account1.viewAccountInfo();
    account2.viewAccountInfo();

    // Perform some transactions
    BankingService::performDeposit(account1, 200.0);
    BankingService::performWithdrawal(account2, 150.0);
    BankingService::performTransfer(account1, account2, 300.0);
    account1.viewAccountInfo();
    account2.viewAccountInfo();

    // Create a transaction
    Transaction transaction1(1, 1001, "Deposit", 200.0, "2024-08-04");
    transaction1.viewTransactionInfo();

    return 0;
}
