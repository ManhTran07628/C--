#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a,b;
ll n;

void inkq() {
    cout << n << "=";
    for(int i = 0; i < a.size(); i++) {
        if(i > 0) cout << "+";
        cout << a[i];
    }
    cout << '\n';
}

void phantich(ll k,ll j)
{
    if(k == n) {
        inkq();
        return;
    }
    for(int i = j;i <= n-k;i++) {
        a.push_back(i);
        phantich(k+i,i);
        a.pop_back();
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "phantich"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    phantich(0,1);
    return 0;
}