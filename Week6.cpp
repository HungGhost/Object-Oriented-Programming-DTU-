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

    IntArr operator+(const IntArr& other) const {
        IntArr result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }
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

    int operator[](int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1;
    }
    friend istream& operator>>(istream& is, IntArr& obj) {
        for (int i = 0; i < obj.size; i++) {
            is >> obj.arr[i];
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const IntArr& obj) {
        for (int i = 0; i < obj.size; i++) {
            os << obj.arr[i] << " ";
        }
        return os;
    }
};
// write something to week 7
// I don't know about matrix knowledge
