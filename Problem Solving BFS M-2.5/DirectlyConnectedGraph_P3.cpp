#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
vector<int> v1;
int cnt = 0;
void bfs(int givenNode)
{
    queue<pair<int, int>> q;
    q.push({givenNode, 0});
    vis[givenNode] = true;
    int par, level;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        par = p.first;
        level = p.second;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;

            }
           
        }  
         if (level == 1)
        {
                cnt++;
        }
    }
}
    int main()
    {
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int givenNode;
        cin >> givenNode;
        bfs(givenNode);
        cout<<cnt;

        return 0;
    }