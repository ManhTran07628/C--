#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+1;
string a[N],lt = "";
int c[N],n;
vector<string> b;

void timmax()
{
    string ans = "";
    for(auto c: b) {
        ans += c;
    }
    if(lt < ans) lt = ans;
}


void quaylui(int k)
{
    if(k == n) {
        timmax();
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(c[i] == 0) {
            c[i] = 1;
            b.push_back(a[i]);
            quaylui(k+1);
            b.pop_back();
            c[i] = 0;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tâm béo"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    quaylui(0);
    sort(a+1,a+n+1);
    cout << lt;
    return 0;
}