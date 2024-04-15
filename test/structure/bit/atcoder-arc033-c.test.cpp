#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"

#include "../../../structure/bit.cpp"

int main() {
    long long Q;
    cin >> Q;
    vector<long long> T(Q);
    vector<long long> X(Q);
    for(int i = 0 ; i < Q ; ++i){
        cin >> T[i];
        cin >> X[i];
    }

    BIT tree(max(X) + 1);
    rep(i, Q) {
        long long t = T[i], x = X[i];
        
        if (t == 1) {
            tree.add(x, 1);
        }
    
        if (t == 2) {
            ll index = tree.lower_bound(x);
            cout << index << endl;
            tree.add(index, -1);
        }
    } 

    return 0;
}