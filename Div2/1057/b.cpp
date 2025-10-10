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
    int x, y, z;
    std::cin >> x >> y >> z;

    bool possible = true;
    for (int k = 0; k < 31; ++k) {
      int bit_x = 1 & (x >> k);
      int bit_y = 1 & (y >> k);
      int bit_z = 1 & (z >> k);
      if (bit_x + bit_y + bit_z == 2) {
        possible = false;
        break;
      }
    }
    std::cout << (possible ? "YES" : "NO") << "\n";
  }
}