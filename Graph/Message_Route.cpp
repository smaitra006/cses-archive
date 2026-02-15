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
  vector<vi> adj(n + 1, vi());
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vi visi(n + 1, 0);
  vi par(n + 1, -1);
  vi dist(n + 1, 0);
  queue<int> q;
  q.push(1);
  visi[1] = 1;
  dist[1] = 1;
  par[1] = 0;
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for (auto x : adj[t])
    {
      if (!visi[x])
      {
        q.push(x);
        visi[x] = 1;
        dist[x] = dist[t] + 1;
        par[x] = t;
      }
    }
  }
  if (par[n] == -1)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << dist[n] << endl;
  vi ans;
  int p = n;
  while (p != 0)
  {
    ans.pb(p);
    p = par[p];
  }
  reverse(all(ans));
  for (auto x : ans)
  {
    cout << x << " ";
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
