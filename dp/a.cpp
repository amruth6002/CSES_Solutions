#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9 + 7;
#define out(x) cout << x << "\n";
#define debug(x) std::cerr << #x << ": " << x << "\n"
#define setBit(x, i) (x |= (1LL << i))
#define clearBit(x, i) (x &= ~(1LL << i))
#define toggleBit(x, i) (x ^= (1LL << i))
#define getBit(x, i) ((x >> i) & 1)
#define msb(x) (63 - __builtin_clzll(x))
#define nos(x) __builtin_popcountll(x)
/*6.  1e18 consists of 60 bits
  7.  n^(1<<i) sees if the ith bit of n is set or not
  8.  a.erase(unique(a.begin(),a.end()),a.end) removes the duplicates but have to sort a before that other-wise
    some duplicates which are not side by side will be present*/
void solve()
{
int n;cin>>n;
vector<int> x(n);
vector<vector<int>> dp(n,vector<int>(n));
int sum=0;
for (int i = 0; i < n; i++)
{
    cin >> x[i];
    dp[i][i]=x[i];
    sum+=x[i];
}
for(int i = n-1; i >=0 ; i--) {
    for(int j = i+1; j < n; j++) {
        int a=x[i]-dp[i+1][j];
        int b=x[j]-dp[i][j-1];
        dp[i][j]=max(a,b);
    }
}
out((sum+dp[0][n-1])/2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
cin.tie(nullptr);
    // int t;cin >> t;while (t--)
    {
solve();
}
return 0;
}