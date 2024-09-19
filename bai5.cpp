#include<bits/stdc++.h>
using namespace std;
int day_31[] = {1, 3, 5, 7, 8, 10, 12};
struct Solve {
    int day, month, year;
    
    void input() {
        cin >> day >> month >> year;
    }
    bool leap_year() {
        if (year % 100 == 0) return year % 400 == 0;
        return year % 4 == 0;
    }
    void calc_the_next_day() {
        if (month == 2) {
            if (day < 28) cout << day + 1 << "/" << month << "/" << year << "\n";
            else if (day == 29) {
                cout << "1/3/" << year << "\n";
            } else if (day == 28) {
                if (leap_year()) cout << "1/3/" << year << "\n";
                else cout << "29/2/" << year << "\n";
            }
        } 
        else if (day < 30) {
            cout << day + 1 << "/" << month << "/" << year << "\n";
        } else
        if (day == 30) {
            bool ok = false;
            for (int i = 0; i < 7; i++) if (day_31[i] == month) ok = true;
            if (ok) cout << day + 1 << "/" << month << "/" << year << "\n";
            else cout << "1/" << month + 1 << "/" << year << "\n";
        } else if (day == 31) {
            if (month == 12) cout << "1/1/" << year + 1 << "\n";
            else cout << "1/" << month + 1 << "/" << year << "\n";
        } else assert(false);
    }
    void calc_the_previous_day() {
        if (day > 1) cout << day - 1 << "/" << month << "/" << year << "\n";
        else {
            if (month == 3) {
                if (leap_year()) cout << "29/2/" << year << "\n";
                else cout << "28/2/" << year << "\n";
            } else
            if (month == 1) {
                cout << "31/12/" << year - 1 << "\n";
            }
            else {
                bool ok = false;
                for (int i = 0; i < 7; i++) if (day_31[i] == month - 1) ok = true;
                if (ok) cout << "31/" << month - 1 << "/" << year << "\n";
                else cout << "30/" << month - 1 << "/" << year << "\n";
            } 
        }
    }
    void calc_the_order() {
        int res = day;
        for (int i = 1; i < month; i++) {
            bool ok = false;
            for (int j = 0; j < 7; j++) if (day_31[j] == i) ok = true;
            res += 30 + ok;
        }
        cout << res << "\n";
    }
    void solve() {
        calc_the_next_day();
        calc_the_previous_day();
        calc_the_order();
    }
} minhntq;

int main() {
    minhntq.input();
    minhntq.solve();
    return 0;
}
