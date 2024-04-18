#define PROBLEM "https://atcoder.jp/contests/abc149/tasks/abc149_c"

#include "../../../math/is_prime.cpp"

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