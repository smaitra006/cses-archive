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

ll modInverse(ll n)
{
  return binpow(n, MOD - 2);
}

// --- Solution ---

void solve()
{
  int n;
  cin >> n;
  vector<vi> adj(n + 1, vi());
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vector<bool> visi(n + 1, false);
  queue<int> q;
  q.push(1);
  visi[1] = true;
  int last = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    last = u;
    for (int v : adj[u])
    {
      if (!visi[v])
      {
        visi[v] = true;
        q.push(v);
      }
    }
  }
  vector<bool> visi2(n + 1, false);
  queue<int> q2;
  q2.push(last);
  visi2[last] = true;
  int d = -1;
  while (!q2.empty())
  {
    int sz = q2.size();
    d++;
    while (sz--)
    {
      int u = q2.front();
      q2.pop();

      for (int v : adj[u])
      {
        if (!visi2[v])
        {
          visi2[v] = true;
          q2.push(v);
        }
      }
    }
  }
  cout << d << endl;
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
