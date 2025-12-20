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
set<ll> st;
bool dp[100001];
void solve()
{
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  memset(dp, false, sizeof(dp));
  dp[0] = true;
  for (int i = 0; i < n; i++)
  {
    for (int j = 100000; j >= a[i]; j--)
    {
      if (dp[j - a[i]])
      {
        dp[j] = true;
      }
    }
  }
  for (int i = 1; i <= 100000; i++)
  {
    if (dp[i])
    {
      st.insert(i);
    }
  }
  cout << st.size() << endl;
  for (auto x : st)
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
