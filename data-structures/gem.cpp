#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int N; cin >> N;
  vector<int> a, a_prev, flags;
  for(int i=0; i<26; i++)
  {
    int p1, p2; p1=1,p2=0;
    a.push_back(p2); a_prev.push_back(1);
    flags.push_back(p1);
  }
  while(N--)
  {
    char str[101]; cin >> str;
    for(int i=0; i<26; i++)
    {
      int p; p=0;
      a.push_back(p);
    }
    for(int i=0; str[i]!='\0'; i++)
    {
      a[(int)str[i] - 97]=1;
    }
    for(int i=0; i<26; i++)
    {
      flags[i] = flags[i] * a[i] * a_prev[i];  
      a_prev[i] = a[i];  
    }
    a.clear();
  }
  int ans=0;
  for(int i=0; i<26; i++)
    if(flags[i]==1) ans++;
  cout << ans << endl;  
  return 0;
}
