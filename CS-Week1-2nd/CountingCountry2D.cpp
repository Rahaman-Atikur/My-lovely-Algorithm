#include<bits/stdc++.h>
using namespace std;
bool visitedArray[1001][1001];
char mat[1001][1001];
int n,m;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]=='.'){
             return true;
    }
       
    else{
         return false;
    }
       
}


void dfs(int si,int sj){
    visitedArray[si][sj] = true;
    for(int i=0;i<4;i++){
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if(valid(ci,cj) && visitedArray[ci][cj]==false){
            visitedArray[ci][cj]=true;
            dfs(ci,cj);

        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    //memset(visitedArray,false,sizeof(visitedArray)); 
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.' && visitedArray[i][j]==false){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    
    return 0;
}