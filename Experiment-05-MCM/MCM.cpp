#include <bits/stdc++.h>
using namespace std;
vector<int> p = {2, 3, 5, 4, 6};
int n = p.size() - 1;
vector<vector<int>> arr(n, vector<int>(n, 0));
vector<vector<int>> s(n, vector<int>(n, 0));

void Print(int i, int j)
{
    if (i == j)
    {
        cout << "A" << i << " ";
    }
    else
    {
        cout << " ( ";
        Print(i, s[i][j]);
        Print(s[i][j] + 1, j);
        cout << " ) ";
    }
}

void Display()
{
    for (auto i : s)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void MCM()
{
    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n - l; i++)
        {
            int j = i + l;
            arr[i][j] = 99999;
            for (int k = i; k <= j - 1; k++)
            {
                int q = arr[i][k] + arr[k + 1][j] + (p[i] * p[k + 1] * p[j + 1]);
                if (q < arr[i][j])
                {
                    arr[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{

    MCM();
    Display();
    Print(0, n - 1);
}

// i = j then a1
// else