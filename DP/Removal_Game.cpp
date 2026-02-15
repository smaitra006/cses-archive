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
#define sz(x) (int) (x).size()
#define pb push_back

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Direction arrays (Up, Right, Down, Left)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// --- Math Utilities ---

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  return (a / gcd(a, b)) * b;
}

ll binpow(ll base, ll exp, ll mod = MOD) {
  ll res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

ll modInverse(ll n) {
  return binpow(n, MOD - 2);
}

// --- Solution ---

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vll> dp(n, vll(n));
  for (int i = 0; i < n; i++) {
    int l = 0, r = i;
    while (r < n) {
      if (i == 0)
        dp[l][r] = a[i];
      else if (i == 1)
        dp[l][r] = max(a[l], a[r]);
      else {
        ll x = a[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);
        ll y = a[r] + min(dp[l + 1][r - 1], dp[l][r - 2]);
        dp[l][r] = max(x, y);
      }
      l++;
      r++;
    }
  }
  cout << dp[0][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
