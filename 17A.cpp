#include <iostream>
#include <vector>

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int n, k;
   std::cin >> n >> k;

   bool criba[n + 1] = { };
   std::vector<int> primos;
   for (int i = 2; i <= n; ++i) {
      if (!criba[i]) {
         for (int j = 2 * i; j <= n; j += i) {
            criba[j] = true;
         }
         primos.push_back(i);
      }
   }

   int acum = 0, res = 0;
   for (int i = 0; i < primos.size( ); ++i) {
      if (i > 1) {
         if (acum + 1 > n) break; 
         res += (!criba[acum + 1]);
         acum -= primos[i - 2];
      }
      acum += primos[i];
   }
   std::cout << (res >= k ? "YES\n" : "NO\n");
}
