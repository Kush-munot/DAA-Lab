#include <bits/stdc++.h>
using namespace std;
#define n 7
int C, Wt = 0;
int P[n], W[n];
float x[n], ans;

bool sortbysec(const pair<int, float> &a, const pair<int, float> &b)
{
    return (a.second > b.second);
}

void FractionalKnapsack()
{
    vector<pair<int, float>> ratio;
    cout << "Printing The Sorted Verion" << endl;
    for (int i = 0; i < n; i++)
    {
        ratio.push_back(make_pair(i, ((float)P[i] / W[i])));
    }

    sort(ratio.begin(), ratio.end(), sortbysec);
    for (int i = 0; i < n; i++)
    {
        cout << ratio[i].first << " " << ratio[i].second << endl;
    }
    int i = 0;

    while (Wt < C)
    {
        if ((W[ratio[i].first] + Wt) < C)
        {
            x[ratio[i].first] = 1;
            Wt += W[ratio[i].first];
        }
        else
        {
            x[ratio[i].first] = (C - Wt) / (float)W[ratio[i].first];
            Wt = C;
        }
        i++;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << "x[i] = " << x[i] << endl;
        ans += P[i] * x[i];
    }
}

int main()
{
    cout << "Enter the Bag capacity : ";
    cin >> C;

    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    cout << "Enter the profits amount" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    cout << "Enter the weights amount" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    FractionalKnapsack();

    cout << ans << endl;
}