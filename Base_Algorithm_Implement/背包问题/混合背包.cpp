#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct good{
    int v;
    int w;
    int s;
};
int main(){
    int n,m;
    vector<int>dp(10100,0);
    vector<good>goods;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        if(-1 == s){
            goods.push_back({v,w,-1});
        }
        else if(0 == s){
            goods.push_back({v,w,0});
        }
        else{
            //多重背包转化为二进制优化
            for(int k = 1;k<=s;k*=2){
                s-=k;
                goods.push_back({v*k,w*k,-1});
            }
            if(s>0) goods.push_back({v*s,w*s,-1});
        }
    }
    for(auto good:goods){
        if(-1 == good.s){
            //01背包
            for(int j = m;j>=good.v;j--){
                dp[j] = max(dp[j],dp[j-good.v]+good.w);
            }
        }
        else{
            //无穷背包
            for(int j = good.v;j<=m;j++){
                dp[j] = max(dp[j],dp[j-good.v]+good.w);
            }
        }
    }
    cout<< dp[m];
    return 0;
}