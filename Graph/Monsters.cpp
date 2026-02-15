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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int pc, pr;
  queue<pii> mq;
  vector<vi> mdist(n, vi(m, INT_MAX)), pdist(n, vi(m, INT_MAX)), dir(n, vi(m, INT_MAX));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 'A')
      {
        pr = i;
        pc = j;
        pdist[pr][pc] = 0;
      }
      if (a[i][j] == 'M')
      {
        mq.push({i, j});
        mdist[i][j] = 0;
      }
    }
  }
  while (!mq.empty())
  {
    int r = mq.front().first;
    int c = mq.front().second;
    mq.pop();
    for (int i = 0; i < 4; i++)
    {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] != '#' && mdist[r][c] + 1 < mdist[nr][nc])
      {
        mdist[nr][nc] = mdist[r][c] + 1;
        mq.push({nr, nc});
      }
    }
  }
  queue<pii> pq;
  pq.push({pr, pc});
  while (!pq.empty())
  {
    int r = pq.front().first;
    int c = pq.front().second;
    pq.pop();
    for (int i = 0; i < 4; i++)
    {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] != '#' && pdist[r][c] + 1 < pdist[nr][nc])
      {
        pdist[nr][nc] = pdist[r][c] + 1;
        pq.push({nr, nc});
        dir[nr][nc] = i;
      }
    }
  }
  int ansr = -1, ansc = -1, ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
      {
        if (a[i][j] != '#' && pdist[i][j] < mdist[i][j] && pdist[i][j] < ans)
        {
          ans = pdist[i][j];
          ansr = i;
          ansc = j;
        }
      }
    }
  }
  if (ans == INT_MAX)
  {
    cout << "NO" << endl;
    return;
  }
  string s = "", c = "URDL";
  while (ansc != pc || ansr != pr)
  {
    int i = dir[ansr][ansc];
    s += c[i];
    ansr = ansr - dx[i];
    ansc = ansc - dy[i];
  }
  reverse(all(s));
  cout << "YES" << endl;
  cout << ans << endl;
  cout << s << endl;
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
