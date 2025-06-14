/*Date Created: 14-06-2025*/
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
/*binary exponantion*/
int binpow(int a, int b)
{a %= MOD;int res = 1;while (b > 0)
{if (b & 1){res = res * a % MOD;}a=a*a%MOD;
b>>=1;}return res;}
/*6.  1e18 consists of 60 bits
7.  n^(1<<i) sees if the ith bit of n is set or not
8.  a.erase(unique(a.begin(),a.end()),a.end) removes the duplicates but have to sort a before that other-wise
some duplicates which are not side by side will be present*/
void solve()
{
    int n;cin>>n;
    int sum=(n*(n+1))/2;
    if(sum%2)
    {
        out(0);
        return;
    }
    int ssum=sum/2;
    vector<int> dp(ssum+1);
    dp[0]=1;
    for(int i = 1; i <= n; i++) {
        for(int j = ssum; j >= i; j--) {
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
    out((dp[ssum]*binpow(2,MOD-2))%MOD);
}
int32_t main()
{
ios_base::sync_with_stdio(false);cin.tie(nullptr);
// int t;cin >> t;while (t--)
{solve();}return 0;}
