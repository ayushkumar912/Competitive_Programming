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
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define char unsigned char
#define sz(a) ((int)(a.size()))
#define input(arr) for(auto &x: arr) cin >> x;
#define output(arr, ...) for(auto &x: arr) cout << x << __VA_ARGS__;
#define tcon(cond) ((cond) ? "Yes" : "No")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
const ll MOD = 1e9 + 7;
const ld eps = 1e-9;


void Ayush() {
int n;
    cin >> n;
    string s;
    cin >> s;
    debug(s);
int cnt1=0,cnt0=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt1++;
            debug(cnt0);
        } else {
            if (i == 0 || s[i] != s[i - 1]) {
                cnt0++;
            }
            debug(cnt1);
        }
    }
cout<<tcon(cnt1 > cnt0)<<endl;
}

int32_t main() {
    io;
    int t;
    // t=1;
    cin >> t;
    while (t--) {
        // cerr<<"case:"<<t<<endl;
        Ayush();
    }

    return 0;
}