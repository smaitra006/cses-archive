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
void solve()
{
  int n;
  cin >> n;
  vector<pair<pii, int>> a;
  for (int i = 0; i < n; i++)
  {
    int s, e;
    cin >> s >> e;
    a.push_back({{s, e}, i});
  }
  sort(a.begin(), a.end());
  int cnt = 1;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vi ans(n);
  for (int i = 0; i < n; i++)
  {
    if (pq.empty())
    {
      ans[a[i].second] = cnt;
      pq.push({a[i].first.second, cnt});
      cnt++;
    }
    else
    {
      if (a[i].first.first > pq.top().first)
      {
        ans[a[i].second] = pq.top().second;
        pq.pop();
        pq.push({a[i].first.second, ans[a[i].second]});
      }
      else
      {
        ans[a[i].second] = cnt;
        pq.push({a[i].first.second, cnt});
        cnt++;
      }
    }
  }
  cout << cnt - 1 << endl;
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
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
