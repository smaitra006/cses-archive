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
  vector<pll> v(n);
  ll cnt = 1, sum = 1, prod = 1, m = 1, cntp = 1, mod = MOD - 1;
  for (int i = 0; i < n; i++)
  {
    int p, a;
    cin >> p >> a;
    v[i] = {p, a};
    cntp = (cntp * (a + 1)) % (2 * mod);
    cnt = (cnt * (a + 1)) % MOD;
    m = (m * (binpow(p, a) % MOD)) % MOD;
    ll num = (binpow(p, a + 1) - 1 + MOD) % MOD;
    ll den = modInverse(p - 1);
    ll x = (num * den) % MOD;
    sum = (sum * x) % MOD;
  }
  for (auto x : v)
  {
    ll ex;
    if (x.second % 2 == 1)
    {
      ex = (x.second * (cntp / 2)) % mod;
    }
    else
    {
      ex = ((x.second / 2) * cntp) % mod;
    }
    prod = (prod * binpow(x.first, ex)) % MOD;
  }
  cout << cnt << " " << sum << " " << prod << endl;
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
