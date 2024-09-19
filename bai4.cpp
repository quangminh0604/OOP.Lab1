#include<bits/stdc++.h>
using namespace std;

struct Solve {
    long double x;
    long long INF = (long long)1e18;
    void input() {
        cin >> x;
    }
    void solve() {
        long double result = x;
        long long sign = -1, fact = 1, pow = x;
        for (int exp = 3; fact < INF / exp / (exp - 1) && pow < INF / x / x && exp <= 1000000; exp += 2) {
            fact = fact * exp * (exp - 1);
            pow = pow * x * x;
            result += (long double) sign * pow / fact;
            sign = sign * (-1);
        }
        cout << result;
    }
} minhntq;

int main() {
    minhntq.input();
    minhntq.solve();
    return 0;
}