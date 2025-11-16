#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc253/tasks/abc253_g"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    --L, --R;

    using S = ll;
    auto op = [](S a, S b) { return max(a, b); };
    auto e = []() { return 0ll; };
    using F = ll;
    auto mapping = [](S a, F b) { return (b != inf64) ? b : a; };
    auto composition = [](F& a, F b) { if (b != inf64) a = b; };
    auto id = []() { return inf64; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> treap(N, 0);
    rep(i, N) {
        treap.apply(i, i + 1);
    }

    vll A(N);
    rep(i, N) A[i] = N - i - 1;

    vll B(N, 0);
    B[0] = 0;
    rep(i, N - 1) B[i + 1] = B[i] + A[i];

    ll left = upper_bound(B.begin(), B.end(), L) - B.begin();
    ll right = upper_bound(B.begin(), B.end(), R) - B.begin();

    if (left == right) {
        rep(i, L - B[left - 1], R - B[right - 1] + 1) {
            ll x = treap.get(left - 1);
            ll y = treap.get(left + i);
            treap.apply(left - 1, y);
            treap.apply(left + i, x);
        }
    }
    else {
        rep(i, L - B[left - 1], A[left - 1]) {
            ll x = treap.get(left - 1);
            ll y = treap.get(left + i);
            treap.apply(left - 1, y);
            treap.apply(left + i, x);
        }
        rep(i, left + 1, right) {
            treap.rotate(i - 1, N - 1, N);
        }
        rep(i, R - B[right - 1] + 1) {
            ll x = treap.get(right - 1);
            ll y = treap.get(right + i);
            treap.apply(right - 1, y);
            treap.apply(right + i, x);
        }
    }

    vll ans(N);
    rep(i, N) {
        ans[i] = treap.get(i);
    }

    cout << ans << endl;

    return 0;
} 
