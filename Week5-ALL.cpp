#include <bits/stdc++.h>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    Complex(){}
    Complex(double real, double imag)
    {
        this->imag = imag;
        this->real = real;
    }
    Complex(const Complex& c)
    {
        real = c.real;
        imag = c.imag;
    }
    void display() const {
        cout << real << " + " << imag << "i\n";
    }
};

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(){
        hour = 0;
        minute = 0;
        second = 0;
    }
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    Time(const Time& t)
    {
        hour = t.hour;
        minute = t.minute;
        second = t.second;
    }

    void display() const {
        cout << hour << ":" << minute << ":" << second << "\n";
    }
};

class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    static double interestRate;

public:
    BankAccount()
    {
        name = "";
        accountNumber = 0;
        accountType = "";
        balance = 0;
    }
    BankAccount(string name, int accountNumber, string accountType, double balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->accountType = accountType;
        this->balance = balance;
    }
    BankAccount(const BankAccount& b)
    {
        name = b.name;
        accountNumber = b.accountNumber;
        accountType = b.accountType;
        balance = b.balance;
    }
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void display() const {
        cout << "Name: " << name << ", Account Number: " << accountNumber
                  << ", Account Type: " << accountType << ", Balance: " << balance << "\n";
    }

    static void displayInterestRate() {
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

double BankAccount::interestRate = 0.05;

class IntArr {
private:
    int* arr;
    int size;

public:
    IntArr()
    {
        arr = nullptr;
        size = 0;
    }
    IntArr(int* arr, int size) : size(size) {
        this->arr = new int[size];
        copy(arr, arr + size, this->arr);
    }
    IntArr(const IntArr& a) : IntArr(a.arr, a.size) {}

    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int search(int value) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    bool compare(const IntArr& a) const {
        if (size != a.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
        }
        return true;
    }
};

class String {
private:
    char* str;

public:
    String() {
        str = nullptr;
    }
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    String(const String& s) : String(s.str) {}

    void display() const {
        cout << str << "\n";
    }

    ~String() {
        delete[] str;
    }

    void changeCase() {
        for (int i = 0; str[i]; i++) {
            str[i] = isupper(str[i]) ? tolower(str[i]) : toupper(str[i]);
        }
    }

    void reverse() {
        int len = strlen(str);
        for (int i = 0; i < len / 2; i++) {
            swap(str[i], str[len - i - 1]);
        }
    }
};
auto main() -> int
{
    Complex c1(3.0, 4.0);
    Complex c2(c1);
    c1.display();
    c2.display();
    Time t1(12, 30, 45);
    Time t2(t1);
    t1.display();
    t2.display();
    BankAccount b1("Thanh Hung", 123456, "Hihi", 1000);
    BankAccount b2(b1);
    b1.display();
    b2.display();
    b1.deposit(500);
    b1.withdraw(2000);
    b1.display();
    BankAccount::displayInterestRate();
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    IntArr a1(arr1, 5);
    IntArr a2(arr2, 5);
    a1.display();
    a2.display();
    cout << a1.search(3) << "\n";
    cout << a1.compare(a2) << "\n";
    String s1("Hello");
    String s2(s1);
    s1.display();
    s2.display();
    s1.changeCase();
    s1.display();
    s1.reverse();
    s1.display();
}
