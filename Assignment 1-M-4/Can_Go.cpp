#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1001][1001];
bool vis[1001][1001];
int ai,aj,bi,bj;
vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#')
        return false;
    else
        return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
            {
                 ai = i;
                 aj =j;
            }
            if(mat[i][j]=='B')
            {
                 bi = i;
                 bj =j;
            }
        }
    }

    dfs(ai,aj);
    if(vis[bi][bj]==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}