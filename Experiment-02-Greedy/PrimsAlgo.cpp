#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[V], bool mstSet[V])
{
    int min = INT_MAX, minInd;
    for (int i = 0; i < V; i++)
    {
        if (key[i] < min && mstSet[i] == false)
        {
            min = key[i];
            minInd = i;
        }
    }
    return minInd;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primsAlgo(int graph[V][V])
{
    bool mstSet[V];
    int key[V], parent[V];

    for (int i = 1; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < V - 1; c++)
    {
        int m = minKey(key, mstSet);
        mstSet[m] = true;

        for (int n = 0; n < V; n++)
        {
            if (graph[m][n] != 0 && graph[m][n] < key[n] && mstSet[n] == false)
            {
                parent[n] = m;
                key[n] = graph[m][n];
            }
        }
        printMST(parent, graph);
    }
}

int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primsAlgo(graph);

    /*
    A - 2 99 6 99
    B - - 99 6 99
  */
}