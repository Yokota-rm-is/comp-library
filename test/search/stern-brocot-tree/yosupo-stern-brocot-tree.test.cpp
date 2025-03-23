#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../../../search/stern-brocot-tree.cpp"

int main() {
    ll T;
    cin >> T;

    SternBrocotTree<ll> sbt;

    while (T--) {
        string S;
        cin >> S;

        if (S == "ENCODE_PATH") {
            ll p, q;
            cin >> p >> q;
            vll A = sbt.encode_path(p, q);

            if (A.empty()) {
                cout << 0 << endl;
                continue;
            }
            else if (A.front() == 0) {
                cout << A.size() - 1;    
            }
            else {
                cout << A.size() << " R " << A.front();
            }

            rep(i, 1, A.size()) {
                cout << (i % 2 == 0 ? " R " : " L ") << A[i];
            }
            
            cout << endl;
        }
        else if (S == "DECODE_PATH") {
            ll k;
            cin >> k;

            vll A;
            rep(i, k) {
                char c;
                ll a;
                cin >> c >> a;

                if (i == 0 and c == 'L') A.push_back(0);
                A.push_back(a);
            }

            auto [p, q, r, s] = sbt.decode_path(A);
            cout << p + r << " " << q + s << endl;
        }
        else if (S == "LCA") {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            auto [f, g, h, k] = sbt.lca(a, b, c, d);
            cout << f + h << " " << g + k << endl;
        }
        else if (S == "ANCESTOR") {
            ll k, a, b;
            cin >> k >> a >> b;

            auto [p, q, r, s] = sbt.ancestor(k, a, b);
            if (p == 0 && q == 0 && r == 0 && s == 0) cout << -1 << endl;
            else cout << p + r << " " << q + s << endl;
        }
        else if (S == "RANGE") {
            ll p, q;
            cin >> p >> q;
            
            auto [f, g, h, k] = sbt.range(p, q);
            cout << f << " " << g << " " << h << " " << k << endl;
        }
    }
    
    return 0;
} 
