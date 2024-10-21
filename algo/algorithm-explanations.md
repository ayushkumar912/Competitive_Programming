# Comprehensive Algorithm Explanations

## 1. Binary Exponentiation (binpow)

### Name
Binary Exponentiation

### Time Complexity
O(log b)

### Input Required
- `a`: Base (long long)
- `b`: Exponent (long long)
- `m`: Modulus (long long, optional)

### Output
Returns `a^b mod m` (long long)

### Data Types
- Input: long long
- Output: long long

### Explanation
Binary exponentiation, also known as exponentiation by squaring, is an efficient algorithm for calculating large powers. It works by breaking down the exponent into its binary representation and using the properties of exponents to reduce the number of multiplications needed.

The algorithm takes a base `a`, an exponent `b`, and an optional modulus `m`. It iteratively squares the base and multiplies it to the result when the corresponding bit in the binary representation of the exponent is 1. This process continues until all bits of the exponent have been processed.

If a modulus is provided, all operations are performed modulo this value, which allows for calculations with very large numbers without overflow.

### Code
```cpp
ll binpow(ll a, ll b, ll m = 1e9 + 7) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

## 2. Extended Euclidean Algorithm (extEuclid)

### Name
Extended Euclidean Algorithm

### Time Complexity
O(log(min(a, b)))

### Input Required
- `a`, `b`: Numbers to find GCD (long long)
- `x`, `y`: References to variables that will store coefficients (long long)

### Output
Returns GCD of a and b (long long), and modifies x and y to satisfy the equation ax + by = gcd(a,b)

### Data Types
- Input: long long
- Output: long long, and modifies long long references

### Explanation
The Extended Euclidean Algorithm is an extension of the Euclidean algorithm for finding the greatest common divisor (GCD) of two numbers. In addition to finding the GCD, it also finds the coefficients of Bézout's identity, which are integers x and y such that:

ax + by = gcd(a, b)

The algorithm works recursively, starting with the initial equation and breaking it down into smaller subproblems. At each step, it expresses the GCD of the current pair of numbers in terms of the GCD of the next pair (which are the smaller of the two numbers and the remainder of their division).

As the recursion unwinds, it builds up the coefficients x and y for the original equation.

### Code
```cpp
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```

## 3. Sieve of Eratosthenes (seive)

### Name
Sieve of Eratosthenes

### Time Complexity
O(n log log n)

### Input Required
- `n`: Upper limit to find primes (int)

### Output
Boolean vector `is_prime` where `is_prime[i]` is true if i is prime

### Data Types
- Input: int
- Output: vector<bool>

### Explanation
The Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to a given limit. It works by iteratively marking the multiples of each prime number as composite, starting from 2.

The algorithm begins by creating a boolean array of size n+1, initially all set to true. It then iterates from 2 to sqrt(n). For each number i that is still marked as prime, it marks all multiples of i as composite, starting from i*i (as all smaller multiples would have been marked by smaller primes).

After the iteration, all numbers still marked as true are prime.

### Code
```cpp
int n = MOD;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

## 4. Totient Function (phi)

### Name
Euler's Totient Function

### Time Complexity
O(sqrt(n))

### Input Required
- `n`: Number to calculate phi for (int)

### Output
Returns φ(n) (int)

### Data Types
- Input: int
- Output: int

### Explanation
Euler's Totient Function, denoted as φ(n), counts the number of integers up to n that are coprime to n. Two numbers are considered coprime if their greatest common divisor is 1.

The algorithm calculates φ(n) by using the product formula:

φ(n) = n * product of (1 - 1/p) for all prime factors p of n

It iterates through potential prime factors up to sqrt(n), reducing n as it finds factors. If n is still greater than 1 after this process, it means n itself is prime, and we account for this in the final step.

### Code
```cpp
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
```

## 5. Totient Function from 1 to n (phi1ton)

### Name
Euler's Totient Function for Range [1, n]

### Time Complexity
O(n log log n)

### Input Required
- `n`: Upper limit (int)

### Output
Modifies vector `phi` where `phi[i]` contains φ(i)

### Data Types
- Input: int
- Output: vector<int>

### Explanation
This algorithm efficiently calculates Euler's totient function for all numbers from 1 to n using a sieve-like approach. It's based on the multiplicative property of the totient function and the fact that for a prime p, φ(p) = p - 1.

The algorithm starts by initializing phi[i] = i for all i. Then, for each prime number p it encounters, it updates phi[j] for all multiples j of p by multiplying by (1 - 1/p). This is equivalent to subtracting phi[j] / p from phi[j].

### Code
```cpp
void phi1toN(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```

## 6. Modular Inverse (inv)

### Name
Modular Multiplicative Inverse

### Time Complexity
O(log m)

### Input Required
- `i`: Number to find inverse for (long long)
- `m`: Modulus (long long, optional, default: MOD)

### Output
Returns modular multiplicative inverse of i modulo m (long long)

### Data Types
- Input: long long
- Output: long long

### Explanation
The modular multiplicative inverse of an integer a modulo m is an integer x such that ax ≡ 1 (mod m). This algorithm finds the modular inverse using the property of Fermat's Little Theorem, which states that for a prime modulus p, a^(p-1) ≡ 1 (mod p) for any a not divisible by p.

From this, we can derive that a^(p-2) is the modular inverse of a modulo p. The algorithm uses this fact along with binary exponentiation to efficiently compute the inverse.

Note that this method only works when the modulus is prime. For non-prime moduli, you would need to use the extended Euclidean algorithm instead.

### Code
```cpp
ll inv(ll i, ll m = MOD) {
    return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}
```

## 7. Factorial Modulo (factmod)

### Name
Factorial Modulo

### Time Complexity
O(p + log n)

### Input Required
- `n`: Number to calculate factorial for (int)
- `p`: Modulus (int)

### Output
Returns n! mod p (int)

### Data Types
- Input: int
- Output: int

### Explanation
This algorithm calculates n! mod p efficiently, even for large values of n. It's based on Wilson's theorem and the properties of modular arithmetic.

The algorithm first calculates the factorials modulo p for all numbers less than p using a simple loop. Then, it uses these precomputed values along with Wilson's theorem to calculate larger factorials.

Wilson's theorem states that for a prime p, (p-1)! ≡ -1 (mod p). Using this, we can break down n! into smaller factorials and use the precomputed values.

### Code
```cpp
int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;
    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}
```
## 8. Is Inside Boundary (isin)
 ###  Name
  Is Inside Boundary
### Time Complexity
 O(1)
 ### Input Required
 - `x`, `y`: Coordinates to check (int)
 - `row`, `col`: Boundaries (int)
 ### Output
  Returns true if (x, y) is inside the boundary, false otherwise (bool)
 ### Data Types
 - Input: int
 - Output: bool
 ### Explanation
 This function checks if a given point (x, y) is inside a rectangular boundary defined by (1, 1) and (row, col). It's useful in grid-based problems to ensure that coordinates are valid.
 ### Code
 ```cpp
 bool isIn(int x, int y, int row, int col){
    return x>0 and x<=row and y>0 and y<=col;
 }
```
## 9. dx dy Vectors (dxdy)
### Name
dx dy Vectors
### Time Complexity
N/A (constant-time initialization)
### Input Required
None
### Output
Two arrays `dx` and `dy` representing movement directions
### Data Types
- Output: int arrays
### Explanation
These arrays define the possible movements in a 2D grid, including diagonal movements. They are often used in graph traversal algorithms on 2D grids, such as BFS or DFS.
### Code
```cpp
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
```

## 10. Input for a Vector String (maze)
### Name
Input for a Vector String
### Time Complexity
O(n * m), where n and m are the dimensions of the maze
### Input Required
- `n`, `m`: Dimensions of the maze (int)
### Output
Populates a 2D vector `maze` with characters
### Data Types
- Input: int
- Output: vector<vector<char>>
### Explanation
This code snippet reads a 2D character grid (often representing a maze or game board) from standard input. It's useful for problems involving 2D grids or matrices.
### Code
```cpp
vector<vector<char>> maze(n+1, vector<char> (m+1));
for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
        cin >> maze[i][j];
    }
}
```

## 11. Disjoint Set Union (dsu)
### Name
Disjoint Set Union (DSU) or Union-Find
### Time Complexity
- Find: O(α(n)) amortized
- Union: O(α(n)) amortized
where α(n) is the inverse Ackermann function
### Input Required
- `n`: Number of elements in the set (T)
### Output
A DSU data structure with methods for union and find operations
### Data Types
- Input: Template type T (usually int)
- Output: Various methods returning T or void
### Explanation
This class implements the Disjoint Set Union data structure, also known as Union-Find. It's used to efficiently manage a partition of a set into disjoint subsets. It supports two main operations: union (merge two sets) and find (determine which set an element belongs to). This implementation includes both union by rank and union by size optimizations, as well as path compression for the find operation.
### Code
```cpp
template <typename T>
class DisjointSetUnion {
    vector<T> rank, parent, size; 
public: 
    DisjointSetUnion(T n) {
        rank.resize(n+1, 0); 
        size.resize(n+1, 1); 
        parent.resize(n+1);
        for(T i = 0;i<=n;i++) {
            parent[i] = i; 
        }
    }
    
    T findUPar(T node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }
    
    void unionByRank(T u, T v) {
        T ulp_u = findUPar(u); 
        T ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    
    void unionBySize(T u, T v) {
        T ulp_u = findUPar(u); 
        T ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
```

## 12. Lowest Common Ancestor (Binary Lifting) (lca)
### Name
Lowest Common Ancestor (LCA) using Binary Lifting
### Time Complexity
- Preprocessing: O(N log N)
- Query: O(log N)
where N is the number of nodes in the tree
### Input Required
- `n`: Number of nodes in the tree (int)
- `adj`: Adjacency list representing the tree (vector<vector<int>>)
- `root`: Root of the tree (int, optional, default: 1)
### Output
A TreeAncestor object with methods to query LCA and kth ancestor
### Data Types
- Input: int, vector<vector<int>>
- Output: Various methods returning int
### Explanation
This class implements the Binary Lifting algorithm to efficiently solve the Lowest Common Ancestor problem on a tree. It preprocesses the tree to allow for fast LCA queries and k-th ancestor queries. The algorithm uses a sparse table approach, storing ancestors at power-of-two distances for each node.
### Code
``` cpp
class TreeAncestor {
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    void dfs(int currNode, vector<vector<int>> &adj, int currDepth) {
        depth[currNode] = currDepth;
        for(int nxtNode : adj[currNode]) {
            if(depth[nxtNode] == -1){
                up[nxtNode][0] = currNode;
                for(int j = 1; j<LOG; j++){
                    up[nxtNode][j] = up[ up[nxtNode][j-1] ][j-1];
                }
                dfs(nxtNode, adj, currDepth+1);
            }
        }
    }

public:
    TreeAncestor(int n, vector<vector<int>> &adj, int root = 1) {
        LOG = ceil(log2(n+1));
        up = vector<vector<int>>(n+1, vector<int>(LOG));
        depth = vector<int>(n+1, -1);
        dfs(root, adj, 0);
    }

    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = LOG - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }

  int get_lca(int a, int b) { // O(log(N))
        if(depth[a] < depth[b]) {
            swap(a, b);
        }
        // 1) Get same depth.
        int k = depth[a] - depth[b];
        for(int j = LOG - 1; j >= 0; j--) {
            if(k & (1 << j)) {
                a = up[a][j]; // parent of a
            }
        }
        // 2) if b was ancestor of a then now a==b
        if(a == b) {
            return a;
        }
        // 3) move both a and b with powers of two
        for(int j = LOG - 1; j >= 0; j--) {
            if(up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
};
```
### Additional Explanation
The `get_lca` function efficiently finds the Lowest Common Ancestor of two nodes a and b:
1. It first ensures that a is deeper in the tree than b.
2. It then brings a up to the same depth as b using binary lifting.
3. If a and b are now the same, that node is the LCA.
4. Otherwise, it moves both a and b up the tree in tandem, using the largest possible jumps that keep them below their LCA.
5. The parent of the final positions of a and b is their LCA.

This method allows for LCA queries in O(log N) time complexity.



This completes the explanations for all the provided algorithms and data structures.


## 13. Checking cycle in directed graph (iscycle)
### Name
Is Cycle in Directed Graph
### Time Complexity
O(V + E), where V is the number of vertices and E is the number of edges
### Input Required
- `adj`: Adjacency list representing the graph (vector<vector<int>>)
- `n`: Number of nodes in the graph (int)
### Output
Returns true if the graph contains a cycle, false otherwise (bool)
### Data Types
- Input: vector<vector<int>>, int
- Output: bool
### Explanation
This function detects whether a directed graph contains a cycle using Kahn's algorithm for topological sorting. It works by repeatedly removing nodes with no incoming edges. If all nodes are removed, the graph is acyclic. If nodes remain after the process, a cycle exists.
### Code
```cpp
bool isCycle(vvi &adj, int n){
    vector<int> inDegree(n, 0);
    queue<int> q;
    int vis = 0;

    for(int i = 0; i<n; i++){
        for(auto nxt: adj[i]){
            inDegree[nxt]++;
        }
    }

    for(int i = 0; i<n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        vis++;
        for(auto nxt: adj[curr]){
            inDegree[nxt]--;
            if(inDegree[nxt] == 0){
                q.push(nxt);
            }
        }
    }

    return vis!=n;
}
```

## 14. Topological Sorting (topo)
### Name
Topological Sorting
### Time Complexity
O(V + E), where V is the number of vertices and E is the number of edges
### Input Required
- `adj`: Adjacency list representing the graph (vector<vector<int>>)
- `ans`: Vector to store the topological order (vector<int>&)
### Output
Populates the `ans` vector with nodes in topological order
### Data Types
- Input: vector<vector<int>>, vector<int>&
- Output: void
### Explanation
This function performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS). It visits nodes in depth-first order and adds them to the answer vector after all their dependencies have been processed. The result is reversed at the end to get the correct topological order.
### Code
```cpp
void dfs(int curr,vvi &adj, vi &ans, vb &vis){
    vis[curr] = true;
    for(auto nxt: adj[curr]){
        if(vis[nxt]) continue;
        dfs(nxt, adj, ans, vis);
    }
    ans.push_back(curr);
}

void topoSort(vvi &adj, vi &ans){
    int n = adj.size();
    vector<bool> vis(n, false);
    for(int i = 0; i<n; i++){
        if(vis[i] == true) continue;
        dfs(i, adj, ans, vis);
    }
    reverse(ans.begin(), ans.end());
}
```

## 15. KMP Algorithm (kmp)
### Name
KMP (Knuth-Morris-Pratt) Algorithm
### Time Complexity
O(n), where n is the length of the string
### Input Required
- `s`: The string to process (string)
### Output
Returns the prefix function (vector<int>)
### Data Types
- Input: string
- Output: vector<int>
### Explanation
The KMP algorithm computes the prefix function of a string, which for each position i gives the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring. This function is crucial for efficient string matching and can be used to find all occurrences of a pattern in a text in linear time.
### Code
```cpp
vector<int> prefix_function(string s) {  // KMP
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
```

## 16. Z-Function (zfun)
### Name
Z-Function
### Time Complexity
O(n), where n is the length of the string
### Input Required
- `s`: The string to process (string)
### Output
Returns the Z-array (vector<int>)
### Data Types
- Input: string
- Output: vector<int>
### Explanation
The Z-function computes an array Z where Z[i] is the length of the longest substring starting from s[i] which is also a prefix of s. This function is useful in various string matching problems and can be used as an alternative to KMP in many scenarios.
### Code
```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
```

## 17. Trie (trie)
### Name
Trie (Prefix Tree)
### Time Complexity
- Insert: O(L), where L is the length of the word
- Search: O(L), where L is the length of the word
- StartsWith: O(L), where L is the length of the prefix
### Input Required
Varies by operation (string for insert, search, and startsWith)
### Output
Varies by operation (void for insert, bool for search and startsWith)
### Data Types
- Input: string
- Output: varies
### Explanation
A Trie is an efficient data structure for storing and searching strings. It's particularly useful for prefix-based operations. This implementation includes methods for inserting words, counting words, and counting prefixes. It also supports erasing words from the trie.
### Code
```cpp
struct Node {
    Node *links[26];
    int cntPrefix = 0, cntEnd = 0;
    
    Node* get(char key) {
        return links[key - 'a'];
    }
    void put(char key, Node* node) {
        links[key - 'a'] = node;
    }
    bool containsKey(char key) {
        return links[key - 'a'] != NULL;
    }
    int getEnd(){
        return cntEnd;
    }
    int getPrefix(){
        return cntPrefix;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void increaseEnd(){
        cntEnd++;
    }
    void decreasePrefix(){
        cntPrefix--;
    }
    void decreaseEnd(){
        cntEnd--;
    }
};

class Trie{
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node *curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i], new Node());
            }
            curr = curr->get(word[i]);
            curr->increasePrefix();
        }
        curr->increaseEnd();
    }
    int countWordsEqualTo(string word){
        Node *curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr->containsKey(word[i])) return 0;
            curr = curr->get(word[i]);
        }
        return curr->getEnd();
    }
    int counttStartsWith(string word){
        Node *curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr->containsKey(word[i])) return 0;
            curr = curr->get(word[i]);
        }
        return curr->getPrefix();
    }
    void erase(string word){
        Node *curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr->containsKey(word[i])){
                return;
            }
            curr = curr->get(word[i]);
            curr->decreasePrefix();
        }
        curr->decreaseEnd();
    }
};
```
  