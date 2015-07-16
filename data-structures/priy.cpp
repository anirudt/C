#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N; cin >> N;
    int min, sum=1;
    vector<int> w;
    for(int i=0; i<N; i++)
    {
      int p; cin >> p;
      w.push_back(p);
    } 
    sort(w.begin(), w.end());
    min = w[0];
    int i = 1;
    while(i < N)
    {
      if(w[i]<=min + 4)
      {
        sum = sum;
      }  
      else
      {
        sum++;
        min = w[i];
      }
      i++;
    }
    cout << sum <<endl;
    return 0;
}
    
    
