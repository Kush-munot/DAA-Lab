#include <bits/stdc++.h>
using namespace std;

vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int mini, maxi, mid, min1, max1;

void max_min(int i, int j)
{
    if (i == j)
    {
        mini = arr[i];
        maxi = arr[i];
    }
    else if (i == j - 1)
    {
        mini = min(arr[i], arr[j]);
        maxi = max(arr[i], arr[j]);
    }
    else
    {
        int mid = (i + j) / 2;
        max_min(i, mid);
        min1 = mini;
        max1 = maxi;
        max_min(mid + 1, j);
        mini = min(mini, min1);
        maxi = max(maxi, max1);
    }
}

int main()
{
    max_min(0, 9);
    cout << "Minimum is - " << mini << " and Maximum is " << maxi << endl;
}