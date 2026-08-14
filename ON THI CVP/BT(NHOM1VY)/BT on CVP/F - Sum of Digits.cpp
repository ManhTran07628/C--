#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }  
    string n;
    cin >> n;
    if(n.size() == 1) {
        cout << 0;
        return 0;
    }
    int m = 0,cnt = 1;
    for(auto i:n) m += i - '0';
    while(m > 9) {
        int m1 = m,sum = 0;
        while(m1 > 0) {
            sum += (m1 % 10);
            m1 /= 10;                
        }
        m = sum;
        cnt++;
    }
    cout << cnt;
    return 0;
}