#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t; cin >> t;
  while(t--)
  { 
    string s; cin >> s;
    int c = 0, n = s.size();
    for(int i=0; i<n; i++)
      c += abs((int)s[i] - (int)s[n-1-i]);
    cout << c/2 << endl;  
  }
  return 0;
}
