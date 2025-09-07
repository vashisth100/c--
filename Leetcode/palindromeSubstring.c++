#include <bits/stdc++.h>
using namespace std;

string palindrome(string s){
    int start = 0, maxLen = 1;

    for(int i=0; i < s.length(); i++){
        int l = i, r = i;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            if(r+l-1 > maxLen){
                maxLen = r+l-1;
                start = l;
            }
            --l;
            ++r;
        }

        l = i; r = i+1;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            if(r+l-1 > maxLen){
                maxLen = r+l-1;
                start = l;
            }
            --l;
            ++r;
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    string s = "abbc";

    cout<<palindrome(s);
    
}