#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e7+1;
string a;
ll n;

void nhiphan(ll k)
{
    if(k == n) {
        cout << a;
        cout << '\n';
        return;
    }
    for(char i = '0';i <= '1';i++) {
        a=a+i;
        nhiphan(k+1);
        a.pop_back();
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "nhiphan"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    nhiphan(0);
    return 0;
}