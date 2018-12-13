//
// Created by wangheng on 2018-12-13.
//

#ifndef ALGORITHMUNLOCK_HEAP_H
#define ALGORITHMUNLOCK_HEAP_H
#include <iostream>

using namespace std;

template <class T>
class Heap{
public:
    int max_size;
    int heap_length;
    T* heap;

    Heap(int max_size){
        this->max_size = max_size;
        this->heap = new T[max_size];
        this->heap_length = 0;
    }
    ~Heap() = default;

    void push(T data){
        this->heap[this->heap_length] = data;
        this->heap_length ++;
        if(this->heap_length >= this->max_size){
            this->max_size = this->max_size * 2;
            T* tmp_heap = new T[this->max_size];

            for (int i = 0;i<this->max_size / 2;i++){
                tmp_heap[i] = this->heap[i];
            }
            this->heap = tmp_heap;
        }
        int tmp_node_index = (this->heap_length - 1);
        while (tmp_node_index >0) {
            if (this->heap[tmp_node_index] < this->heap[(tmp_node_index - 1) / 2]) {
                T tmp = this->heap[tmp_node_index];
                this->heap[tmp_node_index] = this->heap[(tmp_node_index - 1) / 2];
                this->heap[(tmp_node_index - 1) / 2] = tmp;
                tmp_node_index = (tmp_node_index - 1) / 2;
            } else {
                break;
            }
        }
    }

    T pop(){
        if(this->heap_length ==0){
            cerr<<"Empty heap exception!"<<endl;
            throw "Empty heap exception!";
        } else{
            T tmp_data = this->heap[0];
            this->heap[0] = this->heap[this->heap_length - 1];
            this->heap_length --;
            int tmp_index = 0;
            while (tmp_index < this->heap_length){
                int left_index = 2 * tmp_index + 1;
                int right_index = 2 * tmp_index + 2;
                if (right_index < this->heap_length){
                    if(this->heap[tmp_index] > this->heap[left_index] and this->heap[tmp_index] > this->heap[right_index]){
                        if(this->heap[left_index] > this->heap[right_index]){
                            this->swap_data(this->heap, tmp_index, right_index);
                            tmp_index = right_index;
                        }else{
                            this->swap_data(this->heap, tmp_index, left_index);
                            tmp_index =left_index;
                        }
                    }else if(this->heap[tmp_index] > this->heap[left_index]){
                        this->swap_data(this->heap, tmp_index, left_index);
                        tmp_index = left_index;
                    }else if(this->heap[tmp_index] > this->heap[right_index]){
                        this->swap_data(this->heap, tmp_index, right_index);
                        tmp_index = right_index;
                    } else{
                        break;
                    }
                }else if(left_index < this->heap_length){
                    if(this->heap[tmp_index] > this->heap[left_index]){
                        this->swap_data(this->heap, tmp_index, left_index);
                        tmp_index = left_index;
                    } else{
                        break;
                    }
                } else{
                    break;
                }
            }
            return tmp_data;
        }
    }

    void print_heap(){
        for (int i = 0;i<this->heap_length;i++){
            cout<<this->heap[i]<<"\t";
        }
        cout<<endl;
    }

    void swap_data(T* heap, int i, int j){
        try {
            T tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
        }catch (char* str){
            cerr<<str<<endl;
        }

    }
};

#endif //ALGORITHMUNLOCK_HEAP_H
