#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long fun(vector<int> a)
{
  if(a.size()==1)
    return a[0];
  vector<int> x;
  for(int i=1;i<a.size(); i++)
  {
    int p; p = a[i];
    x.push_back(p);
  }
  return pow(a[0], fun(x));
}


int main()
{
  int n, m, t; cin >> t;
  while(t--)
  {
    cin >> n >> m;
    vector<int> a, copya, earl;
    for(int i=0; i<n; i++)
    {
      int p; cin >> p;
      a.push_back(p);
      copya.push_back(p);
    }
    long long sum;
    sort(a.begin(), a.end());
    sum += fun(a);
    while(earl != a)
    {  
      earl = a;
      next_permutation(a.begin(), a.end());
      for(int j: a)
        cout << j << " ";
      cout << endl;  
      sum += fun(a);
    }
    cout << sum%m << endl;
  }
  return 0;
}
