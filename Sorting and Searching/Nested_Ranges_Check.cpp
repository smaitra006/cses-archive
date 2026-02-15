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

// --- Solution ---
bool cmp(pair<pii, int> &a, pair<pii, int> &b)
{
  if (a.first.first == b.first.first)
  {
    return a.first.second > b.first.second;
  }
  return a.first.first < b.first.first;
}
void solve()
{
  int n;
  cin >> n;
  vector<pair<pii, int>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), cmp);
  vi ans1(n, 0), ans2(n, 0);
  int mini_end = INT_MAX;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i].first.second >= mini_end)
    {
      ans1[a[i].second] = 1;
    }
    mini_end = min(mini_end, a[i].first.second);
  }
  int maxi_end = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (a[i].first.second <= maxi_end)
    {
      ans2[a[i].second] = 1;
    }
    maxi_end = max(maxi_end, a[i].first.second);
  }
  for (int i = 0; i < n; i++)
  {
    cout << ans1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << ans2[i] << " ";
  }
  cout << endl;
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
