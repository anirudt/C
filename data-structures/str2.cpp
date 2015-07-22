#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int t; cin >> t;
  char a[100001], b[100001];
  while(t--)
  {
    cin >> a; cin >> b;
    vector<int> a_, b_, ans;
    int c=0;
    for(int i=0; i<26; i++)
    {
      int p; p=0;
      a_.push_back(p);
      b_.push_back(p);
      ans.push_back(p);
    }
    for(int i=0; a[i]!='\0'; i++)
      a_[(int)a[i] - 97]++; 
    for(int i=0; b[i]!='\0'; i++)
      b_[(int)b[i] - 97]++;
    for(int i=0; i<26; i++)
      ans[i] = a_[i] * b_[i];
    for(int i=0; i<26; i++)
      c += ans[i];
    if(c>=1) cout << "YES" << endl;
    else     cout << "NO"  << endl;
  }
  return 0;
}
