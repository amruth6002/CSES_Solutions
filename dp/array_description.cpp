#include <bits/stdc++.h>
using namespace std;
#define int long long
#define out(n) cout << n << "\n"
const int mod = 1000000007;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // dp[position][value]
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    if(a[0]!=0)
    {
       dp[0][a[0]]=1;
    }
    else
    {
       for(int i = 1; i <= m; i++) {
        dp[0][i]=1;
       }
    }
    for(int i = 1; i < n; i++) {
        if(a[i]==0)
        {
         for(int j = 1; j <= m; j++) {
            if(j-1>=1)
            {
             dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j+1<=m)
            {
            dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
         }
        }
        else
        {
            if(a[i]-1>=1)
            {
             dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]-1])%mod;
            }
            dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]])%mod;
            if(a[i]+1<=m)
            {
            dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]+1])%mod;
            }
        }
    }
    int ans=0;
    for(int i = 1; i <= m; i++) {
        ans=(ans+dp[n-1][i])%mod;
    }
    out(ans%mod);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    {
        solve();
    }
    return 0;
}