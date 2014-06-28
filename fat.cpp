#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

long long fact[21];
vector<int> get_nth(int n, long long size) {
   if(n == 1) {
       assert(size == 0);
       return vector<int>(1, 0);
   }
   int primeiro_digito = size/fact[n-1];

   vector<int> resto = get_nth(n-1, size - primeiro_digito * fact[n-1]);
   for(int i = 0; i < resto.size(); i++)
       if(resto[i] >= primeiro_digito)
           resto[i]++;
   resto.insert(resto.begin(), primeiro_digito);

   return resto;
}

int main() {
   fact[0] = 1;
   for(int i = 1; i <= 20; i++)
       fact[i] = i * fact[i-1];

   int n; long long size;
   cin >> n >> size;

   vector<int> ans = get_nth(n, size);
   for(int i = 0; i < ans.size(); i++)
       cout << ans[i] << " ";
   cout << endl;
}
