#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
deque<char> l,r;

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
    string s,k;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '<') {
            if(!l.empty()) {
                r.push_front(l.back());
                l.pop_back();
            }
        }
        else if(s[i] == '>') {
            if(!r.empty()) {
                l.push_back(r.front());
                r.pop_front();
            }
        }
        else if(s[i] == '-') {
            if(!l.empty()) {
                l.pop_back();
            }
        }
        else l.push_back(s[i]);
    }
    while(!l.empty()) {
        cout << l.front();
        l.pop_front();
    }
    while(!l.empty()) {
        cout << l.front();
        l.pop_front();
    }
    while(!r.empty()) {
        cout << r.front();
        r.pop_front();
    }
    return 0;
}