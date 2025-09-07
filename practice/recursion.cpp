#include <bits/stdc++.h>
using namespace std;

void name(int i, int n)
{
    if (i > n)
    return;
    
    cout << "priyanshu" << endl;
    n--;
    name(i, n);
}

void printNum(int i, int n){
    if(i > n)
    return;

    cout<<i<<endl;
    i++;
    printNum(i, n);
}

void reverseNum(int i, int n){
    if(i > n)
    return;

    cout<<n<<endl;
    n--;
    reverseNum(i,n);
}

void backTrack(int i, int n){
    if( i  > n)
    return;

    backTrack(i+1, n);
    cout<<i<<endl;
}

void SumOfN(int i, int sum){
    if(i < 1){
        cout<<sum;
        return;
    }
    SumOfN(i-1, sum + i);
}

int sumFn(int i){
    if(i == 0){
        return 0;
    }
    return i + sumFn(i-1);
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

bool palindrome(int i, string n){
    if(i >= n.length()/2){
        return true;
    }
    if(n[i] != n[n.length()-i-1]){
        return false;
    }
    return palindrome(i+1, n);

}

void reverseArr(int i, int n, int arr[]){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);

    reverseArr(i+1,n,arr);
}

void fibonacci(int a, int b, int n){

    if(n == 0){
        return;
    }

    int c = a + b; 
    cout<<c<<" ";
    fibonacci(b, c, n-1);
    
}

int fibElement(int n){
    if(n <= 1){
        return n;
    }
    return fibElement(n-1) + fibElement(n-2);
}

int main()
{

    int n;
    cin>>n;
    
    cout<<fibElement(n);
}