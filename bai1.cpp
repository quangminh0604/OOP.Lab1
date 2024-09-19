#include<bits/stdc++.h>
using namespace std;

struct Solve {
    void solve() {
        int x, y; cin >> x >> y;
        int g = __gcd(x, y);
        x /= g; y /= g;
        cout << x << "/" << y;
    }
} minhntq;

int main() {
    minhntq.solve();
    return 0;
}