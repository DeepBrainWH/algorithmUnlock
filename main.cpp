#include <iostream>
#include "SearchAlgorithm.h"
#include "SortAlgorithm.h"
#include "Utils.h"

using namespace std;

void test_search_function(){
    auto * algorithm = new SearchAlgorithm();
    int *a = algorithm->get_sort_rand(10);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    int index = algorithm->binary_search_no_recursive(a, 10, a[6]);
    cout<<"the value "<<a[6]<<" 's position in "<<index<<endl;

    int index2 = algorithm->binary_search_recursive(a, 0, 10, a[9]);
    cout<<index2<<endl;
}

void test_sort(){
    auto* sortAlgorithm = new SortAlgorithm<int>();
    int* a = utils::get_unsort_range(20);
    for(int i = 0;i<20;i++){
        cout<<a[i]<<"  ";
    }
    cout<<"\n"<<"====================="<<endl;
    sortAlgorithm->selectSort(a, 20);
    for(int i = 0;i<20;i++){
        cout<<a[i]<<"  ";
    }
}

void test_quick_sort(){
    auto* sort = new SortAlgorithm<int>();
    int* list = utils::get_unsort_range(100);
    sort->quick_sort(list, 0, 99);
    for(int i = 0;i<100;i++){
        cout<<list[i]<<"\t";
    }
    cout<<endl;
}




int main() {
//    test_search_function();
//    test_sort();
    test_quick_sort();
    return 0;

}