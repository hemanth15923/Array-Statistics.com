#include <iostream>
#include <limits>
#include <vector>

int main() {
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    if (std::cin.fail() || n <= 0) {
        std::cout << "Please enter a positive whole number.\n";
        return 1;
    }

    std::vector<double> numbers(n);

    std::cout << "Enter " << n << " numbers:\n";

    for (int i = 0; i < n; i++) {
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Enter a number: ";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
        }
    }

    double sum = 0;
    double minimum = numbers[0];
    double maximum = numbers[0];

    for (double number : numbers) {
        sum += number;

        if (number < minimum) {
            minimum = number;
        }

        if (number > maximum) {
            maximum = number;
        }
    }

    double average = sum / n;

    std::cout << "\n=== Results ===\n";
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Average: " << average << '\n';
    std::cout << "Minimum: " << minimum << '\n';
    std::cout << "Maximum: " << maximum << '\n';

    return 0;
}
