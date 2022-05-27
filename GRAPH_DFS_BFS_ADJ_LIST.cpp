// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
int visit[8]{0};
// Simpler and adds elements to stack from end
void dfs1(int u, int A[][8], int n)
{
    int visited[8]{0};
    stack<int> stk;
    stk.emplace(u);

    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();

        if (visited[u] == 0)
        {
            cout << u << ", " << flush;
            visited[u] = 1;
            //    cout<<"dhiraj";
            for (int v = n - 1; v >= 0; v--)
            {
                if (A[u][v] == 1 && visited[v] == 0)
                {
                    stk.emplace(v);
                }
            }
        }
    }
}

void bfs(int u, int A[][8], int n)
{
    cout << u << " ";
    int visited[8]{0};
    queue<int> q;
    q.emplace(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int q1 = q.front();
        q.pop();
        for (int v = 1; v <= n - 1; v++)
        {
            if (A[q1][v] == 1 && visited[v] == 0)
            {
                q.emplace(v);
                visited[v] = 1;
                cout << v << " ,";
            }
        }
    }
}

void dfs2(int i, int A[][8], int n)
{

    if (visit[i] == 0)
    {
        cout << i << " ,";
        visit[i] = 1;
        for (int v = 1; v <= n - 1; v++)
        {
            if (A[i][v] == 1 && visit[v] == 0)
            {
                dfs1(v, A, n);
            }
        }
    }
}
int main()
{

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    int u = 5;

    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs1(1, A, 8);
    cout << endl;

    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs2(1, A, 8);
    cout << endl;

    cout << "bfs Vertex: " << u << " -> " << flush;
    bfs(1, A, 8);
    cout << endl;
    return 0;
}
