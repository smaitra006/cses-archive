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
int memo[100001][1001];
int dp(vi costs, vi pages, int x, int i)
{
  if (i >= costs.size() || x <= 0)
  {
    return 0;
  }
  if (memo[x][i] != -1)
  {
    return memo[x][i];
  }
  int not_take = dp(costs, pages, x, i + 1);
  int take = INT_MIN;
  if (costs[i] <= x)
  {
    take = pages[i] + dp(costs, pages, x - costs[i], i + 1);
  }
  return memo[x][i] = max(take, not_take);
}
void solve()
{
  int n, x;
  cin >> n >> x;
  vi costs(n), pages(n);
  for (int i = 0; i < n; i++)
  {
    cin >> costs[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> pages[i];
  }
  int dp[100001][1001];
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
