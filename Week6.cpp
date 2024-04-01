class IntArr {
private:
    int* arr;
    int size;

public:
    IntArr(int size) {
        this->size = size;
        arr = new int[size];
    }

    ~IntArr() {
        delete[] arr;
    }

    // Overload + operator to add 2 IntArr objects
    IntArr operator+(const IntArr& other) const {
        IntArr result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    // Overload == operator to compare equality of 2 objects
    bool operator==(const IntArr& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i]) {
                return false;
            }
        }
        return true;
    }

    // Overload [] operator to retrieve an integer from the specified index
    int operator[](int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1;
    }

    // Overload input operator
    friend istream& operator>>(istream& is, IntArr& obj) {
        for (int i = 0; i < obj.size; i++) {
            is >> obj.arr[i];
        }
        return is;
    }

    // Overload output operator
    friend ostream& operator<<(ostream& os, const IntArr& obj) {
        for (int i = 0; i < obj.size; i++) {
            os << obj.arr[i] << " ";
        }
        return os;
    }
};
// I don't know about matrix knowledge
