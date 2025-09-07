#include <bits/stdc++.h>
using namespace std;

int maxx(int a, int b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    int maximum = maxx(a, b);
    cout<<"value is "<<maximum;

    return 0;
}