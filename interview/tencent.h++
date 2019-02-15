//
// Created by wangheng on 2/16/19.
//

#ifndef ALGORITHMUNLOCK_TENCENT_H
#define ALGORITHMUNLOCK_TENCENT_H

#include <iostream>
using namespace std;

class Tencent{
public:
    Tencent() = default;
    ~Tencent() = default;

    void print_matrix(){
        /**
         * 3    4   5   6
         * 4    5   9   8
         * 8    9   0   3
         * 2    5   7   4
         *
         * print: 3 4 5 6 8 3 4 7 5 2 8 4 5 9 0 9
         */
        int rows = 5;
        int cols = 5;
        int mat[rows][cols] = {
                {3,4,5,6,5},
                {4,5,9,8,3},
                {8,9,0,3,2},
                {2,5,7,4,5},
                {3,4,2,1,9}
        };
        cout<<"your input matrix is:\n";
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                cout<<mat[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<endl;

        int start_row = 0;
        int end_row = rows-1;
        int start_col = 0;
        int end_col = cols-1;

        while (start_row <= end_row){
            for(int j = start_col;j<=end_col;j++){
                cout<<mat[start_row][j]<<" ";
            }
            for(int i = start_row+1;i<=end_row;i++){
                cout<<mat[i][end_col]<<" ";
            }
            for(int i = end_col-1;i>=start_col;i--){
                cout<<mat[end_row][i]<<" ";
            }
            for(int i = end_row-1;i>start_row;i--){
                cout<<mat[i][start_col]<<" ";
            }
            start_col ++;
            start_row ++;
            end_row --;
            end_col --;
        }
        cout<<endl;
    }
};
#endif //ALGORITHMUNLOCK_TENCENT_H
