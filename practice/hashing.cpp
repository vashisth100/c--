#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int num;
    cin >> num;

    while (num--)
    {
        int a;
        cin >> a;

        cout << hash[a] << endl;
    }
    return 0;
}