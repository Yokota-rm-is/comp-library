#define PROBLEM "https://atcoder.jp/contests/abc350/tasks/abc350_f"

#include "../../../structure/implicit-treap.cpp"

namespace seg {
    #include "../../../structure/dual-segment-tree.cpp"
}

int main() {
    string S;
    cin >> S;

    vector<char> T;
    fore(c, S) T.push_back(c);

    stack<ll> st;
    vector<pll> A;
    rep(i, S.size()) {
        char c = S[i];
        if (c != '(' and c != ')') {

        }
        else if (c == '(') st.push(i);
        else {
            ll l = st.top();
            st.pop();
            ll r = i;
            A.emplace_back(l, r + 1);
        }
    }

    seg::RangeAddPointGet<ll, ll> tree(S.size(), 0);
    fore(p, A) {
        auto [l, r] = p;
        tree.apply(l, r, 1);
    }

    rep(i, S.size()) {
        char c = S[i];
        if (c == '(' or c == ')') continue;
        if (tree.get(i) % 2 == 0) S[i] = c;
        else {
            if (is_upper(c)) S[i] = to_lower(c);
            else S[i] = to_upper(c);
        }
    }

    using Node = char;
    using F = long long;
    auto op = [](Node a, Node b) { return a + b; };
    auto e = []() { return 0; };
    auto mapping = [](Node x, F f) { return x; };
    auto composition = [](F &f, F s) { return ; };
    auto id = []() { return 0ll; };

    ImplicitTreap<Node, F, op, e, mapping, composition, id> treap;
    rep(i, S.size()) treap.insert(i, S[i]);

    fore(p, A) {
        auto [l, r] = p;
        treap.reverse(l, r);
    }

    string ans;
    rep(i, S.size()) {
        char c = treap.get(i);
        if (c == '(' or c == ')') continue;

        ans += c;
    }

    cout << ans << endl;

    return 0;
} 
