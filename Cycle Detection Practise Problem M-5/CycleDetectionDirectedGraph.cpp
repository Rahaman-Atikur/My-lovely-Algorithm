#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
bool pathVis[N];
bool ans;

void dfs(int parent){
    vis[parent]=true;
    pathVis[parent]=true;
    for(int child: adj[parent]){
        if(pathVis[child]==true){
            ans = true;
        }
        if(vis[child]==false){
            dfs(child);
        }
    }
    pathVis[parent]=false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);

    }
    memset(vis,false,sizeof(vis));
    memset(pathVis,false,sizeof(pathVis));
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(i);
        }
    }
    if(ans==true)
        cout<<"Cycle Detected";
    else
        cout<<"Cycle not Detected";
    return 0;
}