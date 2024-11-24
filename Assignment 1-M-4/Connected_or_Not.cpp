#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> v[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    int q;
    cin>>q;
    while(q--){
         int src,des;
    int flag = 0;
    cin>>src>>des;
    for(int i=0;i<v[src].size();i++){
        if(v[src][i]==des || src==des){
            flag = 1;
        }
    }
    if(flag==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
   
    return 0;
}