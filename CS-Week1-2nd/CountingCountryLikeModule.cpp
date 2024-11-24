#include<bits/stdc++.h>
using namespace std;
char matrix[1001][1001];
int counter=0;
bool vis[1001][1001];
vector<pair<int,int>> d={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
bool valid(int x,int y){
     if(x>=0 && x<n && y>=0 && y<m && matrix[x][y]=='.'){
        return true;
        }
    else{
        return false;
    }
}

void dfs(int sourceRow,int sourceCol){
    vis[sourceRow][sourceCol]=true;
    for(int i=0;i<4;i++){
        int childRow = sourceRow + d[i].first;
        int childCol = sourceCol + d[i].second;
        if(valid(childRow,childCol)==true && vis[childRow][childCol]==false){
            vis[childRow][childCol]=true;
            dfs(childRow,childCol);
        }
       
    }


}

int main()
{
   
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='.'&& vis[i][j]==false){
                dfs(i,j);
                cnt++;
            }
        }
    }
   cout<<cnt;
    
    return 0;
}