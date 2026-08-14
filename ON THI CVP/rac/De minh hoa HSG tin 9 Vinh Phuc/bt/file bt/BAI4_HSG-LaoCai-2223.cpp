#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TAOXAU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
//    string x,y = "";
//    cin >> x;
//    for(int i = 0;i < x.size();i++) {
//        y += x[i];
//        reverse(y.begin(),y.end());
//    }
//    cout << y;



    string x,y = "";
    cin >> x;
    if(x.size() % 2 == 0) {
        for(int i = x.size()-1;i >= 0;i -= 2) {
            y += x[i];
        }
        for(int i = 0;i < x.size();i+=2) {
            y += x[i];
        }
        cout << y;
    }
    else {
        for(int i = x.size()-1;i >= 0;i -= 2) {
            y += x[i];
        }
        for(int i = 1;i < x.size();i+=2) {
            y += x[i];
        }
        cout << y;
    }
    return 0;
}
// abcd -> dbac
// abcde -> ecabd
