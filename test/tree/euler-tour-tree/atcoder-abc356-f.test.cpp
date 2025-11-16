#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc356/tasks/abc356_f"
// https://atcoder.jp/contests/abc356/submissions/67493534

#include "../../../tree/euler-tour-tree.cpp"

int main() {
    ll Q, K;
    cin >> Q >> K;

    vector<pll> queries(Q);
    vll nodes;

    rep(i, Q) {
        cin >> queries[i].first >> queries[i].second;
        nodes.push_back(queries[i].second);
    }
    
    sort(nodes);
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    ll N = nodes.size();
    vll A(N, 1);

    EulerTourTree<ll, ll> tree(A);
    setll st;

    rep(q, Q) {
        auto [t, x] = queries[q];
        ll idx = lower_bound(nodes.begin(), nodes.end(), x) - nodes.begin();

        if (t == 1) {
            auto it = st.lower_bound(idx);

            if (it == st.end()) {
                if (it != st.begin()) {
                    auto prev_it = prev(it);
                    ll prev_idx = *prev_it;
                    if (nodes[idx] - nodes[prev_idx] <= K) tree.link(prev_idx, idx);
                }
                st.insert(idx);
            }
            else if (*it == idx) {
                auto next_it = next(it);
                if (next_it != st.end()) {
                    ll next_idx = *next_it;
                    if (nodes[next_idx] - nodes[idx] <= K) tree.cut(idx, next_idx);
                }
                if (it != st.begin()) {
                    auto prev_it = prev(it);
                    ll prev_idx = *prev_it;
                    if (nodes[idx] - nodes[prev_idx] <= K) tree.cut(prev_idx, idx);

                    if (next_it != st.end()) {
                        ll next_idx = *next_it;
                        if (nodes[next_idx] - nodes[prev_idx] <= K) tree.link(prev_idx, next_idx);
                    }
                }
                st.erase(it);
            }
            else  {
                ll next_idx = *it;
                if (nodes[next_idx] - nodes[idx] <= K) tree.link(idx, next_idx);
                
                if (it != st.begin()) {
                    auto prev_it = prev(it);
                    ll prev_idx = *prev_it;
                    if (nodes[next_idx] - nodes[prev_idx] <= K) tree.cut(prev_idx, next_idx);
                    if (nodes[idx] - nodes[prev_idx] <= K) tree.link(prev_idx, idx);
                }

                st.insert(idx);
            }
        }
        else {
            cout << tree.query(idx, -1) << endl;
        }
    }

    return 0;
} 
