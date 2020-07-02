#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>dp(1010,0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int v,w;
        cin>>v>>w;
        for(int j = v;j<=m;j++){
            dp[j] = max( dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[m];
    return 0;
}