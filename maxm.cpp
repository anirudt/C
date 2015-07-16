#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  long long n, k, min;
  vector<int> a;
  cin >> n >> k;
  for(int i=0; i<n; i++)
  {
    int p; cin >> p;
    a.push_back(p);
  }
  stable_sort(a.begin(), a.end());
  for(int i=0; i<=n-k; i++)
  {
    if(a[i+k-1] - a[i] < min)
      min = a[i+k-1] - a[i];
  }
  cout << min << endl;
  return 0;
}
