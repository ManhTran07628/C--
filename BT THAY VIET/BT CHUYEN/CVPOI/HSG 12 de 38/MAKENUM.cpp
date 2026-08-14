#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int lim = 32000;
int prime[MM];
vector<int> primes;

void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;

    for(int i = 2;i < MM;i++)
        if(prime[i]) 
            primes.push_back(i);
}

struct Node
{
    Node *child[20];
    int exist = 0;
    Node() {for(int i = 0;i <= 10;i++) child[i] = nullptr;}
};

Node *root;

void createNode() {root = new Node();}

void add_nums(int a)
{
    Node *p = root;
    string s = to_string(a);
    for(auto c:s) {
        if(p -> child[c - '0'] == nullptr) p -> child[c - '0'] = new Node();
        p = p -> child[c - '0'];
    }
    p -> exist++;
}

void dfs(Node *p,int nums)
{
    for(int i = 1;i <= p -> exist;i++) cout << nums;

    for(int i = 9;i >= 0;i--) {
        if(p -> child[i] == nullptr) continue;
        dfs(p -> child[i],nums * 10 + i);
    }
}

vector<int> fac;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll n; cin >> n;
    createNode();
    for(auto p:primes) {
        while(n % p == 0) {
            fac.push_back(p);
            n /= p;
        }
    }
    if(n > 1) fac.push_back(n);

    for(auto x:fac) {
        cout << x << ' ';
        add_nums(x);
    }
    dfs(root,0);
    return 0;
}