#include <bits/stdc++.h>
using namespace std;

// =============================================================================
//  TYPE ALIASES
// =============================================================================
using ll = long long;
using ld = long double;
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vi>;

// =============================================================================
//  CONSTANTS
// =============================================================================
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// =============================================================================
//  MACROS
// =============================================================================
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((ll)(v).size())
#define fi first
#define se second
#define endl '\n'

// =============================================================================
//  UTILITY FUNCTIONS
// =============================================================================
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

inline ll power(ll base, ll exp, ll mod = MOD)
{
  ll res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

// =============================================================================
//  SOLVE FUNCTION
// =============================================================================
int memo[1000001];
int dp(vi &a, int sum)
{
  if (sum < 0)
    return INT_MAX;
  if (sum == 0)
    return 0;
  if (memo[sum] != -1)
  {
    return memo[sum];
  }
  int cnt = INT_MAX;
  for (auto x : a)
  {
    cnt = min(cnt, dp(a, sum - x));
  }
  if (cnt == INT_MAX)
  {
    return memo[sum] = INT_MAX;
  }
  else
  {
    return memo[sum] = 1 + cnt;
  }
}
void solve()
{
  int n, sum;
  cin >> n >> sum;
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vi dp(1000001, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= sum; i++)
  {
    ll cnt = INT_MAX;
    for (auto x : a)
    {
      if ((i - x) >= 0)
      {
        cnt = min(cnt, dp[i - x]);
      }
    }
    if (cnt == INT_MAX)
    {
      dp[i] = cnt;
    }
    else
    {
      dp[i] = 1 + cnt;
    }
  }
  if (dp[sum] == INT_MAX)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << dp[sum] << endl;
  }
}

// =============================================================================
//  MAIN FUNCTION
// =============================================================================
int main()
{
  fast_io;
  // #ifdef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif

  ll t = 1;
  // cin >> t;
  while (t--)
    solve();
}
