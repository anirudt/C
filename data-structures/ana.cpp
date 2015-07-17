#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  char A[10001], B[10001];
  cin >> A; cin >> B;
  vector<int> a, b;
  for(int i=0; i<26; i++)
  {
    int p; p=0;
    a.push_back(p);
    b.push_back(p);
  }
  int len1, len2;
  for(len1=0; A[len1]!='\0'; len1++);
  for(len2=0; B[len2]!='\0'; len2++);
  for(int i=0; i<len1; i++)
    a[(int)A[i] - 97]++;
  for(int i=0; i<len2; i++)
    b[(int)B[i] - 97]++;
  int ans = 0;
  for(int i=0; i<26; i++)
    ans += abs(a[i] - b[i]);
  cout << ans << endl;
  return 0;
}
