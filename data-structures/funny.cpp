#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  char str[10001];
  int t; cin >> t;
  
  while(t--)
  {
    cin >> str;
    int len, i, count=0;
    for(len=0; str[len]!='\0'; len++);
    for(i=1; i<len-1; i++)
    {
      //cout << str[i] << " " << str[i-1] << " " << str[len-2-i] << " " << str[len-i-1] << endl;
      if(abs(str[i]-str[i-1])==abs(str[len-1-i]-str[len-i]))
        count++;
      else
        break;
    }
    if(count==len-2)
      cout << "Funny" << endl;
    else
      cout << "Not Funny" << endl;
  }
}
