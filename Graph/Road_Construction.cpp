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

// Directioan arrays (Up, Right, Down, Left)
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
int par[100001], sz[100001];
int comp, maxi;
int find_par(int u) {
  if (par[u] == u) return u;
  return par[u] = find_par(par[u]);
}

void union_sz(int a, int b) {
  a = find_par(a);
  b = find_par(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    maxi = max(maxi, sz[a]);
    comp--;
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  comp = n, maxi = 1;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    union_sz(u, v);
    cout << comp << " " << maxi << endl;
  }
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
