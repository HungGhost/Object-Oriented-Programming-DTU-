#include <bits/stdc++.h>
using namespace std;
int searchinteger(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return 1;
        }
    }
    return -1;
}
int Max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 0; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
struct Rectangle
{
    float length;
    float breadth;
};
void input(Rectangle &rec)
{
    cout << "Nhap length: ";
    cin >> rec.length;
    cout << "Nhap breadth: ";
    cin >> rec.breadth;
}
void displayDimensions(const Rectangle &rect)
{
    cout << "Length: " << rect.length << ", Breadth: " << rect.breadth << endl;
}
void displayArea(const Rectangle &rect)
{
    float area = rect.length * rect.breadth;
    cout << "Area: " << area << endl;
}
int main()
{
    int n,x;
    cout << "Enter the length of the array: ";
    cin >> n;
    int *numbers = new int[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout << "Enter x: ";
    cin >> x;
    cout << "Search Result: " << searchinteger(numbers, n, x) << endl;
    cout << "Max Element: " << Max(numbers, n) << endl;

    bubbleSort(numbers, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    Rectangle rect;
    input(rect);
    displayDimensions(rect);
    displayArea(rect);
    delete[] numbers;
    return 0;
}
