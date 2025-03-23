#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208"

#include "../../../search/stern-brocot-tree.cpp"

int main() {
    while (true) {
        ll p, n;
        cin >> p >> n;

        if (p == 0 and n == 0) break;

        auto is_ok = [&](ll x, ll y) {
            return y * y * p < x * x;
        };

        SternBrocotTree<ll> sbt;
        auto [u, v, x, y] = sbt.search(is_ok, n);
        cout << u << "/" << v << " " << x << "/" << y << endl;
    }

    return 0;
} 
