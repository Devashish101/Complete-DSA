// Disjoint Set Union - Union by Size
#include <bits/stdc++.h>
using namespace std;

// Find the representative of x
int find(vector<int>& parent, int x) {

    // If x is its own parent, it is the representative
    if(parent[x] == x)
        return x;

    // Path Compression
    return parent[x] = find(parent, parent[x]);
}

// Union two sets using Size
void unionSet(vector<int>& parent, vector<int>& size, int a, int b) {

    // Find the representatives
    a = find(parent, a);
    b = find(parent, b);

    // Already in the same set
    if(a == b)return;

    // Attach smaller set to larger set
    if(size[a] >= size[b]) {
        parent[b] = a;
        size[a] += size[b];

    } else {
        parent[a] = b;
        size[b] += size[a];
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> parent(n + 1);

    // Initially, every set has size 1
    vector<int> size(n + 1, 1);

    // Initially, every element is its own parent
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int m; // Number of queries
    cin >> m;
    while(m--) {

        string str;
        cin >> str;
        if(str == "union") {
            int x, y;
            cin >> x >> y;
            unionSet(parent, size, x, y);

        } else { // find
            int x;
            cin >> x;
            cout << find(parent, x) << "\n";
        }
    }
}

// Disjoint Set Union (DSU) by Rank -> Means how many elements/groups it is directly connected with including itself.
#include <bits/stdc++.h>
using namespace std;

// Find the representative (parent) of x
int find(vector<int>& parent, int x) {

    // If x is its own parent, x is the representative
    if(parent[x] == x)return x;

    // Path Compression
    return parent[x] = find(parent, parent[x]);
}

// Union two sets
void unionSet(vector<int>& parent, vector<int>& rank, int a, int b) {

    // Find the representatives of both sets
    a = find(parent, a);
    b = find(parent, b);

    // If both have the same parent, they are already in same set
    if(a == b)return;

    // Union by Rank
    if(rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    }
    else {
        parent[a] = b;
        rank[b]++;
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Initially, every element is its own set
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int m; // Number of queries
    cin >> m;
    while(m--) {

        string str;
        cin >> str;
        if(str == "union") {
            int x, y;
            cin >> x >> y;
            unionSet(parent, rank, x, y);
        }
        else { // find
            int x;
            cin >> x;
            cout << find(parent, x) << "\n";
        }
    }
}

// Test Case
// 5
// 5
// union 1 2
// union 2 3
// find 1
// find 3
// find 4