#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n){
    int large = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > large){
            large = arr[i];
        }
    }
    return large;
}

int secondLargest(int arr[], int n){
    int large = arr[0], sLarge = -1;

    for(int i= 0; i < n; i++){
        if(arr[i] > large){
            sLarge = large;
            large = arr[i];
        } else if(arr[i] < large && arr[i] > sLarge){
            sLarge = arr[i];
        }
    }
    return sLarge;
}

int secondSmallest(int arr[], int n){
    int smallest = arr[0], secondSmall = INT_MAX;
    for(int i =0; i< n; i++){
        if(arr[i] < smallest){
            secondSmall = smallest;
            smallest = arr[i];
        } else if(arr[i] > smallest && arr[i] < secondSmall){
            secondSmall = arr[i];
        }
    }
    return secondSmall; 
}

bool isSorted(int arr[], int n){
    bool isSort = true;
    for(int i = 0; i < n-1; i++){
        if(arr[i] <= arr[i + 1]){
            isSort = true;
        } else {
            isSort = false;
            break;
        }
    }
    return isSort;
}

void removeDuplicates(int arr[], int n){
    for(int i = 1; i<= n; i++){
        if(arr[i] == arr[i-1]){
            continue;
        } else cout<<arr[i-1]<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    removeDuplicates(arr, n);
}