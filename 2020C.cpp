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
map<tuple<ll,ll,ll>,ll> mp;
mp[{0,0,0}]=0;
mp[{0,0,1}]=1;
mp[{0,1,0}]=0;
mp[{0,1,1}]= -1;
mp[{1,0,0}]= -1;
mp[{1,0,1}]=0;
mp[{1,1,0}]=1;
mp[{1,1,1}]=0;

 ll a=0, b,c,d;
 cin>>b>>c>>d;
 for (int i=60;i>=0;i--){
  ll  I=(((1ll<<i)&b)!=0);
  ll  J=(((1ll<<i)&c)!=0);
  ll  K=(((1ll<<i)&d)!=0);
  ll X= mp[{I,J,K}];
  if(X == -1){
    a= -1;
    break;
  }
  else{
    a+=X *(1ll << i);
  }
 
 }
  cout<<a<<endl; 

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