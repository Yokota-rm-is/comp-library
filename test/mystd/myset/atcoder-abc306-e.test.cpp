#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc306/tasks/abc306_e"
// https://atcoder.jp/contests/abc306/submissions/65371453

#include "../../../mystd/myset.cpp"

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;

    MultiSet<ll> ms;
    vll A(N, 0);
    ms.insert(0, N);

    while (Q--) {
        ll x, y;
        cin >> x >> y;
        --x;
        ms.erase(A[x]);
        A[x] = y;
        ms.insert(y);

        cout << ms.sum_max_k(K) << endl;
    }

    return 0;
} 
