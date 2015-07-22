#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t; cin >> t;
  long long sum;
  while(t--)
  {
    sum = 0;
    int n; cin >> n;
    vector<int> a;
    for(int i=0; i<n;i++)
    {
      int p; cin>>p;
      a.push_back(p);
    }
    for(int i=0; i<n;i++)
    {
      for(int j=i+1; j<n; j++)
      {
        for(int k=j+1; k<n; k++)
        {
          for(int l=k+1; l<n; l++)
          {
            sum += 2*(abs(a[i]+a[j]-a[k]-a[l]) + abs(a[i]+a[k]-a[j]-a[l]) +
                   abs(a[i]+a[l]-a[j]-a[k]));
          }
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
