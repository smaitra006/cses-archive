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
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n)
  {
    cout << "NO" << endl;
    return;
  }
  if ((a > 0 && b == 0) || (a == 0 && b > 0))
  {
    cout << "NO" << endl;
    return;
  }
  vi p1, p2;
  int d = n - (a + b);
  for (int i = 1; i <= d; i++)
  {
    p1.pb(i);
    p2.pb(i);
  }
  if (a > 0 || b > 0)
  {
    vi s;
    for (int i = d + 1; i <= n; i++)
      s.pb(i);
    for (int x : s)
      p1.pb(x);
    for (int i = a; i < s.size(); i++)
      p2.pb(s[i]);
    for (int i = 0; i < a; i++)
      p2.pb(s[i]);
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    cout << p1[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << p2[i] << " ";
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}
