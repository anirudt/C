#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> a;
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    int p; cin >> p;
    a.push_back(p);
  }
  for(int i : a)
  {
    cout << i << endl;
  }
  a.clear();
  cout << a.size() << endl;
  return 0;
}
