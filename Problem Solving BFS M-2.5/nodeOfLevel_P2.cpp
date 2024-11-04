#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
vector<int> v1;
void bfs(int l)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0] = true;
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
         if (l == level)
        {
            v1.push_back(par);
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
        int l;
        cin >> l;
        bfs(l);
        reverse(v1.begin(), v1.end());
        for (int val : v1)
        {
            cout << val << " ";
        }

    return 0;
}