#include "whlog.h"
#include <iostream>
const int num[] = { 1, 5, 10, 50, 100, 500, 1000, 5000, 10000 };
const std::string sym[] = { "I", "V", "X", "L", "C", "D", "M", "G", "H" };
const int length = 9;
int get_integer_value_by_roman_number(char n)
{
    int index = -1;
    for (int i = 0; i < length; i++) {
        if (sym[i][0] == n) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        return num[index];
    }
    return -1;
}
int roman_to_integer(std::string roman_number)
{
    int result = 0;
    int len = roman_number.length();
    int tmp1, tmp2;
    for (int i = 0; i < len; i++) {
        if (i + 1 < len) {
            tmp1 = get_integer_value_by_roman_number(roman_number[i]);
            tmp2 = get_integer_value_by_roman_number(roman_number[i + 1]);
            if (tmp1 >= tmp2) {
                result += tmp1;
            } else {
                result += (tmp2 - tmp1);
                i++;
            }
        } else {
            result += get_integer_value_by_roman_number(roman_number[i]);
        }
    }
    return result;
}
int main()
{
    wh::info("hello this is an information");
    wh::warning("hello this is warning information");
    wh::error("hello this is an error");
    std::string input;
    std::cout << "Please input the roman string: ";
    std::cin >> input;
    std::cout << roman_to_integer(input) << std::endl;
    return 0;
}