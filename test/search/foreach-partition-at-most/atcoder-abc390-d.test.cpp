#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc390/tasks/abc390_d"

#include "../../../search/foreach-partition-at-most.cpp"

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ull> ans;
    vector<ull> group(N, 0);

    auto insert = [&](ll i, ll idx) {
        group[i] += A[idx];
    };

    auto erase = [&](ll i, ll idx) {
        group[i] -= A[idx];
    };

    auto f = [&](vvll& indices) {
        ull xor_sum = 0;
        rep(i, indices.size()) xor_sum ^= group[i];
        ans.push_back(xor_sum);
    };
    
    foreach_partition_at_most(N, N, f, insert, erase);

    sort(ans);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;

    return 0;
} 
