#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define taskname ""
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    ll s, p, r;
    cin >> s >> p >> r;
    ll songaytrc = s / (p - r);
    ll songaychuan = songaytrc - (p / (p - r));
    if (songaychuan * (p - r) + p < s)
    {
        songaychuan++;
    }
    ll sng = songaychuan % 7;
    cout << songaychuan << " ";
    if (sng == 0)
        cout << 3;
    else if (sng == 1)
        cout << 4;
    else if (sng == 2)
        cout << 5;
    else if (sng == 3)
        cout << 6;
    else if (sng == 4)
        cout << 0;
    else if (sng == 5)
        cout << 1;
    else if (sng == 6)
        cout << 2;
    return 0;
}
// thu 4-1 thu 5-2 thu 6-3 thu7-4 thu8-5 thu2-6 thu3-7
