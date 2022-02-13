// DFS

// Once we go in one direction will be go in depth till the point we can go then come back recursively  if no path

// print all vertices in particular order
// we have to maintain a list of vertices
// which we have already visited

// int **edge = new int *[n]; // syntax 2 d array dynamically
// int *visited = new int [n]; // syntax 1 d array dynamically

// 0 means no edge 1 means edge

#include <iostream>
using namespace std;

void print(int **edges, int n, int sv, bool *visited) // starting vertex
{
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; ++i)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            print(edges, n, i, visited); // recursive call
        }
    }
}
/*

// let Graph be

        0
      /   \
     1     2
    /     / \
    5     3  6
     \   /
       4

*/

// call will be 0 -> 1 -> 5 -> 4 -> 3 -> 2 -> 6

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

    cout << "Vertices are " << endl;
    print(edges, n, 0, visited); // also give starting vertex 0 call on 1 , 1 call on 2 and so on

    // deleting all the memory

    delete[] visited;

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}

/*

OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Graph.cpp -o Graph } ; if ($?) { .\Graph }
Enter number of vertices & edges :
7 6
Enter edge from first vertex to second vertex
0 1
Enter edge from first vertex to second vertex
1 5
Enter edge from first vertex to second vertex
5 4
Enter edge from first vertex to second vertex
4 3
Enter edge from first vertex to second vertex
3 2
Enter edge from first vertex to second vertex
2 6
Vertices are
0
1
5
4
3
2
6
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>

*/