#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  char input[100001];
  cin >> input;
  int len;
  for(len=0; input[len]!='\0'; len++);
  
  vector<int> a;
  for(int i=0; i<26; i++)
  {
    int p;p = 0; 
    a.push_back(p);
  }
  for(int i=0; input[i]!='\0'; i++)
  {
    if((int)input[i]-97 >= 0)
    {
      a[(int)input[i]-97]++;
    }
  }
  int count = 0, count1 = 0, tot = 0;
  for(int j=0; j<26; j++)
  {
    //cout << a[j] << endl;
    if(a[j]%2==0 && a[j]!=0)
      count++;
    if(a[j]%2==1)
      count1++;
    else {}
    if(a[j]!=0) tot++;
  }
  //cout << count << " " << count1 << " " << tot << endl;
  if((count==tot && len%2==0) || (count==tot-1 && count1==1 && len%2==1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
