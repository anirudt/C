#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t, n, a, b;
  cin >> t;
  int pdt;
  while(t--)
  {
    vector<int> a_, b_;
    cin >> n >> a >> b;
    pdt = 1;
    int p;
    pdt = pdt<<(n-1);
    int sum = 0;
    for(int i=0; i<n; i++)
    {
      if(a>pdt)
      {
        p = 1;
        a = a%pdt;
      }
      else
      {
        p = 0;
      }
      a_.push_back(p);
      if(b>pdt)
      {
        p = 1;
        b = b%pdt;
      }
      else
      {
        p = 0;
      }
      b_.push_back(p);
      pdt = pdt>>1;
    }
    pdt = 1;
    pdt = pdt<<(n-1);
    for(int i=0; i<n; i++)
      sum += (a_[i] + b_[i]);
    sum = sum%n;  
    int ans = 0;  
    for(int i=n-1; i>=n-1-sum; i++)
    {
      pdt >>= 1;
      ans += pdt;
    }
    cout << ans << endl;
  }
  return 0;
}
