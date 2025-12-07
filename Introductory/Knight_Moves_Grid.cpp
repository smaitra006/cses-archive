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
int dirx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int diry[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve()
{
  int n;
  cin >> n;
  int s = n * n;
  vvi ans(n, vi(n, -1));
  queue<pii> q;
  ans[0][0] = 0;
  q.push({0, 0});
  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 8; i++)
    {
      int nx = x + dirx[i];
      int ny = y + diry[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && ans[nx][ny] == -1)
      {
        ans[nx][ny] = ans[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
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
