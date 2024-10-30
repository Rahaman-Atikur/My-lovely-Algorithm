#include <bits/stdc++.h>
using namespace std;


vector<int> v[1005];

bool visitedArray[1005];
int level[1005];

void bfs(int source){
    queue<int> q;
    q.push(source);
    visitedArray[source]=true;
    level[source] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout<<parent<<endl;
        for(int i=0;i<v[parent].size();i++){
            int child = v[parent][i];
            if(visitedArray[child]==false){
                q.push(child);
                visitedArray[child]=true;
                level[child] = level[parent]+1;
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
    int source;
    cin >> source;
    memset(visitedArray,false,sizeof(visitedArray)); 
    memset(level,-1,sizeof(level));   
    bfs(source);
    for(int i=0;i<n;i++){
        cout<<i<<" "<<level[i];
    }

    return 0;
}