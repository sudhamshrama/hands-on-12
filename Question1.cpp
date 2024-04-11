#include <iostream>

class DynamicArray {
private:
    int* array;
    int capacity;
    int size;

public:
    DynamicArray() {
        capacity = 1; // Initial capacity
        size = 0;
        array = new int[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void push_back(int value) {
        if (size == capacity) {
            // Double the capacity
            int new_capacity = capacity * 2;
            int* new_array = new int[new_capacity];

            // Copy elements to the new array
            for (int i = 0; i < size; ++i) {
                new_array[i] = array[i];
            }

            // Delete old array and update pointers
            delete[] array;
            array = new_array;
            capacity = new_capacity;
        }

        // Add the new element
        array[size++] = value;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    int operator[](int index) {
        return array[index];
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
