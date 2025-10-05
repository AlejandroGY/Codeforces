// me tomo como 16 minutos :(

#include <iostream>
#include <vector>

int main( ) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);

  int t;
  std::cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(m);

    bool possible = true;
    for (int i = 0; i < m; ++i) {
      std::cin >> arr[i];
      if (i && arr[i - 1] >= arr[i]) {
        possible = false;
      }
    }

    if (!possible) {
      std::cout << "1\n";
      continue;
    }

    int maxi = arr[m - 1];
    std::cout << n - maxi + 1 << "\n";
  }
}