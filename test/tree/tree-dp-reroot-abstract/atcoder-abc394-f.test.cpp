#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc394/tasks/abc394_f"

#include "../../../tree/tree-dp-reroot-abstract.cpp"

int main() {
    ll N;
    cin >> N;

    using S = vll;
    auto merge = [](S x, S y) -> S {
        vll ret;

        auto px = x.begin();
        auto py = y.begin();
        
        while (ret.size() < 3) {
            if (px == x.end() and py == y.end()) break;
            else if (px == x.end()) ret.push_back(*py++);
            else if (py == y.end()) ret.push_back(*px++);
            else {
                if (*px > *py) ret.push_back(*px++);
                else ret.push_back(*py++);
            }
        }

        return ret;
    };
    auto e = []() -> S {
        return S(0);
    };

    using F = ll;
    auto put_vertex = [](S x, F y) -> S {
        if (x.size() < 3) return S(1, 1);

        return {accumulate(x) + 1};
    };
    auto id_vertex = []() -> F {
        return 0;
    };

    TreeDPVertex<S, merge, e, F, put_vertex, id_vertex> tree(N);

    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        --a; --b;

        tree.connect(a, b, 1);
    }

    tree.build(0);
    tree.reroot();

    ll ans = -1;
    rep(i, N) {
        vll acc;
        fore(x, tree.dp[i]) acc.push_back(x[0]);

        if (acc.size() < 4) continue;

        sort(acc);
        reverse(acc);
        acc.resize(4);
        chmax(ans, accumulate(acc) + 1);
    }

    cout << ans << endl;

    return 0;
}