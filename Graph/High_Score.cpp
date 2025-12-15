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
  vector<pair<pii, int>> edge;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edge.pb({{u, v}, -w});
  }
  vll ans(n + 1, LONG_LONG_MAX);
  ans[1] = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (auto e : edge)
    {
      int u = e.first.first;
      int v = e.first.second;
      int w = e.second;
      if (ans[u] != LONG_LONG_MAX && ans[u] + w < ans[v])
      {
        ans[v] = ans[u] + w;
      }
    }
  }
  vi b(n + 1, 0);
  for (auto e : edge)
  {
    int u = e.first.first;
    int v = e.first.second;
    int w = e.second;
    if (ans[u] != LLONG_MAX && ans[u] + w < ans[v])
    {
      b[v] = 1;
    }
  }
  vector<vi> adj(n + 1, vi());
  for (auto e : edge)
  {
    adj[e.first.first].pb(e.first.second);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (b[i] == 1)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
    {
      if (!b[v])
      {
        b[v] = 1;
        q.push(v);
      }
    }
  }
  if (b[n] == 1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << -ans[n] << endl;
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
