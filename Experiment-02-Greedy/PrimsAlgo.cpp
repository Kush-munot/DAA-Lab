#include <bits/stdc++.h>
using namespace std;
#define V 6

int minKey(int key[V], bool mstSet[V]) //* Find Minimum Index Key
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

void printMST(int parent[], double graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primsAlgo(double graph[V][V])
{
    bool mstSet[V]; //* To Check if Node is Visited or not
    int key[V];     //* Key is used to find current minimum key
    int parent[V];  //* Parent is used to store Minimum Spanning Tree Order

    for (int i = 1; i < V; i++) //* setting initially the Key[i] as Infinity and Visited[i] = false
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; //* First Node is Source
    parent[0] = -1;

    for (int c = 0; c < V - 1; c++)
    {
        int m = minKey(key, mstSet); //* Finding Minimum Key
        mstSet[m] = true;            //* Visited is set true for specific minimum key

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
    double graph[V][V] = {
        {0, 427.50202366902516, 385.2763086761522, 351.6311760175055, 419.1135964192494},
        {427.50202366902516, 0, 74.550293671268, 87.48224082988976, 9.979747789152853},
        {385.2763086761522, 74.550293671268, 0, 102.55989455322387, 74.1264796790887},
        {351.6311760175055,87.48224082988976, 102.55989455322387, 0, 77.55690666294466},
        {419.1135964192494, 9.979747789152853, 74.1264796790887,77.55690666294466, 0}};
    primsAlgo(graph);
}