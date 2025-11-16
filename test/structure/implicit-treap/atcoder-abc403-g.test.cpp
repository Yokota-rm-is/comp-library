#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc403/tasks/abc403_g"

#include "../../../structure/implicit-treap.cpp"
#include "../../../mystd/myset.cpp"

int main() {
    ll Q;
    cin >> Q;

    MultiSet<ll> ms;
    using S = pll;
    auto op = [](S a, S b) { return S(a.first + b.first, a.second + b.second); };
    auto e = []() { return S(0, 0); };
    using F = bool;
    auto mapping = [](S a, F b) { return b ? S(a.second, a.first) : a; };
    auto composition = [](F& a, F b) { a ^= b; };
    auto id = []() { return false; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> treap;

    ll z = 0;
    ll M = 1e9;

    while (Q--) {
        ll y;
        cin >> y;

        ll x = ((y + z) % M) + 1;
        auto it = ms.upper_bound(x);
        ll rank = ms.rank(it);

        treap.apply(rank, treap.size(), true);
        S s = (rank % 2 == 0) ? S(x, 0) : S(0, x);
        treap.insert(rank, s);
        ms.insert(x);

        ll ans = treap.prod(0, treap.size()).first;
        cout << ans << endl;
        z = ans;
    }

    return 0;
} 
