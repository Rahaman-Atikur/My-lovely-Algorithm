#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool visitedArray[10005];
int nodeCounter = 0;

vector<int> result;

void dfs(int src){
    nodeCounter++;
    visitedArray[src] = true;
    for(int child: v[src]){
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
    for(int i=0;i<n;i++){
        if(visitedArray[i]==false){
            nodeCounter = 0;
            dfs(i);
            result.push_back(nodeCounter);
        }
    }

    sort(result.begin(),result.end());
    for(int size: result){
        cout<<size<<" ";
    }
   


    return 0;
}