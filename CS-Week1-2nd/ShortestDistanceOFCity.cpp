#include<bits/stdc++.h>
using namespace std;
bool visitedArray[1001][1001];
char mat[1001][1001];
int n,m;

int level[1001][1001];

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

void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    visitedArray[si][sj]= true;
    level[si][sj]=0;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        int nRow = node.first;
        int nCol = node.second;
        for(int i=0;i<4;i++){
            int ci = nRow + dx[i];
            int cj = nCol + dy[i];
            if(valid(ci,cj) && visitedArray[ci][cj]==false){
                visitedArray[ci][cj]=true;
                level[ci][cj] = level[nRow][nCol]+1;
                bfs(ci,cj);
                q.push({ci,cj});
            }
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
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.' && visitedArray[i][j]==false){
                bfs(i,j);
            }
        }
    }
    int cnt =0;
    int sourceRow,soureColumn;
    cin>>sourceRow>>soureColumn;
    int destinationRow,destinationColumn;
    cin>>destinationRow>>destinationColumn;
    bfs(sourceRow,soureColumn);
    if(visitedArray[destinationRow][destinationColumn]==true){
        cout<<"Shortest Path"<<" "<<level[destinationRow][destinationColumn];
    }
    else{
        cout<<"No";
    }
    return 0;
}