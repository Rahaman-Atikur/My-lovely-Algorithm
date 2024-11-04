#include<bits/stdc++.h>
using namespace std;
bool vis[10005];
int level[10005];
vector<int> v[10005];

void bfs(int src,int des){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        if(par==des){
             cout<<level[des]<<endl;
             return;
        }
        for(int child:v[par]){
             if(vis[child]==false){
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
             }
        }
       
       
    }
     cout<<"-1"<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int query;
    cin>>query;
    while(query--){
        int src,des;
        cin>>src>>des;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        bfs(src,des);

    }
    
    return 0;
}