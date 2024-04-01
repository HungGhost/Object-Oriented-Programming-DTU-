#include <bits/stdc++.h>
using namespace std;
template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void sortArray(T arr[], int size)
{
    sort(arr, arr + size);
}

template <typename T>
int searchArray(T arr[], int size, T key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
class Stack
{
private:
    T *stack;
    int top;
    int capacity;

public:
    Stack(int capacity) : capacity(capacity), top(-1)
    {
        stack = new T[capacity];
    }

    void push(T value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        stack[++top] = value;
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return T();
        }
        return stack[top--];
    }

    void display() const
    {
        for (int i = 0; i <= top; ++i)
        {
            cout << stack[i] << ' ';
        }
        cout << '\n';
    }
};

struct Student
{
    string name;
    int rollNo;
    double cgpa;
};

struct Employee
{
    std::string name;
    int empId;
    double salary;
};

template <typename T>
T getElement(T arr[], int size, int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Index out of range" << std::endl;
    }
    return arr[index];
}
