#include<iostream>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

class Transaction {
public:
    time_t timestamp;
    double amount;
    double new_bal;

    Transaction(double amount, double new_bal) : amount(amount), new_bal(new_bal) {
        timestamp = time(0);
    }
};

class Loan {
public:
    time_t timestamp;
    double amount;
    double interest;

    Loan(double amount, double interest) : amount(amount), interest(interest) {
        timestamp = time(0);
    }
};

class Customer {
private:
    string account_no;
    string name;
    string address;
    string account_type;
    double funds;
    vector<Transaction> transaction_history;
    vector<Loan> loan_history;

public:
    Customer(string account_no, string name, string address, string account_type)
        : account_no(account_no), name(name), address(address), account_type(account_type), funds(0) {}

    void update(string new_name, string new_address, string new_account_type){
        name = new_name;
        address = new_address;
        account_type = new_account_type;
    }

    void transact(double amount){
        if(amount != 0){
            funds += amount;
            transaction_history.push_back(Transaction(amount, funds));
        }
        else{
            cout << "Invalid amount entered!!"<<endl;
        }
    }

    void fundtransfer(Customer& payee, double amount){
        if(amount > 0 && amount <= funds){
            payee.funds += amount;
            payee.transaction_history.push_back(Transaction(amount, payee.funds));
            funds -= amount;
            transaction_history.push_back(Transaction(-amount, funds));
            cout << amount << " successfully transferred to "<< payee.account_no << endl;
        }
        else{
            cout << "Fund transfer failed due to invalid input/insufficient balance" << endl;
        }
    }

    void viewPassbook(){
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transaction_history) {
            cout << "Transaction Amount: " << transaction.amount << ", Timestamp: " << ctime(&transaction.timestamp) << ", New Balance: " << transaction.new_bal << endl;    
        }
    }

    void loan(double amount, double interest){
        funds += amount;
        loan_history.push_back(Loan(amount, interest));
        transaction_history.push_back(Transaction(amount, funds));
        cout << "Loan for amount: "<<amount<<" for an interest rate of: "<<interest<<" has been succesfully granted."<<endl;
    }

    void searchTransactions(string date) { //format for date: month as Mon(space)date as dd(space)year as yyyy 
        cout << "Transactions on " << date << ":" << endl;
        for (const auto& transaction : transaction_history) {
            string timestampStr = ctime(&transaction.timestamp);
            string a = timestampStr.substr(4, 7);
            string b = timestampStr.substr(20, 4);
            string concat = a + b;
            if (concat == date) {
                cout << "Amount: " << transaction.amount << ", Timestamp: " << timestampStr << endl;
            }
        }
    }

    void searchTransactions(double amount) {
        cout << "Transactions with amount " << amount << ":" << endl;
        for (const auto& transaction : transaction_history) {
            if (transaction.amount == amount) {
                cout << "Transaction Amount: " << transaction.amount << ", Timestamp: " << ctime(&transaction.timestamp) << endl;
            }
        }
    }
};

int main(){
    
    return 0;
}