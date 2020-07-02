#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>dp(1010,0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int j = m;j>=v;j--){
            for(int k = 1;k<=s&&(k*v)<=j;k++){
                dp[j] = max(dp[j],dp[j-k*v]+k*w);
            }
        }
    }
    cout<<dp[m];
    return 0;
}