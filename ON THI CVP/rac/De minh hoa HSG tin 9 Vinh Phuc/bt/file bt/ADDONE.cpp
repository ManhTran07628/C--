#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
     string a,b = "1";
    string kq;
    cin >> a;
    int test = 0;
    int nho = 0;
    while(a.size() != b.size()) {
        if(a.size() < b.size()) {
            a = '0' + a;
        }
        else b = '0' + b;
    }
    kq = a;
    for(int i = a.size() - 1;i >= 0;i--) {
        test = a[i] - '0' + b[i] - '0' + nho;
        nho = test / 10;
        kq[i] = char((test % 10) + '0');
    }
    if(nho == 1) {
        kq = '1' + kq;
    }
    cout << kq;
    return 0;
}