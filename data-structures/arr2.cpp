#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool desc(int i, int j) { return i > j; }

int main() {

    long long n, k, t, count; cin >> t;
    while(t--)
    {  
        vector<int> a, b;
        cin >> n >> k;
        cout << "Hello" << endl;
        for(int i=0; i<n; i++)
        {
            int p; cin >> p;
            a.push_back(p);
        }
        cout << "Hello" << endl;
        for(int i=0; i<n; i++)
        {
            int p; cin >> p;
            b.push_back(p);
        }
        cout << "Hello" << endl;
        sort(a.begin(), a.end());
        cout << "Hello" << endl;
        sort(b.begin(), b.end(), greater<int>());
        cout << "Hello" << endl;
        count = 0;
        for(int i=0; i<n; i++)
        {
            //for(int j=0;j<n;j++)
           // {
                cout << a[i] << b[i] << endl;
                if(a[i]+b[i] >= k)
                {
                    a[i] = 0; b[i] = 0;
                    count++;
                    //break;
                }
                else
                  break;
//            }
        }
        a.clear();
        b.clear();
        if(count == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

