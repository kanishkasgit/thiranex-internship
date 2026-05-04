#include <iostream>
#include <fstream>
using namespace std;

class Bank {
private:
    int accNo;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccNo() {
        return accNo;
    }

    void deposit() {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Amount deposited successfully!\n";
    }

    void withdraw() {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if (amt > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amt;
            cout << "Withdrawal successful!\n";
        }
    }
};

// 🔹 Create Account
void addAccount() {
    Bank b;
    ofstream file("bank.dat", ios::binary | ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    b.createAccount();
    file.write((char*)&b, sizeof(b));

    file.close();
    cout << "Account created successfully!\n";
}

// 🔹 Display All Accounts
void displayAll() {
    Bank b;
    ifstream file("bank.dat", ios::binary);

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    cout << "\n--- Account Details ---\n";

    while (file.read((char*)&b, sizeof(b))) {
        b.showAccount();
        cout << "----------------------\n";
    }

    file.close();
}

// 🔹 Deposit Money
void depositMoney() {
    int acc;
    bool found = false;
    Bank b;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    cout << "Enter Account No: ";
    cin >> acc;

    while (file.read((char*)&b, sizeof(b))) {
        if (b.getAccNo() == acc) {
            b.deposit();

            int pos = file.tellg() - sizeof(b);
            file.seekp(pos);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}

// 🔹 Withdraw Money
void withdrawMoney() {
    int acc;
    bool found = false;
    Bank b;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    cout << "Enter Account No: ";
    cin >> acc;

    while (file.read((char*)&b, sizeof(b))) {
        if (b.getAccNo() == acc) {
            b.withdraw();

            int pos = file.tellg() - sizeof(b);
            file.seekp(pos);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}

// 🔹 Main Function
int main() {
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addAccount(); break;
            case 2: displayAll(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
