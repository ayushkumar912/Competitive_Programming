/**
 *    author:  AYUSH KUMAR
 *    created: 28.09.2024 13:25:14
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pi tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define char unsigned char
#define sz(a) ((int)(a.size()))
#define input(arr) for(auto &x: arr) cin >> x;
#define output(arr, ...) for(auto &x: arr) cout << x << __VA_ARGS__;
#define tcon(cond) ((cond) ? "YES" : "NO")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<pll>> vvpl;
typedef vector<vector<ll>> vvll;
const int MOD =1e9 + 7;
const int eps = 1e-9;
int cO(const string &s) {
    int c = 0;
    for (char ch : s) {
        c += (ch == '1');
    }
    return c;
}

int eO(int o) {
    return (o % 2 == 0) ? 0 : 1;
}

void rN(int n) {
    cout << n << endl;
}

void pR(int o) {
    cout << eO(o) << endl;
}

void hS(const string &s) {
    int o = cO(s);
    if (o == 0) {
        rN(s.length());
    } else {
        pR(o);
    }
}

void Ayush() {
  int n;
        cin >> n;
        string s;
        cin >> s;
        hS(s);
}

int32_t main() {
    io;
    int t,Case =0;
    // t=1;
    cin >> t;
    while (t--) {
      Case++;  
       debug(Case);
        Ayush();
    }

    return 0;
}