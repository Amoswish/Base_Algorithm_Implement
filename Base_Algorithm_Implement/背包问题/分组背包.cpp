#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<int> dp(1010,0);
    vector<int> v(110,0);
    vector<int> w(110,0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int group;
        cin>>group;
        for(int k = 0;k<group;k++) cin>>v[k]>>w[k];
        for(int j = m;j>=0;j--){
            for(int k = 0;k<group;k++){
                if(j>=v[k]) dp[j] = max(dp[j],dp[j-v[k]]+w[k]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}
