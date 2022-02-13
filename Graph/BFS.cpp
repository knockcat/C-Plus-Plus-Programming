// BFS

// Once we visit one vertex we will print all its ajcacent vertices

// print all vertices in particular order
// we have to maintain a list of vertices
// which we have already visited

// int **edge = new int *[n]; // syntax 2 d array dynamically
// int *visited = new int [n]; // syntax 1 d array dynamically

// 0 means no edge 1 means edge

#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, int sv)
{
    queue<int> q;
    bool *visited = new bool[n]; // visited array

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    q.push(sv); // pushing starting vertex to queue
    visited[sv] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop(); // pop current vertex
        cout << curr << endl;

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

    delete[] visited; // free memory
}

/*

// let Graph be

        0
      /   \
     4     5
    /       \
    3        6
   / \         \
  2   1         7

*/

// call will be 0 -> 4 -> 5 -> 3 -> 6 -> 1 -> 2 -> 7

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

    cout << "BFS " << endl;
    printBFS(edges, n, 0); // 0 starting vertex

    // deleting all the memory

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}

/*

OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ BFS.cpp -o BFS } ; if ($?) { .\BFS }

Enter number of vertices & edges :
8 9
Enter edge from first vertex to second vertex
0 4
Enter edge from first vertex to second vertex
0 5
Enter edge from first vertex to second vertex
4 3
Enter edge from first vertex to second vertex
5 6
Enter edge from first vertex to second vertex
3 6
Enter edge from first vertex to second vertex
3 2
Enter edge from first vertex to second vertex
3 1
Enter edge from first vertex to second vertex
6 7
Enter edge from first vertex to second vertex
2 1
BFS
0
4
5
3
6
1
2
7
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>
*/