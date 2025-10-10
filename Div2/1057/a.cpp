#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

int main( ) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);

  int t;
  std::cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    std::cin >> n;

    std::set<int> freq;
    for (int i = 0; i < n; ++i) {
      int tmp;
      std::cin >> tmp;
      freq.insert(tmp);
    }
    std::cout << freq.size( ) << "\n";
  }
}