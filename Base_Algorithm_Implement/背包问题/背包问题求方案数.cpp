#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int>dp(10010,-1e9);
    vector<int>g(1010,0);
    int mod = 1e9+7;
    int n,m;
    cin>>n>>m;
    dp[0] = 0;
    g[0] = 1;
    for(int i = 1;i<=n;i++){
        int v,w;
        cin>>v>>w;
        for(int j = m;j>=v;j--){
            int res = max(dp[j],dp[j-v]+w);
            int s = 0;
            if(res == dp[j]) s+= g[j];
            if(res == (dp[j-v]+w)) s += g[j-v];
            g[j] = s%mod;
            dp[j] = res;
        }
    }
    int maxw = 0;
    for(int i = 0;i<=m;i++){
        maxw = max(maxw,dp[i]);
    }
    int ans = 0;
    for(int i = 0;i<=m;i++){
       if( maxw == dp[i]) {
           ans +=g[i];
       }
    }
    cout<<ans;
    return 0;
}