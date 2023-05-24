#include <bits/stdc++.h>
using namespace std;
#define int long long
#define R 9
#define C 10
#define se second
#define fi first
typedef pair<int, int> Pair;
typedef vector<vector<int>> Graph;

class cell
{
public:
    int parI;
    int parJ;
    double F;
    double G;
    double H;
};
bool isValid(Pair p)
{
    int i = p.fi;
    int j = p.se;
    return (i >= 0 && j >= 0 && i < R && j < C);
}
bool isDestination(Pair s, Pair d)
{
    return (s == d);
}
bool isBlocked(Pair p, Graph &g)
{
    return (g[p.fi][p.se] == 0);
}

double huerastic(int i, int j, Pair des)
{
    double x = (i - des.fi) * (i - des.fi);
    double y = (j - des.se) * (j - des.se);
    double ans = sqrt(x + y);
}
void printPath(Pair S, int d1, int d2, cell cellList[R][C])
{
    int s1 = S.fi;
    int s2 = S.se;
    stack<Pair> ans;
    ans.push({d1, d2});
    while (!(cellList[d1][d2].parI == s1 && cellList[d1][d2].parJ == s2))
    {

        int t1 = cellList[d1][d2].parI;
        int t2 = cellList[d1][d2].parJ;
        d1 = t1;
        d2 = t2;
        ans.push({d1, d2});
    }
    cout << "PRINT \n";
    cout << "[ " << S.fi << " " << S.se << " ]" << endl;
    while (!ans.empty())
    {
        Pair k = ans.top();
        cout << "[ " << k.fi << " " << k.se << " ]" << endl;
        ans.pop();
    }
    return;
}

void A_star(Graph &grid, Pair sou, Pair des)
{

    if (!isValid(sou) || !isValid(des))
    {
        cout << "Sourse or Destination is InValid ";
        return;
    }
    if (isBlocked(sou, grid) || isBlocked(des, grid))
    {
        cout << "Sourse or Destination is Blocked ";
        return;
    }
    if (isDestination(sou, des))
    {
        cout << "Given sourse is destination ";
        return;
    }
    set<pair<int, Pair>> openList;
    bool closeList[R][C] = {false};
    cell cellList[R][C];
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cellList[i][j].parI = -1;
            cellList[i][j].parJ = -1;
            cellList[i][j].G = FLT_MAX;
            cellList[i][j].H = FLT_MAX;
            cellList[i][j].F = FLT_MAX;
        }
    }
    int i = sou.fi;
    int j = sou.se;
    cellList[i][j].parI = i;
    cellList[i][j].parJ = j;
    cellList[i][j].G = 0.0;
    cellList[i][j].H = 0.0;
    cellList[i][j].F = 0.0;

    openList.insert({0.0, sou});

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    while (!openList.empty())
    {
        pair<int, Pair> P = *openList.begin();
        openList.erase(openList.begin());
        int f = P.fi;
        int i = P.se.fi;
        int j = P.se.se;
        if (closeList[i][j])
            continue;
        closeList[i][j] = 1;

        double fNew;
        double gNew;
        double hNew;
        for (int l = 0; l < 8; ++l)
        {
            int iNew = i + dx[l];
            int jNew = j + dy[l];
            // 0 2 4 6
            if (isValid({iNew, jNew}))
            {

                if (isDestination({iNew, jNew}, des))
                {
                    cellList[iNew][jNew].parI = i;
                    cellList[iNew][jNew].parJ = j;
                    printPath(sou, iNew, jNew, cellList);
                    return;
                }
                else if (closeList[iNew][jNew] == 0 && !isBlocked({iNew, jNew}, grid))
                {
                    if (l & 1)
                        gNew = cellList[i][j].G + 1.0;
                    else
                        gNew = cellList[i][j].G + 1.414;
                    hNew = huerastic(iNew, jNew, des);
                    fNew = gNew + hNew;
                    if (cellList[iNew][jNew].F == FLT_MAX || cellList[iNew][jNew].F > fNew)
                    {
                        cellList[iNew][jNew].parI = i;
                        cellList[iNew][jNew].parJ = j;
                        cellList[iNew][jNew].G = gNew;
                        cellList[iNew][jNew].H = hNew;
                        cellList[iNew][jNew].F = fNew;
                        openList.insert({fNew, {iNew, jNew}});
                    }
                }
            }
        }
    }
    cout << "There no path exist ";
    return;
};
signed main()
{
    Graph grid = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                  {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                  {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                  {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}};

    A_star(grid, {8, 0}, {5, 3});
    
    return 0;
}


// PRINT  
// [ 8 0 ]
// [ 7 0 ]
// [ 6 0 ]
// [ 5 0 ]
// [ 4 1 ]
// [ 4 2 ]
// [ 5 3 ]
