#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n)
{
    int large = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    return large;
}

int secondLargest(int arr[], int n)
{
    int large = arr[0], sLarge = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            sLarge = large;
            large = arr[i];
        }
        else if (arr[i] < large && arr[i] > sLarge)
        {
            sLarge = arr[i];
        }
    }
    return sLarge;
}

int secondSmallest(int arr[], int n)
{
    int smallest = arr[0], secondSmall = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmall = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < secondSmall)
        {
            secondSmall = arr[i];
        }
    }
    return secondSmall;
}

bool isSorted(int arr[], int n)
{
    bool isSort = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            isSort = true;
        }
        else
        {
            isSort = false;
            break;
        }
    }
    return isSort;
}

void removeDuplicates(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            continue;
        }
        else
            cout << arr[i - 1] << " ";
    }
}

void rotateArray1(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void rotateArrayByD(int arr[], int n, int d)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

void moveZeroToEnd(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

vector<int> intersectionArray(vector<int> &A, int n, vector<int> &B, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            return;
        }
        else if (A[i] > B[j])
        {
            return;
        }
        else
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

vector<int> unionArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != A[i])
            {
                unionArr.push_back(A[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != B[j])
            {
                unionArr.push_back(B[j]);
            }
            j++;
        }
    }

    while (j < m)
    {
        if (unionArr.size() == 0 || unionArr.back() != B[j])
        {
            unionArr.push_back(B[j]);
        }
        j++;
    }

    while (i < n)
    {
        if (unionArr.size() == 0 || unionArr.back() != A[i])
        {
            unionArr.push_back(A[i]);
        }
        i++;
    }
    return unionArr;
}

int missingNum(int arr[], int n){
    int sum = (n*(n+1))/2;

    int s2;
    for(int i = 0; i < n-1; i++){
        s2 += arr[i];
    }
    return sum-s2;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int d;
    // cin >> d;

    missingNum(arr, n);
    printArray(arr, n);
}