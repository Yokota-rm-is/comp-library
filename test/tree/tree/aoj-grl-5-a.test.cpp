#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&"

#include "../../../tree/tree.cpp"

int main() {
    ll n;
    cin >> n;

    Tree tree(n);
    rep(i, n - 1) {
        ll s, t, w;
        cin >> s >> t >> w;

        tree.connect(s, t, w);
    }

    cout << tree.find_diameter() << endl;

    return 0;
}