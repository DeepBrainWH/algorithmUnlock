//
// Created by wangheng on 2018-12-19.
// binary search tree.
//

#ifndef ALGORITHMUNLOCK_BINARY_SEARCH_TREE_H
#define ALGORITHMUNLOCK_BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class T>
class TreeNode{
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* pre;
};

template <class T>
class BBTree{
private:
    TreeNode<T>* root;

public:
    BBTree(){
        this->__init__();
    }
    ~BBTree(){
        delete []root;
    }

    void __init__(){
        this->root = nullptr;
    }

    void _build_tree(){
        TreeNode<T>* tmp_p;
        T data;
        while (true){
            cout<<"Please input the value of the tree, end with -99999:";
            cin>>data;
            if(data == -99999){
                cout<<"Ending build the BBTree!"<<endl;
                break;
            }
            auto* node = new TreeNode<T>;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;

            if(this->root == nullptr){
                node->pre = nullptr;
                this->root = node;
            }else{
                tmp_p = this->root;
                while(true){
                    if(tmp_p->data > node->data){
                        if(tmp_p->left == nullptr){
                            tmp_p->left = node;
                            node->pre = tmp_p;
                            break;
                        }else{
                            tmp_p = tmp_p->left;
                            continue;
                        }
                    }else{
                        if(tmp_p->right == nullptr){
                            node->pre = tmp_p;
                            tmp_p->right = node;
                            break;
                        }else{
                            tmp_p = tmp_p->right;
                            continue;
                        }
                    }
                }
            }
        }
    }

    void mid_order(TreeNode<T>* node){
        if(node == nullptr){
            return;
        }
        this->mid_order(node->left);
        cout<<node->data<<" ";
        this->mid_order(node->right);
    }



    TreeNode<T>* get_root_node(){
        return this->root;
    }
};


#endif //ALGORITHMUNLOCK_BINARY_SEARCH_TREE_H
