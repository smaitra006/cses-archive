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
bool cmp(pii &a, pii &b)
{
  return a.second < b.second;
}
void solve()
{
  int n, k;
  cin >> n >> k;
  vector<pii> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), cmp);
  multiset<ll> ms;
  ll cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (ms.empty())
    {
      ms.insert(a[i].second * (-1));
    }
    else
    {
      auto x = ms.lower_bound(a[i].first * (-1));
      if (x != ms.end())
      {
        ms.erase(x);
        ms.insert(a[i].second * (-1));
      }
      else if (x == ms.end() && ms.size() < k)
      {
        ms.insert(a[i].second * (-1));
      }
      else
      {
        cnt++;
      }
    }
  }
  cout << n - cnt << endl;
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
