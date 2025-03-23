#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_f"

#include "../../../hash/zobrist-hash.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<ZobristHash<true>> hashA(N + 1), hashB(N + 1);
    rep(i, N) {
        hashA[i + 1] = hashA[i];
        hashA[i + 1].insert(A[i]);

        hashB[i + 1] = hashB[i];
        hashB[i + 1].insert(B[i]);
    }
    
    rep(i, Q) {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;

        ZobristHash hash_lr = hashA[r] - hashA[l - 1];
        ZobristHash hash_LR = hashB[R] - hashB[L - 1];

        if (hash_lr == hash_LR) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
} 