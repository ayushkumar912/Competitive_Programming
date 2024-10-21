#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x) 42
#endif
#include <bits/stdc++.h>
using namespace std;
// Function to print various types
void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(const string& t) { cerr << t; }
void _print(char t) { cerr << t; }

// Function to print pairs
template <class T, class V>
void _print(const pair<T, V>& p) {
    cerr << "{"; 
    _print(p.first); 
    cerr << ", "; 
    _print(p.second); 
    cerr << "}";
}

// Function to print vectors
template <class T>
void _print(const vector<T>& v) {
    cerr << "[ "; 
    for (const T& i : v) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "]";
}

// Function to print sets
template <class T>
void _print(const set<T>& s) {
    cerr << "{ "; 
    for (const T& i : s) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "}";
}

// Function to print multisets
template <class T>
void _print(const multiset<T>& ms) {
    cerr << "{ "; 
    for (const T& i : ms) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "}";
}

// Function to print maps
template <class T, class V>
void _print(const map<T, V>& m) {
    cerr << "{ "; 
    for (const auto& i : m) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "}";
}

// Function to print unordered sets
template <class T>
void _print(const unordered_set<T>& us) {
    cerr << "{ "; 
    for (const T& i : us) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "}";
}

// Function to print unordered maps
template <class T, class V>
void _print(const unordered_map<T, V>& um) {
    cerr << "{ "; 
    for (const auto& i : um) {
        _print(i); 
        cerr << " "; 
    } 
    cerr << "}";
}
