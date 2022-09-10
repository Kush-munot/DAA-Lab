#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int parts(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void QuickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int q = parts(arr, l, h);
        QuickSort(arr, l, q - 1);
        QuickSort(arr, q + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements - " << endl;
    cin >> n;
    int arr[n];
    cout << "Input Array Elements - " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    QuickSort(arr, low, high);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}