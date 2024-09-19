#include<bits/stdc++.h>
using namespace std;

struct Solve {
    void solve() { 
        int x, y; cin >> x >> y;
        int a, b; cin >> a >> b;
        if (x * b >= a * y) cout << x << "/" << y;
        else cout << a << "/" << b;
    }
} minhntq;

int main() {
    minhntq.solve();
    return 0;
}