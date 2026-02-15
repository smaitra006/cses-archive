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
int s = -1, e = -1;
bool dfs(vector<vi> &adj, vi &visi, vi &par, int u)
{
  visi[u] = 1;
  for (auto v : adj[u])
  {
    if (visi[v] == 1 && v != u && v != par[u])
    {
      s = v;
      e = u;
      return true;
    }
    else if (visi[v] == 0)
    {
      par[v] = u;
      if (dfs(adj, visi, par, v) == true)
      {
        return true;
      }
    }
  }
  return false;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vi> adj(n + 1, vi());
  vi visi(n + 1, 0);
  vi par(n + 1, -1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++)
  {
    if (visi[i] == 0)
    {
      if (dfs(adj, visi, par, i) == true)
      {
        vi ans;
        ans.pb(s);
        int u = e;
        while (u != s)
        {
          ans.pb(u);
          u = par[u];
        }
        ans.pb(s);
        cout << ans.size() << endl;
        for (auto x : ans)
        {
          cout << x << " ";
        }
        return;
      }
    }
  }
  if (s == -1 && e == -1)
  {
    cout << "IMPOSSIBLE" << endl;
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
