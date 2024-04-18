#include <iostream>
#include <vector>
using namespace std;

/// @brief prints the elements in the array and their memory locations
/// @param v - vetor of integers

void printMemVec( const vector<int> &v){
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i = 0; i < v.size(); i++){
        printf("Value :%i at Memory Location: %p\n", v[i], &v + i);
    }
}

/// @brief increments all of the elements in the arr by 10
/// @param v - vector of integers

void incVecBy10(vector<int> & v) { //void incArrBy10(int arr[], int size)
    for(int i = 0; i < v.size(); i++){
        v[i] += 10;
    }
}

int main(){
    const int SIZE = 5;
    vector<int> vec;
  
    for(int i=0; i<SIZE; i++){
        vec.push_back(100+i);

    }
    printf("Before-----------\n");
    printMemVec(vec);
    incVecBy10(vec);
    printf("After-----------\n");
    printMemVec(vec);
    return 0; 
}