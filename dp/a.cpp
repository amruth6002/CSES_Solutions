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
{
    a %= MOD;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
/*6.  1e18 consists of 60 bits
7.  n^(1<<i) sees if the ith bit of n is set or not
8.  a.erase(unique(a.begin(),a.end()),a.end) removes the duplicates but have to sort a before that other-wise
some duplicates which are not side by side will be present*/
string LCS(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans.push_back(s[i - 1]);
            i--, j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t) << "\n";
    return 0;
}
