#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc084/tasks/abc084_d"

#include "../../../mystd/myset.cpp"
#include "../../../math/eratosthenes.cpp"

int main() {
    ll N = 1e5;

    Eratosthenes era(N);
    Set<ll> st;

    rep(i, 1, N + 1, 2) {
        if (!era.is_prime[i]) continue;
        if (!era.is_prime[(i + 1) / 2]) continue;

        st.insert(i);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << st.count(l, r + 1) << endl;
    }

    return 0;
}