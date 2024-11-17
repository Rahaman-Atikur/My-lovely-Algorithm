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
    memset(visitedArray,false,sizeof(visitedArray));
    int countedComponent = 0;
    for(int i=0;i<n;i++){
        if(visitedArray[i]==false){
            dfs(i);
            countedComponent++;
        }
    }
    cout<<countedNode;

    return 0;
}