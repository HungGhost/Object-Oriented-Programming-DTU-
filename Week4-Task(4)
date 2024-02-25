#include <iostream>
#include <string>

class Customer {
private:
    int customerID;
    string name;
    double creditLimit;

public:
    void setData(int id, const string& n, double limit) {
        customerID = id;
        name = n;
        creditLimit = limit;
    }

    void displayData() {
        cout << "Customer ID: " << customerID << ", Name: " << name << ", Credit Limit: " << creditLimit << endl;
    }
};

int main() {
    Customer customers[5];

    for (int i = 0; i < 5; ++i) {
        int id;
        string name;
        double limit;

        cout << "Enter details for Customer " << i + 1 << endl;
        cout << "Customer ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore(); // Ignore newline character left in buffer
        getline(cin, name);
        cout << "Credit Limit: ";
        cin >> limit;

        customers[i].setData(id, name, limit);
    }

    for (int i = 0; i < 5; ++i) {
        customers[i].displayData();
    }

    return 0;
}
