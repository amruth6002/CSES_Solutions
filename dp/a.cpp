#include <bits/stdc++.h>
using namespace std;
#define int long long
#define out(n) cout << n << "\n"
const int inf = 1000000007;
/*1.  (n<<i) multiplies n*2poweri
2.  (n>>i) divides n/2poweri
3.  (1<<i) 2 poweri (left_shift)
4.  (1>>i) 1/2 poweri(right shft operator)
5.  __builtin_popcountll(n); counts number of set bits in n(long long)
6.  1e18 consists of 60 bits
7.  n^(1<<i) sees if the ith bit of n is set or not
8.  a.erase(unique(a.begin(),a.end()),a.end) removes the duplicates but have to sort a before that other-wise
    some duplicates which are not side by side will be present
9.*/
// log function
int lg(int n)
{
    int c = 0;
    while (n > 1)
    {
        c++;
        n = (n + 1) / 2;
    }
    return c;
}
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