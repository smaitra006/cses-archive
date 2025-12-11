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
int memo[100005][105];
int rec(vi &a, int i, int last, int n, int m)
{
  if (i == n)
  {
    return 1;
  }
  if (memo[i][last] != -1)
  {
    return memo[i][last];
  }
  int ans = 0;
  int l, r;
  if (a[i] == 0)
  {
    l = 1;
    r = m;
  }
  else
  {
    l = a[i];
    r = a[i];
  }
  if (i > 0)
  {
    l = max(l, last - 1);
    r = min(r, last + 1);
  }
  for (int j = l; j <= r; j++)
  {
    ans = (ans + rec(a, i + 1, j, n, m)) % MOD;
  }
  return memo[i][last] = ans;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  memset(memo, -1, sizeof(memo));
  cout << rec(a, 0, 0, n, m) << endl;
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
