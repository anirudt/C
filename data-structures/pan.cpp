#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  char input[1001], in[1001];
  cin.getline(input, sizeof(input));
  for(int i=0; input[i]!='\0'; i++)
  {
    if(input[i]>='A' && input[i]<='Z') in[i] = input[i] + 32;
    else in[i] = input[i];
  }
  vector<int> a;
  for(int i=0; i<26; i++)
  {
    int p;p = 0; 
    a.push_back(p);
  }
  for(int i=0; input[i]!='\0'; i++)
  {
    if((int)in[i]-97 >= 0)
    {
      a[(int)in[i]-97]++;
    }
  }
  int count = 0;
  for(int j=0; j<26; j++)
  {
    if(a[j]>=1)
      count++;
    else
      break;
  }
  if(count==26)
    cout << "pangram" << endl;
  else
    cout << "not pangram" << endl;
  return 0;
}
