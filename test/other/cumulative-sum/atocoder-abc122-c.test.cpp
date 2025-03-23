#define PROBLEM "https://atcoder.jp/contests/abc122/tasks/abc122_c"

#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    CumulativeSum<ll> cs;

    rep(i, N - 1) {
        if (S[i] == 'A' and S[i + 1] == 'C') cs.push_back(1);
        else cs.push_back(0);
    }

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << cs.sum(l - 1, r - 1) << endl;
    }

    return 0;
}