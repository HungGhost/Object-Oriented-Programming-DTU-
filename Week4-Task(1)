#include <bits/stdc++.h>

class Circle; // Forward declaration

class Rectangle {
private:
    float length;
    float width;
    float area;

public:
    void input() {
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;
        area = length * width;
    }

    void display() {
        cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << area << endl;
    }

    friend void larger(Rectangle r, Circle c);
};

class Circle {
private:
    float radius;
    float area;

public:
    void input() {
        cout << "Enter the radius of circle: ";
        cin >> radius;
        area = 3.14 * radius * radius;
    }

    void display() {
        cout << "Circle - Radius: " << radius << ", Area: " << area << endl;
    }

    friend void larger(Rectangle r, Circle c);
};

void larger(Rectangle r, Circle c) {
    if (r.area > c.area) {
        cout << "Rectangle has a larger area." << endl;
    } else if (c.area > r.area) {
        cout << "Circle has a larger area." << endl;
    } else {
        cout << "Both have the same area." << endl;
    }
}

int main() {
    Rectangle rectangle;
    Circle circle;

    rectangle.input();
    rectangle.display();

    circle.input();
    circle.display();

    larger(rectangle, circle);

    return 0;
}
