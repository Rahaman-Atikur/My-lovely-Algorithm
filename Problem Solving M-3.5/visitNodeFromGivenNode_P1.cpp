#include<bits/stdc++.h>
using namespace std;
vector<int>v[10005];
bool visitedArray[10005];
int countedNode = 0;
void dfs(int givenNode){
    countedNode++;
    visitedArray[givenNode]=true;
    for(int child: v[givenNode]){
        if(visitedArray[child]==false){
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int givenNode;
    cin>>givenNode;
    dfs(givenNode);
    cout<<countedNode;
    return 0;
}