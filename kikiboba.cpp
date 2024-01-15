#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;

  int b = count(all(s), 'b');
  int k = count(all(s), 'k');

  if (b == 0 && k == 0) {
    cout << "none";
  } else if (b == k) {
    cout << "boki";
  } else if (b > k) {
    cout << "boba";
  } else if (b < k) {
    cout << "kiki";
  }
}