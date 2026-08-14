#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<char> a;
ll n;

void inkq()
{
    for(auto c:a) {
        cout << c;
    }
    cout << endl;
}

void nhiphan(ll k)
{
    //if(a[a.size()-1] == a[a.size()-2]) return;
    if(k == n) {
        inkq();
        return;
    }
    for(char i = 'A';i <= 'C';i++) {
        a.push_back(i);
        nhiphan(k+1);
        a.pop_back();
    }
}

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
    cin >> n;
    nhiphan(0);
    return 0;
}