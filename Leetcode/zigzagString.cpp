#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows){
    if (numRows == 1) {
            return s;
        }

        std::vector<std::string> rows(numRows, "");
        int currRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0) {
                direction = 1;
            } else if (currRow == numRows - 1) {
                direction = -1;
            }
            currRow += direction;
        }

        std::string result = "";
        for (const auto& row : rows) {
            result += row;
        }

    return result;
}


int main(){
    string s;
    cin>>s;

    cout<<convert("paypalishiring" ,3);

}