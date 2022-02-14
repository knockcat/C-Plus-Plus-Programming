// Has Path

#include <iostream>
#include <queue>
using namespace std;

bool Has_path(int **edges, int n, int v1, int v2, bool *visited)
{
    if (edges[v1][v2] == 1)
        return true;

    queue<int> q;
    q.push(v1); // pushing starting vertex to queue

    visited[v1] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop(); // pop current vertex

        for (int i = 0; i < n; ++i)
        {
            if (edges[curr][i] == 1 && !visited[i]) // all adjacent vertices of curr && not visited
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    if (visited[v2] == true)
        return true;
    else
        return false;
}

int main()
{
    int n, e;
    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need to create a 2d array of n*n

    int **edges = new int *[n]; // dynamically

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; ++i)
    {
        int f, s; // first vertex second vertex
        cout << "Enter edge from first vetex to second vertex " << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n]; // visited array

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    int u, v;
    cout << "Enter vertices v1 and v2 for path exist or not " << endl;
    cin >> u >> v;

    if (Has_path(edges, n, u, v, visited))
        cout << "\nThere is a path from " << u << " to " << v;
    else
        cout << "\nThere is no path from " << u << " to " << v;

    // deleting memory
    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    delete[] visited;

    return 0;
}

/*

OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Has_path.cpp -o Has_path } ; if ($?) { .\Has_path }
Enter number of vertices & edges :
4 4
Enter edge from first vetex to second vertex
0 1
Enter edge from first vetex to second vertex
0 3
Enter edge from first vetex to second vertex
1 2
Enter edge from first vetex to second vertex
2 3
Enter vertices v1 and v2 for path exist or not
1 3

There is a path from 1 to 3
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Has_path.cpp -o Has_path } ; if ($?) { .\Has_path }
Enter number of vertices & edges :
6 3
Enter edge from first vetex to second vertex
5 3
Enter edge from first vetex to second vertex
0 1
Enter edge from first vetex to second vertex
3 4
Enter vertices v1 and v2 for path exist or not
0 3

There is no path from 0 to 3
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>

*/