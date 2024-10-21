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


void Ayush() {
 ll n,k;
 cin>>n>>k;
vector <pii> a(n);
 for(int i=0;i<n;i++){
    cin>>a[i].first;
    a[i].second=i;
 }
 sort(all(a));
int ans = 1;
for (int i = 1; i < n; i++){
	if (a[i - 1].second + 1 != a[i].second)
     ans++;
}
debug(a);
cout<<tcon(ans<=k)<<endl;
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