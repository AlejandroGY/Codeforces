#include <bits/stdc++.h>

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   std::string s;
   std::cin >> s;

   int a[s.size( ) + 1] = { };
   for (int i = 1; i < s.size( ); ++i) {
      a[i] = (s[i] == s[i - 1]);
      a[i] += a[i - 1];
   }

   int q;
   std::cin >> q;
   for (int i = 0; i < q; ++i) {
      int ini, fin;
      std::cin >> ini >> fin;
      std::cout << a[fin - 1] - a[ini - 1] << "\n";
   }
}
