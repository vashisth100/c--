#include <iostream>
#include <vector>
using namespace std;

//Time Complexity : BestCase(key is middle): O(1)
//                : Worst Case: O(log n) → Array divided in half repeatedly
//                : Average Case: O(log n)
//Space Complexity: Iterative: O(1)
// Recursive: O(log n) → Due to recursion stack
int binary_search(vector<int> arr, int n){
    
    int st = 0;
    int end = arr.size()-1;
    
    while(st <= end){
        int mid = (st + end)/2;
        if(arr[mid] > n){
            end = mid-1;
        } else if(arr[mid] < n) {
            st = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//Time Complexity: Best case: O(1), Worst case: O(n), Average case: O(n)
int linear_search(vector<int> arr, int n){
    for(int i = 0; i < arr.size(); i++){
        if(n == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {12, 15, 16, 23, 25, 29, 33, 36};
    int n = 36;

    cout<<linear_search(arr, n);
}