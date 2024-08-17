#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_c"

#include "../../../other/custom-baseset.cpp"

int main() {
    long long N, K;
    input(N, K);

    vll R(N);
    rep(i, N) cin >> R[i];

    vector<vll> ans;

    for(CustomBaseset bs(R); bs < bs.end(); ++bs) {
        vll tmp = bs;
        ++tmp;

        ll sum = accumulate(tmp);
        if (sum % K == 0) {
            ans.push_back(tmp);
        }
    }

    sort(ans);

    cout << ans << endl;

    return 0;
} 