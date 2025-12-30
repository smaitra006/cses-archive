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

// ========================= T Y P E D E F S =========================
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// ========================= P B D S =========================
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ========================= M A C R O S =========================
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define set_bits __builtin_popcntll
#define lsb(x) ((x) & -(x))
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define rev(i, a, b) for (int i = a; i >= (b); --i)
#define each(x, v) for (auto &x : v)

// ========================= C O N S T A N T S =========================
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

// ========================= M A T H   U T I L S =========================
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
ll binpow(ll base, ll exp, ll mod = MOD) {
  ll res = 1; base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod; exp /= 2;
  }
  return res;
}
ll modInverse(ll n, ll mod = MOD) {return binpow(n, mod - 2, mod);}
ll nCr(ll n, ll r, const vector<ll>& fact, const vector<ll>& invFact, ll mod = MOD) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}
bool isPrime(ll n) {
  if(n <= 1) return false;
  for(ll i=2; i*i<=n; i++) if(n % i == 0) return false;
  return true;
}

// ========================= S O L U T I O N =========================

void solve() {
  ll n;
  cin >> n;
  ll len = 1;
  ll cnt = 9;
  ll f = 1;
  while (n > (len * cnt)) {
    n -= (len * cnt);
    cnt *= 10;
    f *= 10;
    len++;
  }
  ll i = n - 1;
  ll num = f + (i / len);
  string s = to_string(num);
  cout << s[i % len] << endl;
}

int main() {
  fastio;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
