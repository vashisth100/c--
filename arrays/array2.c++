#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutive(vector<int> &A){
    int maxi = 0;
    int ctr = 0;

    for(int i = 0; i< A.size(); i++){
        if(A[i] == 1){
            ctr ++;
            maxi = max(maxi, ctr);
        } else {
            ctr = 0;
        }
    }
    return maxi;
}

int main(){
    vector<int> A = {1, 1, 0, 1, 1, 1, 0, 1};

    cout<<findMaxConsecutive(A);
}