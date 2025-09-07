#include <iostream>
using namespace std;

//for descending order change the sign of comparison form ""<"" to "">"".. {vice versa}

//find least element in unsorted array --> swap with first element in unsorted array
//time complexity --> O(n^2) {worst, average, best}
void selection_sort(int arr[], int n){
    for(int i = 0; i<= n-2; i++){
        int min = i;

        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        //swap
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

    }
}

//compare adjacent element find if greater --> swap
//time complexity --> O(n^2) {worst, average}
//                --> O(n) {best}
//space complexity -->O(1)
void bubble_sort(int arr[], int n){
    for(int i = 0; i <= n ; i++){    
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){ // for descending order just change sign of comparison

               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
            }
        }    
    }
}

//picks th element and places it to its right position.
//time complexity --> O(n^2) {worst, average}
//        .->    --> O(n) {best}
//space complexity -->O(1)
void insertion_sort(int arr[], int n){
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]= temp;
            j--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n]; 

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}