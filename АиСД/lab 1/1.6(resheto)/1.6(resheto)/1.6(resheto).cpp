#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int *a = new int[n + 1];
  for (int i = 0; i < n + 1; i++)
    a[i] = i;
  for (int p = 2; p <= sqrt(n); p++)
  {
    if (a[p] != 0)
    {
      for (int j = p*p; j < n + 1; j += p)
        a[j] = 0;
    }
  }
  if (a[n] != 0) cout << "prostoe";
  else cout << "ne prostoe";
}
// S(l)=n+1 Емкостная сложность 
// T(l)=c*n^3 Временная сложность  
// l=n+1 Размерность
// полиномиальныq алгоритм