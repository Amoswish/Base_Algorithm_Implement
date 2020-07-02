#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m;
    vector<vector<int>>dp(1010,vector<int>(1010,0));
    vector<int> v(1010,0);
    vector<int> w(1010,0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i = n;i>=1;i--){
        for(int j = 0;j<=m;j++){
            dp[i][j] = dp[i+1][j];
            if(j>=v[i]) dp[i][j] = max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    int nowV = m;
    for(int i = 1;i<=n;i++){
        if(nowV>=v[i]&&dp[i][nowV] == dp[i+1][nowV-v[i]]+w[i]){//选了第i个
            cout<<i<<' ';
            nowV-=v[i];
        }
    }
    return 0;
}