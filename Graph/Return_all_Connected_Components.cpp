// Return All Connected Connected_Components

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int **edges, bool *visited, int n, vector<int> &ans, int start)
{
    visited[start] = true;
    ans.push_back(start);

    for (int i = 0; i < n; ++i)
    {
        if (edges[start][i] == 1 && !visited[i])
            DFS(edges, visited, n, ans, i);
    }
}

void Connected_Components(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            // this vector creating againg and again
            vector<int> ans;

            DFS(edges, visited, n, ans, i);
            sort(ans.begin(), ans.end());

            for (int j = 0; j < ans.size(); ++j)
            {
                cout << ans[j] << " ";
            }
            cout << endl;
        }
    }
    delete[] visited;
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

    cout << "Connected Components are " << endl;
    Connected_Components(edges, n);

    // deleting all the memory

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}

// Return all Connected_Components BFS

/*#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void connected(int **edges, int n, int sv, bool *visited)
{
    int cnt = sv;

    while (cnt < n)
    {
        if (visited[cnt] != 0)
        {
            ++cnt;
            continue;
        }
        visited[cnt] = 1;
        queue<int> q;
        q.push(cnt);
        ++cnt;
        vector<int> v1;
        while (!q.empty())
        {
            int curr = q.front();
            v1.push_back(curr);

            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
    }
    delete[] visited;

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

    cout << "Connected Components " << endl;
    connected(edges, n, 0, visited);

    // deleting all the memory

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}*/
