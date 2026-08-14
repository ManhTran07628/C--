#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
vector<pair<ll,string>> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SORTNUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(isdigit(s[i])) {
            ll tongso = 0,j = i,vt = 0;
            while(isdigit(s[i]) && i < s.size()) {
                tongso += s[i];
                i++;
            }
            string k = "";
            for(int j1 = j;j1 < i;j1++) 
                k += s[j1];
            sort(k.begin(),k.end());
            i--;
            f.push_back({tongso,k});
        }
    }
    sort(f.begin(),f.end());
    string k;
    int j = 0,kt = -1;
    for(int i = 0;i < s.size();i++) {
        if(!isdigit(s[i])) k += s[i];
        if(isdigit(s[i+1]) && !isdigit(s[i]) && i < s.size()) {
            k += f[j].second;
            j++;
            kt = 1;
        }
    }
    if(kt == -1) k += f[0].second;
    cout << k;
    return 0;
}