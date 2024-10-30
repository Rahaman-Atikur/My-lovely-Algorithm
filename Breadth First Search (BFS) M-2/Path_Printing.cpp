#include <bits/stdc++.h>
using namespace std;


vector<int> v[1005];

bool visitedArray[1005];
int level[1005];
int parentArray[1005];

void bfs(int source){
    queue<int> q;
    q.push(source);
    visitedArray[source]=true;
    level[source] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        //cout<<parent<<endl;
        for(int i=0;i<v[parent].size();i++){
            int child = v[parent][i];
            if(visitedArray[child]==false){
                q.push(child);
                visitedArray[child]=true;
                level[child] = level[parent]+1;
                parentArray[child] = parent;
            }
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
    int source,destination;
    cin >> source>>destination;
    memset(visitedArray,false,sizeof(visitedArray)); 
    memset(level,-1,sizeof(level));
    memset(parentArray,-1,sizeof(parentArray));   
    bfs(source);
    int x = destination;
    vector<int> path;
    while(x!=-1){
        path.push_back(x);
        x = parentArray[x];
    }
    reverse(path.begin(),path.end());
    for(int val:path){
        cout<<val<<" ";
    }
   

    return 0;
}