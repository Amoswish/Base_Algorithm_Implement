#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 1005;
int w[MAXN];    // 价值
int v[MAXN];    // 体积
int dp[MAXN][MAXN];  // dp[i][j], 体积为j下前i个物品的最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i]>>w[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j];
            if((j-v[i])>=0)//当前已装容量大于v[i],只有这样才证明可以装入第i件
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] + w[i]);
        }
    int ans = 0;
    for(int i = 0;i<=m;i++){
        ans = max(dp[n][i],ans);
    }
    cout << ans;
    return 0;
}