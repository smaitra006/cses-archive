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
int memo[1001][1001];
int rec(vector<vector<char>> &a, int r, int c, int n)
{
  if (r >= n || c >= n)
  {
    return 0;
  }
  if (a[r][c] == '*')
    return 0;
  if (r == n - 1 && c == n - 1)
  {
    return 1;
  }
  if (memo[r][c] != -1)
  {
    return memo[r][c];
  }
  return memo[r][c] = (rec(a, r, c + 1, n) + rec(a, r + 1, c, n)) % MOD;
}
void solve()
{
  int n;
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  memset(memo, -1, sizeof(memo));
  cout << rec(a, 0, 0, n);
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
