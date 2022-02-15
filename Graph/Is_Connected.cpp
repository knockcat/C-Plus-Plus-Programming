// Is Graph Connected Or Not

#include <iostream>
using namespace std;

void IsConnnected(int **edges, int n, int sv, bool *visited)
{
    if (n == 1)
    {
        visited[sv] = 1;
        return;
    }

    visited[sv] = 1;

    for (int i = 0; i < n; ++i)
    {
        if (edges[sv][i] == 1 && !visited[i])
            IsConnnected(edges, n, i, visited);
    }
    return;
}

int main()
{

    // KNOCKCAT \\

    int n;
    int e;

    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need to create a 2 d array n * n

    int **edges = new int *[n]; // dynamic array for storing edges

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; ++i) // e edges
    {
        int f, s; // first vertex second vertex
        cout << "Enter edge from first vertex to second vertex " << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n]; // visited array

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    IsConnnected(edges, n, 0, visited);

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            cout << "Graph is Not Connected" << endl;
            goto del;
        }
    }

    cout << "Graph Connected" << endl;

    // deleting all the memory

del:
    delete[] visited;

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}

/*
OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Is_Connected.cpp -o Is_Connected } ; if ($?) { .\Is_Connected }
Enter number of vertices & edges :
4 4
Enter edge from first vertex to second vertex
0 1
Enter edge from first vertex to second vertex
0 3
Enter edge from first vertex to second vertex
1 2
Enter edge from first vertex to second vertex
2 3
Graph Connected
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Is_Connected.cpp -o Is_Connected } ; if ($?) { .\Is_Connected }
Enter number of vertices & edges :
4 3
Enter edge from first vertex to second vertex
0 1
Enter edge from first vertex to second vertex
1 3
Enter edge from first vertex to second vertex
0 3
Graph is Not Connected
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>

*/