/**
 * Author:   Subhrajit Maitra
 * Motto:    "Talk is cheap. Show me the code."
 **/

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ========================= T Y P E S =========================
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// ========================= P B D S & H A S H =========================
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <class K, class V>
using safe_map = gp_hash_table<K, V, custom_hash>;

// ========================= M A C R O S =========================
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define rev(i, a, b) for (int i = a; i >= (b); --i)
#define each(x, v) for (auto& x : v)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define uniq(v) \
  sort(all(v)); \
  (v).erase(unique(all(v)), (v).end())

// ========================= U T I L S =========================
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < sz(v); i++) os << v[i] << (i == sz(v) - 1 ? "" : " ");
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << " " << p.second;
  return os;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rng);
}

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

// ========================= M A T H =========================
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
ll modInverse(ll n, ll mod = MOD) {
  return binpow(n, mod - 2, mod);
}
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return (a / gcd(a, b)) * b;
}

// ========================= S O L U T I O N =========================

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vpii> adj(n + 1, vpii());
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  ll ans = 0;
  vi visi(n + 1, 0);
  priority_queue<pii, vpii, greater<>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [wt, u] = pq.top();
    pq.pop();
    if (visi[u]) continue;
    visi[u] = 1;
    ans += wt;
    for (auto [v, w] : adj[u]) {
      if (!visi[v]) pq.push({w, v});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visi[i]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  cout << ans << endl;
}

int main() {
  fastio;
  int t = 1;
  //  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
