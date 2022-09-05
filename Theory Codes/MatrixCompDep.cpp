#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100][100][100];
    int i = 0;
    for (int j = 0; j < 100; j++)
    {
        for (int k = 0; k < 100; k++)
        {
            arr[i][j][k] = (rand() % 9) + 1;
        }
    }

    int x = 99;
    for (int i = 1; i < 100; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < x; k++)
            {
                arr[i][j][k] = arr[0][j][k];
            }
        }
        x -= 1;
    }

    cout << "Please enter the Compression or Expansion number. If you want to exit give input as -1." << endl;
    cout << "PRINTNG THE MATRIX" << endl;

    int pos = 90;
    while (pos != -1)
    {
        i = pos;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                if (arr[i][j][k] != 0)
                    cout << arr[i][j][k] << " ";
                else
                    continue;
            }
            cout << endl;
        }
        cout << endl;
        cin >> pos;
    }
}