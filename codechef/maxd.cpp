#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t; cin>>t;
  long long sum;
  while(t--)
  {
    vector<int> a;
    int n, d; cin >> n >> d; 
    for(int i=0; i<n; i++)
    {
      int p; cin >> p;
      a.push_back(p);
    }
    sort(a.begin(), a.end());
    sum = 0;
    for(int i=a.size()-1; i>=1; i--)
    {
      if(a[i]-a[i-1]<d)
      {
        sum+=a[i]+a[i-1];
        i--;
      }

    } 
    cout << sum << endl; 

  }
  return 0;
}
