#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool desc(int i, int j) { return i > j; }

int main()
{
  int n, k;
  vector<int> c, num;
  cin >> n >> k;
  for(int i=0; i<n; i++)
  {
    int p; cin >> p;
    c.push_back(p);
  }
  for(int i=0; i<k; i++)
  {
    num.push_back(0);
  }
  sort(c.begin(), c.end(), desc);
  int i=0, j=0, sum=0;
  while(i<n)
  {
    if(j!=k)
    {
      sum += (num[j]+1)*c[i];
      num[j]++;
      j++;
    }
    else
    {
      j = 0;
      sum += (num[j]+1)*c[i];
      num[j]++;
      j++;
    }
    i++;
  }
  cout << sum << endl;
  return 0;
}
