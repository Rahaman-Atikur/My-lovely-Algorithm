#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];

void dfs(int parent){
    vis[parent]=true;
    cout<<parent<<endl;
    for(int child: adj[parent]){
        if(vis[child]==false){
            vis[child]=true;
            dfs(child);
        }
    }

}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(i);
        }
    }

    return 0;
}