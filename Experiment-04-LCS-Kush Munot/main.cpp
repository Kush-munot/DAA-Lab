#include <bits/stdc++.h>
using namespace std;

void findAnswer(vector<vector<int>> dir, vector<vector<int>> arr, string str1,
                string str2)
{
    string ans;
    int i = str1.size(), j = str2.size();
    int x = 50;

    while (x--)
    {
        if (i == 0 || j == 0)
            break;
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        else if (dir[i][j] == 2)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

void printMat(vector<vector<int>> mat)
{
    for (auto i : mat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int longestCommonSubseq(string str1, string str2, int m, int n,
                        vector<vector<int>> arr, vector<vector<int>> dir)
{

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                dir[i][j] = 3;
            }
            else if (arr[i - 1][j] >= arr[i][j - 1])
            {
                arr[i][j] = arr[i - 1][j];
                dir[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i][j - 1];
                dir[i][j] = 2;
            }
        }
    }
    printMat(arr);
    cout << "\nDirection Matrix" << endl;
    printMat(dir);

    findAnswer(dir, arr, str1, str2);
    return 0;
}

int main()
{
    string str1 = "AGCCCTAAGGGCTACCTAGCTT", str2 = "GACAGCCTACAAGCGTTAGCTTG";
    int m = str1.size(), n = str2.size();
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dir(m + 1, vector<int>(n + 1, 0));
    /*1 for up
      2 for left
      3 for diagonal*/
    longestCommonSubseq(str1, str2, m, n, arr, dir);
}