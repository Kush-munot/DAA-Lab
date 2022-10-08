#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int i, int j, int num)
{
    if (i > j)
    {
        return -1;
    }
    else
    {
        int mid = (i + j) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] > num)
        {
            return binarySearch(arr, 0, mid - 1, num);
        }
        else
        {
            return binarySearch(arr, mid + 1, j, num);
        }
    }
}

int main()
{
    vector<int> arr{111, 12, 63, 24, 45, 26, 57, 28, 39, 0};
    sort(arr.begin(), arr.end());

    cout << "Enter the number to be searched" << endl;
    int x;
    cin >> x;

    cout << "Sorted Array is : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int ans = binarySearch(arr, 0, 9, x);

    cout << "The element is present at index " << ans << " in sorted order" << endl;
}