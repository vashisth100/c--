#include <iostream>
using namespace std;

void print(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void print1(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 5; j >= i; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print2(int n){
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void print3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = i; j < n; j++){
            cout<<" ";
        }
        for(int k = 0; k < (2*i-1); k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print4(int n){
    for(int i = n; i >= 1; i--){
        for(int j = i; j < n; j++){
            cout<<" ";
        }
        for(int k = 0; k < (2*i-1); k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = i; j < n; j++){
            cout<<" ";
        }
        for(int k = 0; k < (2*i-1); k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = n; i >= 1; i--){
        for(int j = i; j < n; j++){
            cout<<" ";
        }
        for(int k = 0; k < (2*i-1); k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = n-1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print7(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if((i+j)%2 == 0){
                cout<<"1 ";
            } else {
                cout<<"0 ";
            }        
        }
        cout<<endl;
    }
}

void print8(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<< j;
        }      
        for(int k = 1; k <= 2*(n-i); k++){
            cout<< " ";
        }
        for(int j = i; j >= 1; j--){
            cout<< j;
        }
        cout<<endl;
    }
}

void print9(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i ; j++){
            sum += 1;
            cout<<sum<<" ";
        }      
        cout<<endl;
    }
}

void print10(int n){
    for(int i = 0; i < n; i++){
        for(char ch ='A'; ch <= 'A'+i; ch++){
            cout<< ch << " ";
        }      
        cout<<endl;
    }
}

void print11(int n){
    for(int i = 0; i < n; i++){
        for(char ch ='A'; ch <= 'A'+i; ch++){
            char sum = 'A'+i;
            cout<< sum << " ";
        }      
        cout<<endl;
    }
}

void print12(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n-i-1); j++){
            cout<<" ";
        }
        char ch = 'A';
        int breakdown = (2*i+1)/2;
        for(int j = 1; j<= 2*i+1; j++){
            cout<< ch;
            if(j <= breakdown) ch++;
            else ch--;
        }
        cout<<endl;
    }             
}

void print13(int n){
    for(int i = 0; i < n; i++){
        for(char ch ='E'-i; ch <= 'E'; ch++){
            cout<< ch << " ";
        }      
        cout<<endl;
    }
}

void print14(int n){
    for(int i = 1; i <= n; i++){
        for(int j =i; j<= n ; j++){
            cout<<"*";
        }    
        for(int k = 1; k <= 2*(i-1); k++){
            cout<<" ";
        } 
        for(int j =i; j<= n ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = n; i >= 1; i--){
        for(int j =i; j<= n ; j++){
            cout<<"*";
        }    
        for(int k = 1; k <= 2*(i-1); k++){
            cout<<" ";
        } 
        for(int j =i; j<= n ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}

void print15(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i ; j++){
            cout<<"*";
        }
        for(int k = i; k < n; k++){
            cout<<" ";
        } 
        for(int k = i; k < n; k++){
            cout<<" ";
        } 
        for(int j = 1; j <= i ; j++){
            cout<<"*";
        }  
        cout<<endl;
    }
    for(int i = n-1; i >= 1; i--){
        for(int j = 1; j <= i ; j++){
            cout<<"*";
        }
        for(int k = i; k < n; k++){
            cout<<" ";
        } 
        for(int k = i; k < n; k++){
            cout<<" ";
        } 
        for(int j = 1; j <= i ; j++){
            cout<<"*";
        }  
        cout<<endl;
    }
}

void print16(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-1; j++){
            if(i == 1 || i == n || j == 1 || j == n-1){
                cout<<"*";
            } else{
                cout<<" ";
            }
        }
        
        cout<<endl;
    }
}

void print17(int n){
    for(int i = 0; i < (2*n-1); i++){
        for(int j = 0; j < (2*n-1); j++){
            int top = i;
            int left = j;
            int right = (2*n - 2) - j;
            int bottom = (2*n - 2) - i;

            cout<<(n- min(min(top,bottom), min(left,right)));
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    print17(n);
}