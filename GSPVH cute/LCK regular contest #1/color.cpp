#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "color"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string a,b; cin >> a >> b;
    if(a == b) cout << "Same";
    else if((a == "Red" && b == "Green") || (a == "Green" && b == "Red") ||
        (a == "Orange" && b == "Blue") || (a == "Blue" && b == "Orange") ||
        (a == "Yellow" && b == "Purple") || (a == "Purple" && b == "Yellow")) cout << "Complementary";

    else if((a == "Red" && (b == "Purple" || b == "Orange")) || 
        (a == "Purple" && (b == "Red" || b == "Blue")) ||
        (a == "Blue" && (b == "Purple" || b == "Green")) ||
        (a == "Green" && (b == "Blue" || b == "Yellow")) ||
        (a == "Yellow" && (b == "Green" || b == "Orange")) ||
        (a == "Orange" && (b == "Red" || b == "Yellow"))) cout << "Adjacent";

    else if(a == "Red" && b == "Yellow") cout << "Orange";
    else if(a == "Red" && b == "Blue") cout << "Purple";
    else if(a == "Purple" && b == "Orange") cout << "Red"; 
    else if(a == "Purple" && b == "Green") cout << "Blue"; 
    else if(a == "Blue" && b == "Red") cout << "Purple"; 
    else if(a == "Blue" && b == "Yellow") cout << "Green"; 
    else if(a == "Green" && b == "Purple") cout << "Blue";
    else if(a == "Green" && b == "Orange") cout << "Yellow";
    else if(a == "Yellow" && b == "Red") cout << "Orange";
    else if(a == "Yellow" && b == "Blue") cout << "Green";
    else if(a == "Orange" && b == "Green") cout << "Yellow";
    else if(a == "Orange" && b == "Purple") cout << "Red";

    // else cout << "None ";
    return 0;
}