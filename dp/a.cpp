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
for(int i = 0; i < n; i++) {
    cin>>x[i];
}
int p=accumulate(x.begin(),x.end(),0);
vector<int> dp(p+1,0);
dp[0]=1;
for (int j = 0; j < n; j++){
    for (int i = p; i >=1; i--)
    {
        {
            if (i - x[j] >= 0)
            {
                dp[i] = max(dp[i - x[j]], dp[i]);
            }
        }
    }
}
int ans=count(dp.begin(),dp.end(),1);
ans--;
out(ans);
for(int i = 1; i <= p; i++) {
    if(dp[i]==1)
    {
        cout<<i<<" ";
    }
}
out("");
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