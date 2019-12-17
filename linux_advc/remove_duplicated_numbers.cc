#include <iostream>
/*
Given a sorted array nums, remove the duplicates in-place such that each element appear 
only once and return the new length.Do not allocate extra space for another array, you must 
do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified 
to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
*/
class Solution {
public:
    Solution() {}
    ~Solution() = default;
    int remove_duplicated_numbers(int* a, int len)
    {
        if (len == 0) {
            return 0;
        }
        int p = 0;
        int q = 1;
        while (q < len) {
            if (a[p] == a[q]) {
                q++;
            } else {
                a[p + 1] = a[q];
                p++;
            }
        }
        return p + 1;
    }
};

int main()
{
    int a[5] = { 1, 2, 2, 3, 3 };
    auto* solu = new Solution();
    int res = solu->remove_duplicated_numbers(a, 5);
    for (int i = 0; i < res; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}