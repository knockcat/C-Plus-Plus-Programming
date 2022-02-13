// bfs & dfs for disconnected graph

/*

// let Graph be

        0                                        12
      /   \                                        \
     4     5                 8                     13
    /       \               / \
    3        6             9   10
   / \         \          /
  2   1         7        11

// call will be DFS 0 -> 4 -> 3 -> 1 -> 2 -> 5 -> 6 -> 7 -> 8 -> 9 -> 11 -> 10 -> 12 -> 13
// call will be BFS 0 -> 4 -> 5 -> 3 -> 6 -> 1 -> 2 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13

*/

#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; ++i)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited); // recursive call
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }

    delete[] visited;
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;

    q.push(sv); // pushing starting vertex to queue
    visited[sv] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop(); // pop current vertex
        cout << curr << " ";

        for (int i = 0; i < n; ++i)
        {
            if (i == curr)
                continue;
            if (edges[curr][i] == 1 && !visited[i]) // all adjacent vertices of curr && not visited
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
}

int main()
{
    // KNOCKCAT \\

    int n, e; // vertex and edges

    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need to create a 2d array
    int **edges = new int *[n]; // dynamically

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; ++i)
    {
        int f, s; // first vertex second vertex
        cout << "Enter edge from first vertex to second vertex " << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "DFS" << endl;

    DFS(edges, n);

    cout << endl;

    cout << "BFS" << endl;

    BFS(edges, n);

    // deleting memory
    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}