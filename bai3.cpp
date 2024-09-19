#include<bits/stdc++.h>
using namespace std;

struct Solve {
    int x, y;
    int a, b;
    void input() {
        cin >> x >> y >> a >> b;
    }
    void tong() {
        int tu3 = x*b + a*y;
        int mau3 = b*y;
        int g = __gcd(tu3, mau3);
        tu3 /= g; mau3 /= g;
        if (mau3 < 0) {
            mau3 = -mau3;
            tu3 = -tu3;
        }
        cout << tu3 << "/" << mau3 << "\n";
    }
    void hieu() {
        int tu3 = x*b - a*y;
        int mau3 = b*y;
        int g = __gcd(tu3, mau3);
        tu3 /= g; mau3 /= g;
        if (mau3 < 0) {
            mau3 = -mau3;
            tu3 = -tu3;
        }
        cout << tu3 << "/" << mau3 << "\n";
    }
    void tich() {
        int tu3 = x*a;
        int mau3 = b*y;
        int g = __gcd(tu3, mau3);
        tu3 /= g; mau3 /= g;
        if (mau3 < 0) {
            mau3 = -mau3;
            tu3 = -tu3;
        }
        cout << tu3 << "/" << mau3 << "\n";
    }
    void thuong() {
        int tu3 = x*b;
        int mau3 = y*a;
        int g = __gcd(tu3, mau3);
        tu3 /= g; mau3 /= g;
        if (mau3 < 0) {
            mau3 = -mau3;
            tu3 = -tu3;
        }
        cout << tu3 << "/" << mau3 << "\n";
    }
} minhntq;

int main() {
    minhntq.input();
    minhntq.tong();
    minhntq.hieu();
    minhntq.tich();
    minhntq.thuong();
    return 0;
}