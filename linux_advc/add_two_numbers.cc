#include <iostream>

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * 时间复杂度: O(n), 空间复杂度: O(1)
 **/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
    ListNode() {}
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

typedef struct ListNode ListNode;

class Solution {
public:
    Solution() {}
    ~Solution() = default;
    ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode *p1_pre, *p2_pre;
        int tmp = 0;
        while (p1 != NULL and p2 != NULL) {
            if (p1->val + p2->val + tmp <= 9) {
                p2->val = p2->val + p1->val + tmp;
                tmp = 0;
            } else {
                p2->val = (p2->val + p1->val + tmp - 10);
                tmp = 1;
            }
            p1_pre = p1;
            p2_pre = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == NULL && p2 == NULL && tmp == 0) {
            return l2;
        }
        ListNode* t = p1;
        ListNode* t_pre;
        if (p1 != NULL) {
            t = p1;
            while (t != NULL) {
                if (t->val + tmp <= 9) {
                    t->val = t->val + tmp;
                    p2_pre->next = p1;
                    tmp = 0;
                    return l2;
                } else {
                    t->val = t->val + tmp - 10;
                    tmp = 1;
                }
                t_pre = t;
                t = t->next;
            }
            ListNode* node = new ListNode;
            node->val = tmp;
            node->next = NULL;
            t_pre->next = node;
            p2_pre->next = p1;
        } else if (p2 != NULL) {
            t = p2;
            while (t != NULL) {
                if (t->val + tmp <= 9) {
                    t->val = t->val + tmp;
                    tmp = 0;
                    return l2;
                } else {
                    t->val = t->val + tmp - 10;
                    tmp = 1;
                    t_pre = t;
                    t = t->next;
                }
            }
            ListNode* node = new ListNode;
            node->val = tmp;
            node->next = NULL;
            t_pre->next = node;
        } else {
            ListNode* node = new ListNode;
            node->val = tmp;
            node->next = NULL;
            p2_pre->next = node;
        }
        return l2;
    }
};

void free_node(ListNode* node)
{
    ListNode* p = node;
    ListNode* tmp;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}
int main()
{
    ListNode* node1 = new ListNode(9, NULL);
    ListNode* node2 = new ListNode(9, node1);
    ListNode* node3 = new ListNode(9, NULL);
    ListNode* node4 = new ListNode();
    ListNode* node5 = new ListNode();
    ListNode* node6 = new ListNode();

    Solution* solu = new Solution();
    ListNode* result = solu->add_two_numbers(node2, node3);
    ListNode* t = result;
    while (t != NULL) {
        std::cout << t->val << "->";
        t = t->next;
    }
    std::cout << std::endl;

    free_node(node1);
    free_node(node4);
}
