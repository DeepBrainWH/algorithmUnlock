#include <iostream>
#include "SearchAlgorithm.h"

using namespace std;
int main() {
    auto * algorithm = new SearchAlgorithm();
    int *a = algorithm->get_sort_rand(10);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    int index = algorithm->binary_search_no_recorsive(a, 10, a[6]);
    cout<<"the value "<<a[6]<<" 's position in "<<index<<endl;

    int index2 = algorithm->binary_search_recursive(a, 0, 10, a[9]);
    cout<<index2<<endl;
    return 0;
}