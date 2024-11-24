#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
vector<int> result;
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
        int x;
        cin>>x;
        if(v[x].size()==0){
             cout<<"-1";
            cout<<endl;
        }  
        else{
            for(int i=0;i<v[x].size();i++){
            
            result.push_back(v[x][i]);
        }
        sort(result.begin(),result.end(),greater<int>());
        for(int sz: result){
            cout<<sz<<" ";
        }
        cout<<endl;
        result.clear();
        }
    }
    return 0;
}