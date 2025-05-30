#include <bits/stdc++.h>
using namespace std;
#define int long long
#define out(n) cout << n << "\n"
const int inf = 1000000007;

void solve()
{
string a;cin>>a;
int n=a.size();
string b;cin>>b;
int m=b.size();

vector<vector<int>> dp(n+1,vector<int>(m+1,0));
for(int i = 0; i <= n; i++) {
    dp[i][0]=i;
}
for(int i = 0; i < m+1; i++) {
    dp[0][i]=i;
}
for(int i = 1; i <=n; i++) {
    for(int j = 1; j <= m; j++) {
        dp[i][j]=inf;
        if(a[i-1]==b[j-1])  
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        }
        else
        {
            dp[i][j]=min({dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1});
        }
    }
}
out(dp[n][m]);    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        solve();
    }
    return 0;
}
