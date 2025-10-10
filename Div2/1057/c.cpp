#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <unordered_map>
#include <vector>

int main( ) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);

  int t;
  std::cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    std::cin >> n;
    std::unordered_map<long long, long long> freq;
    std::vector<long long> lengths(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> lengths[i];
      freq[lengths[i]] += 1;
    }

    std::map<long long, long long> used;
    long long res = 0;
    for (const auto& [key, value] : freq) {
      long long even_sum = (value / 2LL) * 2LL;
      if (even_sum > 0) {
        used[key] = even_sum;
        res += even_sum * key;
      }
    }

    std::vector<long long> odds;
    for (const auto& [key, value] : freq) {
      if (value % 2 != 0) {
        odds.push_back(key);
      }
    }

    std::sort(odds.begin( ), odds.end( ));
    for (int i = 0; i < 2 && !odds.empty( ); ++i) {
      long long length = odds.back( );
      odds.pop_back( );
      used[length] += 1;
      res += length;
    }

    const auto count_sides = [&](const auto& mp) {
      long long res = 0;
      for (const auto& it : mp) {
        res += it.second;
      }
      return res;
    };

    while (!used.empty( )) {
      auto it = std::prev(used.end( ));
      long long max_len = it->first;

      if (max_len < res - max_len) {
        break;
      }

      res -= max_len;
      it->second -= 1;
      if (it->second == 0) {
        used.erase(it);
      }

      if (count_sides(used) < 3) {
        break;
      }
    }

    if (count_sides(used) < 3) {
      res = 0LL;
    }

    std::cout << res << "\n";
  }
}