#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x−axis in interva l [−pi , pi ]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes d is t ()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a ’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
  if (sz(pts) <= 1)
    return pts;
  sort(all(pts));
  vector<P> h(sz(pts) + 1);
  int s = 0, t = 0;

  for (P p : pts) {
    while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
      t--;
    h[t++] = p;
  }

  s = --t;
  reverse(all(pts));

  for (P p : pts) {
    while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
      t--;
    h[t++] = p;
  }

  s = --t;

  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  vector<P> pts;

  while (cin >> n) {
    if (n == 0)
      break;

    pts.resize(n);
    for (auto &&x : pts)
      cin >> x.x >> x.y;

    vector<P> hull = convexHull(pts);

    cout << sz(hull) << '\n';
    for (auto &&x : hull)
      cout << x.x << ' ' << x.y << '\n';
  }

  return 0;
}