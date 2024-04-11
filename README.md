# hands-on-12


### Part 1: Implementing a Dynamic Array (Vector) using C-style arrays

This code defines a simple dynamic array class that mimics the functionality of a C++ vector using C-style arrays. It implements a `push_back` method to insert elements into the array dynamically and automatically doubles the array's capacity when needed.

### Part 2: Amortized Runtime Analysis

#### a) Aggregate Method

The aggregate method calculates the average cost per operation. In the case of inserting `n` elements, the total cost is the sum of individual insertions, which grows as `O(n)` since each insertion operation takes constant time on average. Therefore, the amortized cost per insertion is `O(1)`.

#### b) Accounting Method

In the accounting method, we maintain a "bank account" to distribute the cost of expensive operations over cheaper ones. For each insertion, we "charge" `1` unit of cost and "pay" for doubling the array capacity by putting `1` unit into the bank. Since doubling the array only happens when the array is full, and we insert `n` elements, the total cost is `2n`. Therefore, the amortized cost per insertion is `2n / n = 2`, which is still `O(1)`.

These analyses demonstrate that both methods yield a constant amortized runtime for inserting `n` elements into the dynamic array.
