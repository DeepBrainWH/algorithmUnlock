#include <cstdio>
#include <iostream>

using namespace std;

const static int num[] = { 1, 5, 10, 50, 100, 500, 1000, 5000, 10000 };
const static string sym[] = { "I", "V", "X", "L", "C", "D", "M", "G", "H" };
const static int len = 9;

string get_roman_char_by_num(int div)
{
    // printf("[\033[42;30minfo\033[0m] the number is : %d\n", div);
    int high = len - 1;
    int low = 0;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (num[mid] == div) {
            return sym[mid];
        } else if (num[mid] < div) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return "-";
}

string to_roman_number(int number)
{
    string result = "";
    int div = 1;
    while (number > div) {
        div *= 10;
    }
    div /= 10;

    while (number > 0) {
        int last_num = number / div;
        if (last_num <= 3) {
            string tmp = get_roman_char_by_num(div);
            for (int i = 0; i < last_num; i++) {
                result = result + tmp;
            }
        } else if (last_num == 4) {
            result = result + (get_roman_char_by_num(div) + get_roman_char_by_num(div * 5));
        } else if (last_num >= 5 && last_num <= 8) {
            result += get_roman_char_by_num(div * 5);
            for (int i = 0; i < last_num - 5; i++) {
                result += get_roman_char_by_num(div);
            }
        } else if (last_num == 9) {
            result += get_roman_char_by_num(div)
                + get_roman_char_by_num(div * 10);
        } else if (last_num == 10) {
            result += "X";
        }
        std::cout << last_num << " " << div << std::endl;
        if (div % 10 == 0) {
            number = number / div;
        } else {
            number = number % div;
        }
        div /= 10;
    }
    return result;
}

int main(int len, char* argv[])
{
    cout << "Please input a integer number:";
    int num;
    cin >> num;
    string res = to_roman_number(num);
    cout << res << endl;
    return 0;
}