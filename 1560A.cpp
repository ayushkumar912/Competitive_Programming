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

vector<int> a; 

void polycab() {
    a.push_back(0);  
    a.push_back(1);
    a.push_back(2);
    int n = 3; 
    while (a.size() <= 1000) { 
        if (n % 10 == 3 || n % 3 == 0) {
            n++;  
            continue;  
        }
        a.push_back(n);  
        n++; 
    }
}

void Ayush() {
    int n;
    cin >> n;   
    cout << a[n] << endl; 
}
int32_t main() {
    io;
     polycab();
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