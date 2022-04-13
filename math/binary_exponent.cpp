/**
 * @file
 * @brief C++ Program to find Binary Exponent Iteratively and Recursively.
 *
 * Calculate a^b in O(log(b)) by converting b to a
 * binary number. Binary exponentiation is also known as exponentiation by
 * squaring.
 * @note This is a far better approach compared to naive method which
 * provide O(b) operations.
 *
 * Example:
 * 10 in number base 2 is 1010.
 * 2^10_d = 2^1010_b = 2^8_d * 2^2_d, 10_d means 10 in decimal, 1010_b means
 * 1010 in binary, which equals to 10_d, this rule applies.
 * 2^1 = 2
 * 2^2 = (2^1)^2 = 2^2 = 4
 * 2^4 = (2^2)^2 = 4^2 = 16
 * 2^8 = (2^4)^2 = 16^2 = 256
 * Hence to calculate 2^10 we only need to multiply 2^8 and 2^2
 * skipping 2^1 and 2^4.
 */

#include <iostream>

/// Recursive function to calculate exponent in O(log(n)) using binary
/// exponent.
int binExpo(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = binExpo(a, b / 2);
    if (b % 2) {
        return res * res * a;
    } else {
        return res * res;
    }
}

/// Iterative function to calculate exponent in O(log(n)) using binary
/// exponent.
int binExpo_alt(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

/// Main function
int main() {
    int a, b;
    /// Give two numbers a, b
    std::cin >> a >> b;
    if (a == 0 && b == 0) {
        std::cout << "Math error" << std::endl;
    } else if (b < 0) {
        std::cout << "Exponent must be positive !!" << std::endl;
    } else {
        int resRecurse = binExpo(a, b);
        /// int resIterate = binExpo_alt(a, b);

        /// Result of a^b (where '^' denotes exponentiation)
        std::cout << resRecurse << std::endl;
        /// std::cout << resIterate << std::endl;
    }
}
