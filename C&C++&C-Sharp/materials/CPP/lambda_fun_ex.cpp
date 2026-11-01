
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Lambda to print each number
    auto print = [](int n) {
        std::cout << n << " ";
    };

    std::cout << "Numbers: ";
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << std::endl;

    // Lambda to calculate the sum of numbers
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        sum += n;
    });

    std::cout << "Sum: " << sum << std::endl;

    // Lambda to filter even numbers
    std::vector<int> even_numbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers), [](int n) {
        return n % 2 == 0;
    });

    std::cout << "Even Numbers: ";
    std::for_each(even_numbers.begin(), even_numbers.end(), print);
    std::cout << std::endl;

    return 0;
}
// - *Printing Numbers*: The first lambda function print takes an integer and prints it. It is used with `std::for_each` to print all numbers in the vector.
// - *Calculating Sum*: The second lambda captures the sum variable by reference and adds each number to it. This demonstrates how lambdas can modify variables from the surrounding scope.
// - *Filtering Even Numbers*: The third lambda checks if a number is even and is used with std::copy_if to create a new vector containing only the even numbers.

