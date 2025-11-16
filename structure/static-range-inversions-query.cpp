#pragma once
#include "../base.cpp"

// 参考: https://suisen-kyopro.hatenablog.com/entry/2022/10/15/010252
template <typename T>
struct StaticRangeInversionsQuery {
    long long N, sqrtN;
    long long block_size, block_num;
    // pinv[i][j] := inversion number of the subarray (a_{i * block_size}, ..., a_{i * block_size + j - 1})
    // sinv[i][j] := inversion number of the subarray (a_{i * block_size - j}, ..., a_{i * block_size - 1})
    vector<vector<long long>> pinv, sinv;
    // blocks_sorted[i] := sorted array of { (a_{i * block_size + j}, i * block_size + j) | 0 <= j < block_size }
    vector<vector<pair<T, long long>>> blocks_sorted;

    StaticRangeInversionsQuery(vector<T> a) : N(a.size()), sqrtN(max(1ll, (ll)sqrt((double)N))), block_size(sqrtN), block_num(ceil(N, block_size)) {
        a.resize(block_size * block_num, inf64);

        blocks_sorted.resize(block_num);
        rep(block_id, block_num) {
            const long long offset = block_id * block_size;

            blocks_sorted[block_id].resize(block_size);

            rep(i, block_size) {
                blocks_sorted[block_id][i] = {a[offset + i], offset + i};
            }

            sort(blocks_sorted[block_id]);
        }

        pinv = build_pinv<less<T>>(a);
        reverse(a);
        sinv = build_pinv<greater<T>>(a);
        reverse(sinv);
    }

    long long operator()(long long l, long long r) const {
        if (l == r) return 0;
        
        const long long bl = l / block_size, br = ceil(r, block_size);

        if (br - bl == 1) {
            /**
                *             l   r
                *         | A | B | C |
                * Blocks: |           |
                *
                * Inv(B)=Inv(AB)+Inv(BC)-Inv(ABC)+Inv(A,C)
                */
            long long res = pinv[bl][r - bl * block_size] + sinv[bl + 1][(bl + 1) * block_size - l] - pinv[bl][block_size];
            for (long long k = block_size - 1, cnt = 0; k >= 0; --k) {
                cnt += blocks_sorted[bl][k].second < l;
                if (blocks_sorted[bl][k].second >= r) {
                    res += cnt;
                }
            }
            return res;
        } 
        else {
            /**
                *           l                         r
                *           | A |        B        | C |
                * Blocks: |     |     |     |     |     |
                *
                * Inv(ABC)=Inv(AB)+Inv(BC)-Inv(B)+Inv(A,C)
                */
            const long long ml = (bl + 1) * block_size, mr = (br - 1) * block_size;
            long long res = pinv[bl + 1][r - ml] + sinv[br - 1][mr - l] - pinv[bl + 1][mr - ml];
            for (long long k = block_size - 1, j = block_size, cnt = 0; k >= 0; --k) {
                if (blocks_sorted[br - 1][k].second >= r) continue;
                while (j > 0 and blocks_sorted[bl][j - 1].first > blocks_sorted[br - 1][k].first) {
                    cnt += blocks_sorted[bl][--j].second >= l;
                }
                res += cnt;
            }
            return res;
        }
    }

    template <typename Compare>
    vector<vector<long long>> build_pinv(const vector<T>& a) const {
        Compare cmp{};
        auto cmp_pair = [&](auto& p, auto& q) { return cmp(p.first, q.first); };

        vector<vector<long long>> ret(block_num + 1);

        // invariant: suf is the sorted array of { (a_i, i) | i is in the k-th block s.t. k > block_id }
        vector<pair<T, long long>> suf;
        repd(block_id, block_num) {
            const long long offset = block_id * block_size;
            ret[block_id].resize(block_size * (block_num - block_id) + 1);
            vector<pair<T, long long>> pre(block_size);
            
            rep(i, block_size) {
                pre[i] = {a[offset + i], offset + i};
                ret[block_id][i + 1] = ret[block_id][i];
                rep(j, i) ret[block_id][i + 1] += cmp(a[offset + i], a[offset + j]);
            }
            sort(pre.begin(), pre.end(), cmp_pair);

            /**
                * | A |  B  |x|
                * Inv(ABx)=Inv(AB)+Inv(Bx)-Inv(B)+Inv(A,x)
                */

                // calculates Inv(A,a_i) for all i >= block_size * block_id
            for (long long i = block_size * (block_num - 1 - block_id) - 1, j = block_size; i >= 0; --i) {
                while (j > 0 and cmp(suf[i].first, pre[j - 1].first)) --j;
                ret[block_id][suf[i].second - offset + 1] += block_size - j;
            }

            for (long long i = block_size; i < block_size * (block_num - block_id); ++i) {
                ret[block_id][i + 1] += ret[block_id][i] + ret[block_id + 1][i + 1 - block_size] - ret[block_id + 1][i - block_size];
            }

            copy(pre.begin(), pre.end(), back_inserter(suf));
            inplace_merge(suf.begin(), suf.end() - block_size, suf.end(), cmp_pair);
        }
        return ret;
    }

    static constexpr long long ceil(long long x, long long div) { return (x + div - 1) / div; }
};

