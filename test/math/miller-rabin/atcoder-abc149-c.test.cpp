#define PROBLEM "https://atcoder.jp/contests/abc149/tasks/abc149_c"

#include "../../../math/miller-rabin.cpp"

int main() {
    ll X;
    cin >> X;

    ll x = X;

    while (true) {
        if (is_prime(x)) {
            cout << x << endl;
            return 0;
        }

        ++x;
    }

    return 0;
}