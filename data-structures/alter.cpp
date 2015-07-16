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
    char str[100001]; cin >> str;
    int len = 0;
    for(len=0; str[len]!='\0'; len++);
    int count = 0;
    for(int i=0; i<len-1; i++)
    {
      if(str[i]==str[i+1]) count++;
    }
    cout << count << endl;
  }
  return 0;
}
