#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0304"

#include "../../../math/ushige-.cpp"

int main() {
    ll N, C;
    cin >> N >> C;

    vll A(C), B(C), D(C);
    vector<string> O(C), S(C);

    ll cnt_ast = 0;
    rep(i, C) {
        string query;
        cin >> query;

        ll idx = 0;

        ll a = 0, b = 0, d = 0;
        string o, s;

        while (idx < query.size() and query[idx] >= '0' and query[idx] <= '9') {
            a = a * 10 + (query[idx] - '0');
            ++idx;
        }
        
        if (query[idx] == '*') {
            o = "*";
            ++idx;
            ++cnt_ast;
        }
        else if (query[idx] == '<') {
            o = "<=";
            idx += 2;
        }
        else if (query[idx] == '>') {
            o = ">=";
            idx += 2;
        }

        while (idx < query.size() and query[idx] >= '0' and query[idx] <= '9') {
            b = b * 10 + (query[idx] - '0');
            ++idx;
        }

        if (query[idx] == '+') {
            s = "+";
            ++idx;
        }
        else if (query[idx] == '-') {
            s = "-";
            ++idx;
        }

        while (idx < query.size() and query[idx] >= '0' and query[idx] <= '9') {
            d = d * 10 + (query[idx] - '0');
            ++idx;
        }

        A[i] = a;
        O[i] = o;
        B[i] = b;
        D[i] = d;
        S[i] = s;
    }

    --A, --B;

    ll ans = -inf64;

    rep(bit, 1ll << cnt_ast) {
        ll cnt = 0;
        Solver<long long> solver(N);

        rep(i, C) {
            ll a = A[i], b = B[i], d = D[i];
            string o = O[i], s = S[i];
    
            if (o == "*") {
                if (bit_test(bit, cnt)) o = "<=";
                else o = ">=";
                
                ++cnt;
            }

            if (o == "<=") {
                if (s == "+") {
                    // a <= b -> a - b <= 0
                    // b - a >= d
                    solver.add_less_than_or_equal(a, b, 0);
                    solver.add_greater_than_or_equal(b, a, d);
                }
                else {
                    // a <= b -> a - b <= 0
                    // b - a <= d
                    solver.add_less_than_or_equal(a, b, 0);
                    solver.add_less_than_or_equal(b, a, d);
                }
            }
            else if (o == ">=") {
                if (s == "+") {
                    // a >= b -> a - b >= 0
                    // a - b >= d
                    solver.add_greater_than_or_equal(a, b, 0);
                    solver.add_greater_than_or_equal(a, b, d);
                }
                else {
                    // a >= b -> a - b >= 0
                    // a - b <= d
                    solver.add_greater_than_or_equal(a, b, 0);
                    solver.add_less_than_or_equal(a, b, d);
                }
            }
        }

        rep(i, 1, N) {
            solver.add_greater_than_or_equal(i, 0, 0);
        }

        ll ret = solver.miximize(0);
        if (ret == -inf64) continue;
    
        chmax(ans, ret);
    }

    if (ans == -inf64) cout << -1 << endl;
    else if (ans == inf64) cout << "inf" << endl;
    else cout << ans << endl;

    return 0;
} 