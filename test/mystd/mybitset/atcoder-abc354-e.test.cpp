#define PROBLEM "https://atcoder.jp/contests/abc354/tasks/abc354_e"

#include "../../../mystd/mybitset.cpp"

ll N;
vll A, B;
vector<ll> dp;

bool f(Bitset bit) {
    if (dp[bit] != -1) return dp[bit];

    bool ret = false;

    rep(i, N) {
        if (!bit.test(i)) continue;
        
        rep(j, i) {
            if (!bit.test(j)) continue;

            if (A[i] == A[j] or B[i] == B[j]) {
                Bitset next(bit);
                next.reset({i, j});

                ret |= !f(next);
            }
        }
    }

    dp[bit] = ret;

    return ret;
}

int main() {
    cin >> N;

    A.resize(N), B.resize(N);
    input(A, B);

    dp.resize(1 << N, -1);
    Bitset bit((1 << N) - 1);

    bool ans = f(bit);

    cout << TakahashiAoki(ans) << endl;

    return 0;
} 
