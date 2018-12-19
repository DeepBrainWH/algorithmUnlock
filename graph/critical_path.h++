//
// Created by wangheng on 2018-12-19.
//

#ifndef ALGORITHMUNLOCK_CRITICAL_PATH_H
#define ALGORITHMUNLOCK_CRITICAL_PATH_H

#include <iostream>
#include <string>
#define MAX 99999

using namespace std;


class Node{
public:
    string name;
    int value;
    Node* next;
};

class CriticalPath {
public:
    CriticalPath() {
        this->__init__();
    }
    ~CriticalPath(){
        delete(&vertex);
        delete []top_sort;
        delete(&graph);
        delete []est;
        delete []lst;
    }

    void __init__() {
        Node* tmp_p;
        //初始化图的邻接表
        for (int i = 0; i < 9; i++) {
            string tmp_name = this->name[i];
            Node* node = new Node;
            node->name = tmp_name;
            node->value = 0;
            node->next = nullptr;
            this->vertex[i] = node;
            tmp_p = vertex[i];
            for(int j = 0;j<9;j++){
                if(this->graph[i][j] != 0 and this->graph[i][j] != MAX){
                    Node* node1 = new Node;
                    node1->name = this->name[j];
                    node1->value = this->graph[i][j];
                    node1->next = nullptr;
                    tmp_p->next = node1;
                    tmp_p = tmp_p->next;
                }
            }
        }
        this->_print_graph();
        this->_top_sort();
        this->est = this->_get_est();
        this->_print_est();
        this->lst = this->_get_lst();
        this->_print_lst();
    }

    /**
     * topological sort.
     */
    void _top_sort(){
        int in_degree[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        string* top_sort = new string[this->row];
        Node* tmp;
        for(int i = 0;i<this->row;i++){
            if(this->vertex[i] != nullptr){
                tmp = this->vertex[i]->next;
                while (tmp != nullptr){
                    in_degree[tmp->name[0] - 65] ++;
                    tmp = tmp->next;
                }
            }
        }
        int tmp_int = 0;
        for(int j = 0;j<this->row;j++){
            for(int i = 0;i<this->row;i++){
                if(in_degree[i] == 0){
                    top_sort[tmp_int] = (char)(i + 65);
                    in_degree[i] = -1;
                    tmp_int ++;
                    tmp = this->vertex[i];
                    while (tmp != nullptr and tmp->next != nullptr){
                        in_degree[tmp->next->name[0] - 65] --;
                        tmp = tmp->next;
                    }
                }
            }
        }
        for(int i = 0;i<this->row;i++){
            if(in_degree[i] != -1){
                cout<<"The graph has a loop and critical path calculations cannot be performed"<<endl;
                throw "The graph has a loop and critical path calculations cannot be performed";
            }
        }
        this->top_sort = top_sort;
        this->_print_top_sort(top_sort, 9);
//        cout<<"Each vertex in degree:\n";
//        for(int i = 0;i<this->row;i++){
//            cout<<(char)(i+65)<<":"<<in_degree[i]<<endl;
//        }
    }
    /**
     * 获取最早发生时间
     */
    int* _get_est(){
        int* ee = new int[9]();
        for(int i = 0;i<this->row;i++){
            Node* tmp = this->vertex[this->top_sort[i][0] - 65];
            Node* tmp_next = tmp->next;
            while (tmp_next != nullptr){
                if(ee[tmp->name[0] - 65] + tmp_next->value > ee[tmp_next->name[0] - 65]){
                    ee[tmp_next->name[0] - 65] = ee[tmp->name[0] - 65] + tmp_next->value;
                }
                tmp_next = tmp_next->next;
            }
        }
        return ee;
    }

    /**
     * 获取最晚发生时间
     */
    int* _get_lst(){
        int* tmp_lst = this->est;
        for(int i = this->row-1; i>-1; i--){
            string tmp = this->top_sort[i];
            for(int j = this->row-1;j>-1;j--){
                Node* tmp_node = this->vertex[j];
                Node* tmp_node_next = tmp_node->next;
                while (tmp_node_next != nullptr){
                    if(tmp_node_next->name == tmp){
                        if(tmp_lst[tmp[0] - 65] - tmp_node_next->value < tmp_lst[tmp_node_next->name[0]-65]){
                            tmp_lst[tmp_node->name[0]-65] = tmp_lst[tmp[0] - 65] - tmp_node_next->value;
                        }
                        break;
                    }
                    tmp_node_next = tmp_node_next->next;
                }
            }
        }
        return tmp_lst;
    }
    void _print_graph(){
        for(int i = 0;i<this->row;i++){
            if(this->vertex[i] != nullptr){
                Node* tmp = this->vertex[i];
                cout<<tmp->name<<":\t";
                while (tmp->next != nullptr){
                    cout<<"("<<tmp->next->name<<":"<<tmp->next->value<<") ";
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }
    }

    void _print_top_sort(string* top, int len){
        for(int i = 0;i<len;i++){
            cout<<top[i]<<" ";
        }
        cout<<endl;
    }

    void _print_est(){
        for(int i = 0;i<this->row;i++){
            cout<<this->top_sort[i]<<"\t";
        }
        cout<<endl;
        for(int i = 0;i<this->row;i++){
            cout<<this->est[i]<<"\t";
        }
        cout<<endl;
    }

    void _print_lst(){
        for(int i = 0;i<this->row;i++){
            cout<<this->top_sort[i]<<"\t";
        }
        cout<<endl;
        for(int i = 0;i<this->row;i++){
            cout<<this->lst[i]<<"\t";
        }
        cout<<endl;
    }

private:
    /**
     * vertex_num:顶点个数
     * 图参考../critical_route.png
     */
    Node* vertex[9];
    string* top_sort;
    int row = 9, col = 9;
    int graph[9][9] = {
            {0, 6, 4, 5, MAX, MAX, MAX, MAX, MAX},
            {MAX, 0, MAX, MAX, 1, MAX, MAX, MAX, MAX},
            {MAX, MAX, 0, MAX, 1, MAX, MAX, MAX, MAX},
            {MAX, MAX, MAX, 0, MAX, 2, MAX, MAX, MAX},
            {MAX, MAX, MAX, MAX, 0, MAX, 5, 7, MAX},
            {MAX, MAX, MAX, MAX, MAX, 0, 4, MAX, MAX},
            {MAX, MAX, MAX, MAX, MAX, MAX, 0, MAX, 4},
            {MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0, 2},
            {MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0},
    };
    string name[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    int* est;//最早发生时间
    int* lst;//最晚发生时间
};
#endif //ALGORITHMUNLOCK_CRITICAL_PATH_H
