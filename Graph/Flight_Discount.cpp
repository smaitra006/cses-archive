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
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({v, w});
  }
  vector<vll> dist(n + 1, vector<ll>(2, LONG_LONG_MAX));
  dist[1][0] = 0;
  priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
  pq.push({0, {1, 0}});
  while (!pq.empty())
  {
    ll u = pq.top().second.first;
    ll s = pq.top().second.second;
    ll d = pq.top().first;
    pq.pop();
    if (d > dist[u][s])
    {
      continue;
    }
    for (auto e : adj[u])
    {
      int v = e.first;
      int w = e.second;
      if (s == 0)
      {
        if (d + w < dist[v][0])
        {
          dist[v][0] = d + w;
          pq.push({d + w, {v, 0}});
        }
        if (d + floor(w * 1.0 / 2) < dist[v][1])
        {
          dist[v][1] = d + floor(w * 1.0 / 2);
          pq.push({d + floor(w * 1.0 / 2), {v, 1}});
        }
      }
      else
      {
        if (d + w < dist[v][1])
        {
          dist[v][1] = d + w;
          pq.push({d + w, {v, 1}});
        }
      }
    }
  }
  cout << dist[n][1] << endl;
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
