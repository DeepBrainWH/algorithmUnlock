//
// Created by wangheng on 2/16/19.
//

#ifndef ALGORITHMUNLOCK_MICROSOFT_H
#define ALGORITHMUNLOCK_MICROSOFT_H

/**
 * 微软面试100题算法
 */
#include <iostream>

namespace ms{
//    输入一棵二元查找树,将该二元查找树转换成一个排序的双向链表。
//    要求不能创建任何新的结点,只调整指针的指向。
//    10
//    / /
//    6 14
//    / / / /
//    4 8 12 16
//    转换成双向链表
//    4=6=8=10=12=14=16。
    struct BSTreeNode{
        int data;
        BSTreeNode* left;//pre
        BSTreeNode* right;//next
    };

    BSTreeNode* build_tree(){
        /**
         * return tree's root.
         */
        BSTreeNode* root = new BSTreeNode;
        root->data = 10;
        root->left = new BSTreeNode;
        root->right = new BSTreeNode;
        root->left->data = 6;
        root->right->data = 14;
        root->left->left = new BSTreeNode;
        root->left->right = new BSTreeNode;
        root->left->left->data = 4;
        root->left->right->data = 8;
        root->right->left = new BSTreeNode;
        root->right->right = new BSTreeNode;
        root->right->left->data = 12;
        root->right->right->data = 16;
        return root;
    }

    void prepare_order(BSTreeNode* root){
        if(root == nullptr)return;
        cout<<root->data<<" ";
        prepare_order(root->left);
        prepare_order(root->right);
    }

    void mid_order_to_link_list(BSTreeNode* T){

        if(T != nullptr){
            BSTreeNode* current = T;
            mid_order_to_link_list(current->left);
        }
    }

    void free_memory(BSTreeNode* root){
        BSTreeNode* p = root;
        if(root == nullptr){
            return;
        }
        if(p->left != nullptr){
            free_memory(p->left);
        }
        if(p->right != nullptr){
            free_memory(p->right);
        }
        delete root;
    }
}
#endif //ALGORITHMUNLOCK_MICROSOFT_H
