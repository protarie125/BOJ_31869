#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using WDP = tuple<ll, ll, ll>;

ll N;
map<string, WDP> proms;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  for (auto i = 0; i < N; ++i) {
    string s;
    ll w, d, p;
    cin >> s >> w >> d >> p;

    proms.insert({s, {w, d, p}});
  }

  vector<bool> goods(100, false);
  for (auto i = 0; i < N; ++i) {
    string s;
    ll x;
    cin >> s >> x;

    const auto& [w, d, p] = proms[s];
    if (x >= p) {
      goods[w * 7 + d] = true;
    }
  }

  ll ans = 0;
  ll ct = 0;
  for (const auto& b : goods) {
    if (b) {
      ++ct;
      ans = max(ans, ct);
    } else {
      ct = 0;
    }
  }

  cout << ans;

  return 0;
}