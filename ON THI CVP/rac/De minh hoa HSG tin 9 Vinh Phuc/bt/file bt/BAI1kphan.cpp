#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;
ll n,k;
void inkq()
{
    for(auto c:a) {
        cout << c;
    }
    cout << '\n';
}

void quaylui(ll j)
{
    if(j == n) {
        inkq();
        return;
    }
    for(int i = 0;i < k;i++) {
        a.push_back(i);
        quaylui(j+1);
        a.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "kphan"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    quaylui(0);
    return 0;
}