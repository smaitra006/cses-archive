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

void solve()
{
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  set<int> st;
  for (int i = 0; i <= k; i++)
  {
    st.insert(i);
  }
  vi cnt(k + 1, 0);
  for (int i = 0; i < k; i++)
  {
    if (a[i] <= k)
    {
      st.erase(a[i]);
      cnt[a[i]]++;
    }
  }
  cout << *st.begin() << " ";
  int l = 0, r = k - 1;
  while (r + 1 < n)
  {
    if (a[l] <= k)
    {
      cnt[a[l]]--;
      if (cnt[a[l]] == 0)
      {
        st.insert(a[l]);
      }
    }
    l++;
    r++;
    if (a[r] <= k)
    {
      st.erase(a[r]);
      cnt[a[r]]++;
    }
    cout << *st.begin() << " ";
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
