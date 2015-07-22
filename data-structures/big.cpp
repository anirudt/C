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
    string k = s;
    next_permutation(s.begin(), s.end());
    if(s!=k)
      cout << s << endl;
    else
      cout << "no answer" << endl;
  }
  return 0;
}
