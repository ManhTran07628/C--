#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll trai[N],phai[N],a[N];

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
    string k;
    cin >> k;
    ll dem = 0;
    for(int i = 0;i < k.size();i++) {
        a[i] = 1;
    }
    trai[0] = 0;
    for(int i = 1;i < k.size();i++) {
        for(char j = 'a';j <= 'z';j++) {
            if(k[i] > j) {
                if(a[j] == 1)
                    trai[i]++;
            }
        }
        if(k[i] > k[i-1]) {
            trai[i] += trai[i-1];
        }
    }
    phai[k.size()-1] = 0;
    for(int i = k.size()-2;i >= 0;i--) {
        for(char j = 'a';j <= 'z';j++) {
            if(k[i] < j) {
                if(a[j] == 1)
                    phai[i]++;
            }
        }
        if(k[i] > k[i+1]) {
            phai[i] += phai-
        }
    }
    for(int i = 0;i < k.size();i++) {
        dem += trai[i] * phai[i];
    }
    cout << dem;
    return 0;
}
