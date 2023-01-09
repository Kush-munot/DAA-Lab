#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w);

    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::greedyColoring()
{
    int result[V];

    result[0] = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++)
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " ---> Color "
             << result[u] << endl;
}

int main()
{
    Graph g1(5);
    g1.addEdge(0, rand() % 4);
    g1.addEdge(0, rand() % 5);
    g1.addEdge(1, rand() % 4);
    g1.addEdge(1, rand() % 5);
    g1.addEdge(2, rand() % 4);
    g1.addEdge(3, rand() % 5);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, rand() % 3);
    g2.addEdge(0, rand() % 5);
    g2.addEdge(1, rand() % 4);
    g2.addEdge(1, rand() % 5);
    g2.addEdge(2, rand() % 4);
    g2.addEdge(4, rand() % 5);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();

    return 0;
}
