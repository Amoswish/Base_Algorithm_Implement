#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct good{
    int v;
    int w;
};
int main(){
    int n,m;
    vector<good>goods;
    vector<int>dp(21010,0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int j = 1;j<=s;j*=2){
            s-=j;
            goods.push_back({v*j,w*j});
        }
        if(s>0) goods.push_back({v*s,w*s});
    }
    //01背包
    for(auto good:goods){
        for(int j = m;j>=good.v;j--){
            dp[j] = max(dp[j],dp[j-good.v]+good.w);
        }
    }
    cout<<dp[m];
    return 0;
}