#include <bits/stdc++.h>
using namespace std;

void extract(int num)
{
    int count = 0;
    while (num > 0)
    {
        int lastDig = num % 10;
        count++;
        num = num / 10;
    }
    cout << count;
}

void reverse(int num)
{
    int digit;
    while (num > 0)
    {
        digit = num % 10;
        cout << digit;
        num = num / 10;
    }
}

void palindrome(int num)
{
    int original = num;
    int digit;
    int reverse = 0;
    while (num > 0)
    {
        digit = num % 10;
        num = num / 10;
        reverse = (reverse * 10) + digit;
    }
    cout << reverse << endl;

    if (reverse == original)
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }
}

void angstNum(int num)
{
    int original = num;
    int angstrom = 0;
    while (num > 0)
    {
        int digit = num % 10;
        num = num / 10;
        double cube = pow(digit, 3);
        angstrom += cube;
    }
    if (original == angstrom)
    {
        cout << "it is angstrom number";
    }
    else
    {
        cout<<"not a angstrom number";
    }
}

void printDivisor(int num){
    for(int i = 2; i*i < num; i++){
        if(num % i == 0){
            cout<<i<<" ";
        }
    }
}

void prime(int num){

    bool isPrime = true;
    for(int i = 2; i*i < num; i++){
        if(num % i == 0){
            isPrime = false;
        }
    }
    if(isPrime){
        cout<<num<<" is prime";
    } else {
        cout<<"not prime";
    }
}

void gcd(int a, int b){
    int gcd = 1;
    for(int i = 1; i <= min(a,b); i++){
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }
    cout<<gcd;
}

void gcd2(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        } else {
            b=b%a;
        }
    }
        if(a==0){
            cout<<b;
        } else {
            cout<<a;
        }
}

int main()
{
    int n;
    cin >> n;
    int b;
    cin>>b;

    gcd2(n, b);

    return 0;
}