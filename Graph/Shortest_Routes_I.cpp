/*
  Author: Subhrajit Maitra
*/
#include <bits/stdc++.h>
using namespace std;

// Standard type aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

// Short utility macros
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Direction arrays (Up, Right, Down, Left)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// --- Math Utilities ---

ll gcd(ll a, ll b)
{
  return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  if (a == 0 || b == 0)
    return 0;
  return (a / gcd(a, b)) * b;
}

ll binpow(ll base, ll exp, ll mod = MOD)
{
  ll res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

// --- Solution ---

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> adj(n + 1, vector<pii>());
  vll ans(n + 1, LONG_LONG_MAX);
  for (int i = 0; i < m; i++)
  {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].pb({v, d});
  }
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  ans[1] = 0;
  pq.push({0, 1});
  while (!pq.empty())
  {
    ll d = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    if (d > ans[u])
    {
      continue;
    }
    for (auto v : adj[u])
    {
      if (v.second + d < ans[v.first])
      {
        ans[v.first] = v.second + d;
        pq.push({v.second + d, v.first});
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}
