#include <bits/stdc++.h>
using namespace std;

class Student {
protected:
    string name;
    int id;

public:
    Student(string name, int id) {
        this->name = name;
        this->id = id;
    }
};

class Sports : virtual public Student {
protected:
    int s_grade;

public:
    Sports(string name, int id, int s_grade) : Student(name, id) {
        this->s_grade = s_grade;
    }
};

class Exam : virtual public Student {
protected:
    int e_grade;

public:
    Exam(string name, int id, int e_grade) : Student(name, id) {
        this->e_grade = e_grade;
    }
};

class Results : public Sports, public Exam {
private:
    string result;

public:
    Results(string name, int id, int s_grade, int e_grade, string result)
        : Student(name, id), Sports(name, id, s_grade), Exam(name, id, e_grade) {
        this->result = result;
    }

    void display() const {
        cout << "Name: " << name << ", ID: " << id << ", Sports Grade: " << s_grade
             << ", Exam Grade: " << e_grade << ", Result: " << result << '\n';
    }
};

class Shape {
protected:
    double a;
    double b;

public:
    void getData(double a, double b) {
        this->a = a;
        this->b = b;
    }

    virtual void displayArea() const = 0;
};

class Triangle : public Shape {
public:
    void displayArea() const override {
        cout << "Area of Triangle: " << 0.5 * a * b << '\n';
    }
};

class Rectangle : public Shape {
public:
    void displayArea() const override {
        cout << "Area of Rectangle: " << a * b << '\n';
    }
};

class LinkedList {
protected:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

class DoubleEndedList : public LinkedList {
private:
    Node* tail;

public:
    DoubleEndedList() {
        tail = nullptr;
    }

    void add(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromFront() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    void deleteFromBack() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }
};

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void add(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};

auto main() -> int {
    Results r("Thanh Hung", 123, 90, 85, "Heoo");
    r.display();
    LinkedList l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.display();

    DoubleEndedList dl;
    dl.add(10);
    dl.add(20);
    dl.add(30);
    dl.display();
    dl.deleteFromFront();
    dl.display();
    dl.deleteFromBack();
    dl.display();
}
