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

bool is_prime(ll n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool primes[10001] = {true};
void build_sieve(int n)
{
  primes[0] = false;
  primes[1] = false;
  for (int i = 4; i <= n; i += 2)
  {
    primes[i] = false;
  }
  for (int i = 3; i * i <= n; i += 2)
  {
    if (primes[i])
    {
      for (int j = i * i; j <= n; j += 2 * i)
      {
        primes[j] = false;
      }
    }
  }
}

int spf[10001] = {0};
void build_spf(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (spf[i] != 0)
      continue;
    for (int j = 2 * i; j <= n; j += i)
    {
      if (spf[j] == 0)
        spf[j] = i;
    }
  }
}

vector<int> factorize(int k)
{
  vector<int> factors;
  while (spf[k] != 0)
  {
    factors.pb(spf[k]);
    k /= spf[k];
  }
  if (k > 1)
    factors.pb(k);
  return factors;
}

vector<int> sum_divisors(int n)
{
  vector<int> sum_div(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j += i)
    {
      sum_div[j] += i;
    }
  }
  return sum_div;
}

int lpf[10001] = {1};
void build_lpf(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (lpf[i] == 1)
    {
      for (int j = i; j <= n; j += i)
      {
        lpf[j] = i;
      }
    }
  }
}

// --- Solution ---

void solve()
{
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
