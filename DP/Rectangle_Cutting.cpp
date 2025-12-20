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
int dp[501][501];
void solve()
{
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++)
  {
    for (int j = 1; j <= b; j++)
    {
      if (i != j)
      {
        dp[i][j] = INT_MAX;
      }
      for (int k = 1; k < i; k++)
      {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      for (int k = 1; k < j; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }
  cout << dp[a][b] << endl;
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
