#include <iostream>

class Counter {
private:
    static int count; // Static data member to count objects

public:
    Counter() {
        count++;
    }

    static void showCount() {
        cout << "Number of objects created: " << count << endl;
    }
};

// Initialize the static data member
int Counter::count = 0;

int main() {
    Counter obj1, obj2, obj3;

    Counter::showCount(); // Display the count

    return 0;
}
