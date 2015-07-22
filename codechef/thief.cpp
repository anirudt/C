#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t, x, y, m;
  vector<int> mas;
  for(int i=0; i<101;i++)
  {
    int p; p=0;
    mas.push_back(p);
  }
  cin >> t;
  while(t--)
  {
    cin >> m >> x >> y;
    vector<int> pol, saf;
    for(int i=0; i<m ;i++)
    {
      int p; cin>>p;
      pol.push_back(p);
    }
    for(int i=0; i<m; i++)
    {
      for(int j=max(pol[i]-x*y, 1); j<=min(pol[i]+x*y,100); j++)
      {
        mas[j]=1;
      }
    }
    int c = 0;
    for(int i=1; i<101; i++)
    {
      if(mas[i]==0)
      {
        c++;
      }
    }
    cout << c << endl;
    for(int i=1; i<101; i++)
    {
      mas[i]=0;
    }
  }
  return 0;
}
