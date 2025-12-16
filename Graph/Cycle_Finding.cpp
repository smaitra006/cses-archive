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
  vector<pair<pii, ll>> edge;
  for (int i = 0; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    edge.pb({{u, v}, w});
  }
  vll dist(n + 1, 0);
  vi par(n + 1, -1);
  int k;
  for (int i = 0; i < n; i++)
  {
    k = -1;
    for (auto e : edge)
    {
      ll u = e.first.first;
      ll v = e.first.second;
      ll w = e.second;
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        par[v] = u;
        k = v;
      }
    }
  }
  if (k == -1)
  {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    k = par[k];
  }
  vi ans;
  int start = k;
  ans.push_back(k);
  int curr = par[k];
  while (curr != k)
  {
    ans.push_back(curr);
    curr = par[curr];
  }
  ans.push_back(k);
  reverse(all(ans));
  cout << "YES" << endl;
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
