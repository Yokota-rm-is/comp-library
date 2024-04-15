#define PROBLEM "https://atcoder.jp/contests/abc338/tasks/abc338_e"

#include "../../../structure/bit.cpp"

int main() {
    long long N;
    cin >> N;
    vector<pll> A;
    for(int i = 0 ; i < N ; ++i){
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        A.emplace_back(a - 1, b - 1);
    }

    sort(A);

    BIT tree(2 * N);
    bool ans = tree.is_overlapped(A);

    cout << YesNo(ans) << endl;

    return 0;
}