#include <iostream>
#include <map>

constexpr long long MAX = 1000010;

int n;
long long a[MAX];
long long fen[MAX];
long long prev[MAX];
long long back[MAX];

void update(int p, int val) {
   for (int i = p; i <= n; i += i & -i) {
      fen[i] += val;
   }
}

long long sum(int p) {
   long long ans = 0;
   for (int i = p; i; i -= i & -i) {
      ans += fen[i];
   }
   return ans;
}

void solve( ) {
   std::map<int, int> s;
   for (int i = 1; i <= n; ++i) {
      s[a[i]]++;
      prev[i] = s[a[i]];
   }

   s.clear( );

   for (int i = n; i >= 1; --i) {
      s[a[i]]++;
      back[i] = s[a[i]];
   }
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   std::cin >> n;
   for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
   }
   solve( );

   for (int i = 1; i <= n; ++i) {
      update(back[i], 1);
   }

   long long res = 0;
   for (int i = 1; i <= n; ++i) {
      update(back[i], -1);
      res += sum(prev[i] - 1);
   }

   std::cout << res << "\n";
}
