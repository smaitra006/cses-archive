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

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  int sx, sy, ex, ey;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 'A')
      {
        sx = i;
        sy = j;
      }
      if (a[i][j] == 'B')
      {
        ex = i;
        ey = j;
      }
    }
  }
  vector<vi> visi(n, vi(m, 0));
  vector<vi> ans(n, vi(m, -1));
  char dc[] = {'U', 'R', 'D', 'L'};
  queue<pii> q;
  q.push({sx, sy});
  visi[sx][sy] = 1;
  while (!q.empty())
  {
    pii p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    if (x == ex && y == ey)
    {
      cout << "YES" << endl;
      string res = "";
      while (x != sx || y != sy)
      {
        int d = ans[x][y];
        res += dc[d];
        x -= dx[d];
        y -= dy[d];
      }
      reverse(all(res));
      cout << res.length() << endl;
      cout << res << endl;
      return;
    }
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] != '#' && !visi[nx][ny])
      {
        visi[nx][ny] = 1;
        ans[nx][ny] = i;
        q.push({nx, ny});
      }
    }
  }
  cout << "NO" << endl;
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
