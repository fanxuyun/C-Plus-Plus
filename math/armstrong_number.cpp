/**
 * @file
 * \brief Program to check if a number is an [Armstrong/Narcissistic
 * number](https://en.wikipedia.org/wiki/Narcissistic_number) in decimal system.
 *
 * \details
 * Armstrong number or [Narcissistic
 * number](https://en.wikipedia.org/wiki/Narcissistic_number) is a number that
 * is the sum of its own digits raised to the power of the number of digits.
 * @author iamnambiar
 */
#include <cassert>
#include <cmath>
#include <iostream>

// @fanxuyun: this is origin scheme of armstrong number judgement.
namespace originScheme {
/**
 * Function to calculate the total number of digits in the number.
 * @param num Number
 * @return Total number of digits.
 */
// @fanxuyun: fix number base(½øÖÆ) with 10. I have 2 comments:
// 1: type of input parameter and return value should be unsigned int.
// 2: take number base into account.
int number_of_digits(int num) {
    int total_digits = 0;
    while (num > 0) {
        num = num / 10;
        ++total_digits;
    }
    return total_digits;
}

/**
 * Function to check whether the number is armstrong number or not.
 * @param num Number
 * @return `true` if the number is armstrong.
 * @return `false` if the number is not armstrong.
 */
bool is_armstrong(int number) {
    // @fanxuyun: no need to check negative number as armstrong number is noly
    // for natural number, which is not less than 0.
    // If the number is less than 0, then it is not a armstrong number.
    if (number < 0) {
        return false;
    }
    int sum = 0;
    int temp = number;
    // Finding the total number of digits in the number
    int total_digits = number_of_digits(number);
    while (temp > 0) {
        int rem = temp % 10;
        // Finding each digit raised to the power total digit and add it to the
        // total sum
        sum = sum + std::pow(rem, total_digits);
        temp = temp / 10;
    }
    return number == sum;
}
}  // namespace originScheme

// @fanxuyun: this is my scheme of armstrong number judgement.
namespace myScheme {
/**
 * Function to calculate the total number of digits in the number.
 * @param num Number
 * @return Total number of digits.
 */
unsigned int number_of_digits(unsigned int num, unsigned int base) {
    // number base must be positive number
    assert(base > 0);
    // get value k in https://en.wikipedia.org/wiki/Narcissistic_number
    unsigned int total_digits = floor(log(num) / log(base)) + 1;
    return total_digits;
}

/**
 * Function to check whether the number is armstrong number or not.
 * @param num Number
 * @return `true` if the number is armstrong.
 * @return `false` if the number is not armstrong.
 */
bool is_armstrong(unsigned int number, unsigned int base) {
    // number base must be positive number
    assert(base > 0);
    unsigned int k = number_of_digits(number, base);
    unsigned int mappingResult = 0;
    for (unsigned int digitIdx = 0; digitIdx <= k - 1; digitIdx++) {
        // @fanxuyun: a general method to get every digit of input natural
        // number, given the number base.
        // refer to https://en.wikipedia.org/wiki/Narcissistic_number
        unsigned int temp1 =
            number % (unsigned int)(std::pow(base, digitIdx + 1));
        unsigned int temp2 = number % (unsigned int)(std::pow(base, digitIdx));
        unsigned int thisDigit = (temp1 - temp2) / std::pow(base, digitIdx);
        mappingResult += std::pow(thisDigit, k);
    }
    return mappingResult == number;
}
}  // namespace myScheme

/**
 * Function for testing the is_armstrong() function
 * with all the test cases.
 */
void test() {
    std::cout << "Testing origin scheme." << std::endl;
    // is_armstrong(370) returns true.
    assert(originScheme::is_armstrong(370) == true);
    // is_armstrong(225) returns false.
    assert(originScheme::is_armstrong(225) == false);
    // is_armstrong(-23) returns false.
    assert(originScheme::is_armstrong(-23) == false);
    // is_armstrong(153) returns true.
    assert(originScheme::is_armstrong(153) == true);
    // is_armstrong(0) returns true.
    assert(originScheme::is_armstrong(0) == true);
    // is_armstrong(12) returns false.
    assert(originScheme::is_armstrong(12) == false);
    std::cout << "Origin scheme pass." << std::endl;

    std::cout << "Testing my scheme" << std::endl;
    unsigned int base = 10;
    assert(myScheme::is_armstrong(153, base) == true);
    assert(myScheme::is_armstrong(370, base) == true);
    assert(myScheme::is_armstrong(371, base) == true);
    assert(myScheme::is_armstrong(373, base) == false);
    assert(myScheme::is_armstrong(407, base) == true);
    assert(myScheme::is_armstrong(1634, base) == true);
    assert(myScheme::is_armstrong(8208, base) == true);
    assert(myScheme::is_armstrong(9474, base) == true);
    assert(myScheme::is_armstrong(54748, base) == true);
    assert(myScheme::is_armstrong(92727, base) == true);
    assert(myScheme::is_armstrong(93084, base) == true);
    assert(myScheme::is_armstrong(548834, base) == true);

    base = 16;
    assert(myScheme::is_armstrong(0x173, base) == true);
    assert(myScheme::is_armstrong(0xAA9, base) == true);
    assert(myScheme::is_armstrong(0xEA1, base) == true);
    assert(myScheme::is_armstrong(0xEA2, base) == false);
    assert(myScheme::is_armstrong(0xC84E1, base) == true);
    std::cout << "My scheme pass." << std::endl;
}

/**
 * Main Function
 */
int main() {
    test();
    return 0;
}
