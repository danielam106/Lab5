#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

/// @brief returns the fist index of elem if it exists, otherwise returns -1
///iterativeSearch starts at the first index and iterates sequentially to the next until it either
///finds the element or until it reaches the end (i.e. element does not exist)
/// @param v : vector of elements
/// @param elem : integer to look for
/// @return int
int iterativeSearch(const vector<int>&v, int elem){
    //use a for loop where the index, i goes from 0 to the size of v
    for(int i=0;i<v.size();i++){
    //inside the for loop, use an if statement to check whether the element at 1 (e.g. v[i]) equals elem
    if(v[i]==elem){
        return i;
    }
    
    //inside the if statement return i
    }
    //outside of the for loop return -1
    return -1;
}

/// @brief returns the index of elem, if it exists in v. Otherwise it returns -1
///binarySearch is recursive (i.e. function calls itself).
///It utilizes the fact that v is increasing order (e.g. values go up and
///duplicates are not allowed)
///
/// It calculates the mid from the start and end index. It compares v[mid] (i.e. value
///at mid) with elem and decides whether to search the left half (lower values)
///or right half (upper values)
/// @param v : vector of elements
/// @param start : leftmost index (starting value is 0)
/// @param end : rightmost index (starting value is v.size())
/// @param elem : integer to look for
/// @return int

int binarySearch(vector<int> & v, int start, int end, int elem){
    //write an if statement that checks the terminating case
    //inside the if statement return -1
    if(start>end){
        return -1;
    }
    //instantiate the midpoint
    int mid = (start+end)/2;
    //Use if/else statements to do the following
    //1) update end (search left half)
    if(v[mid]>elem){
        end = mid - 1;
    }
    //2) update start (search right half)
    else if(v[mid]<elem){
        start = mid + 1;
    }

    //3)return mid (found the elem)
    else{
        return mid; 
    }
    //return a recursive call to binarySearch
    return binarySearch(v, start, end, elem);
}

void vecGen( const string &filename, vector<int> &v){
    ifstream file(filename);
    v.clear();
    int num;
    while (file.is_open() && file >> num){
        v.push_back(num);
    } 
    file.close();
}

int main(){
    //populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    //test elemets to search for (leave as is)
    vector<int> elem_to_find; 
    vecGen("test_elem.csv", elem_to_find);

    //reads through all 10 of the test_elem values and calls iterative search
    //and records how long each search took (leave as is)
    for(int i=0; i<elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        //stopwatches the tome
        auto start = chrono::high_resolution_clock::now();
        int index_if_found = iterativeSearch(v, elem);
        auto end = chrono::high_resolution_clock::now();

        //calculates the total time itt took in seconds
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        //PRINTS THE INDEX AND HOW LONG IT TOOK TO FIND IT
        cout << index_if_found << ": " << duration.count() <<"microseconds"<< endl;

    }

    //repeat the for loop above sp that it records the time
    //it takes for binarySearch to do the same operation
    for(int i=0; i<elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        //stopwatches the tome
        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(v, 0, v.size()-1, elem);
        auto end = chrono::high_resolution_clock::now();

        //calculates the total time itt took in seconds
         auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        //PRINTS THE INDEX AND HOW LONG IT TOOK TO FIND IT
        cout << index_if_found << ": " << duration.count()<< "microseconds" << endl;

    }
    return 0;
}