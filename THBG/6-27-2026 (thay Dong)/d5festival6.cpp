#include "festivallib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;

vector <int> solveGenius(int N ,int S ,const vector <int> &U ,const vector <int > &V)
{
    vector<int> res(2,0);
    if(U.size() == 0) {
        if(S == 1) return {1,2};
        else return {1,1};
    }
    else {
        res[ U[0] ] = 2;
        res[ V[0] ] = 1;
    }
    return res;
}

bool solveCitizen (const vector <int> &A,const vector <vector <int>> & history)
{
    if(A[0] == 1) return 1;
    if(history.size() == 0) return 0;
    return 1;
}

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     #define taskname ""
//     if(fopen(taskname ".inp","r")) {
//         freopen(taskname ".inp","r",stdin);
//         freopen(taskname ".out","w",stdout);
//     }
//     return 0;
// }