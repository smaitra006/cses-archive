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
vector<bool> sieve(200001, true);
void build()
{
  sieve[0] = false;
  sieve[1] = false;
  for (int p = 2; p * p < 200001; p++)
  {
    if (sieve[p])
    {
      for (int i = p * p; i < 200001; i += p)
        sieve[i] = false;
    }
  }
}
void solve()
{
  int n;
  cin >> n;
  vi b(n + 1);
  build();
  int curr = n;
  while (curr > 0)
  {
    int p = curr + 1;
    while (!sieve[p])
    {
      p++;
    }
    int lb = p - curr;
    for (int i = lb; i <= curr; i++)
    {
      b[i] = p - i;
    }
    curr = lb - 1;
  }
  for (int i = 1; i <= n; i++)
  {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << b[i] << " ";
  }
  cout << endl;
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
