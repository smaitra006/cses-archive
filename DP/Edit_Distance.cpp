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
int n, m;
int memo[5001][5001];
int rec(string s, string t, int i, int j)
{
  if (i == n)
  {
    return m - j;
  }
  if (j == m)
  {
    return n - i;
  }
  if (memo[i][j] != -1)
  {
    return memo[i][j];
  }
  if (s[i] == t[j])
  {
    return rec(s, t, i + 1, j + 1);
  }
  int in = 1 + rec(s, t, i, j + 1);
  int del = 1 + rec(s, t, i + 1, j);
  int rep = 1 + rec(s, t, i + 1, j + 1);
  return memo[i][j] = min({in, del, rep});
}
void solve()
{
  string s, t;
  cin >> s >> t;
  memset(memo, -1, sizeof(memo));
  n = s.size();
  m = t.size();
  vector<vi> dp(n + 1, vi(m + 1, 0));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++)
  {
    dp[0][j] = j;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
      }
    }
  }
  cout << dp[n][m] << endl;
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
