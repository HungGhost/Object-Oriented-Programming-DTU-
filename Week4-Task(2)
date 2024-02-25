#include <bits/stdc++.h>

class Rectangle;

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

    friend class Rectangle; // Rectangle is a friend of Circle

    void larger(Rectangle r);
};

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

    friend void Circle::larger(Rectangle r); // Circle's member function is a friend of Rectangle
};

void Circle::larger(Rectangle r) {
    if (r.area > this->area) {
        cout << "Rectangle has a larger area." << endl;
    } else if (this->area > r.area) {
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

    circle.larger(rectangle);

    return 0;
}
