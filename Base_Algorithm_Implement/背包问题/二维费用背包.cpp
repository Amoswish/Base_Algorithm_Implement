#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n,totalV,totalM;
    vector<vector<int>> dp(10010,vector<int>(1010,0));
    cin>>n>>totalV>>totalM;
    for(int i = 1;i<=n;i++){
        int v,s,w;
        cin>>v>>s>>w;
        for(int j = totalV;j>=v;j--){
            for(int k = totalM;k>=s;k--){
                dp[j][k] = max(dp[j][k],dp[j-v][k-s]+w);
            }
        }
    }
    cout<<dp[totalV][totalM];
    return 0;
}