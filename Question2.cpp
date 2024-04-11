#include <iostream>
#include <chrono>

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
};

int main() {
    const int n = 1000000; // Number of elements to insert
    DynamicArray arr;

    // Time measurement for aggregate method
    auto start_agg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        arr.push_back(i);
    }
    auto end_agg = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_agg = end_agg - start_agg;
    std::cout << "Aggregate method time: " << elapsed_agg.count() << " seconds\n";

    // Time measurement for accounting method
    arr = DynamicArray(); // Reset array
    auto start_acc = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        arr.push_back(i);
    }
    auto end_acc = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_acc = end_acc - start_acc;
    std::cout << "Accounting method time: " << elapsed_acc.count() << " seconds\n";

    return 0;
}
