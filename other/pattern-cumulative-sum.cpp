#pragma once
#include "../base.cpp"

template <typename T>
struct PatternCumulativeSum : vector<vector<T>> {
    ll H, W;

    PatternCumulativeSum(vector<vector<T>>& A) : H(A.size()), W(A.front().size()) {
        (*this).resize(H + 1, vector<T>(W + 1, 0));
        init(A);
    };

    void init(vector<vector<T>>& A) {
        rep(i, A.size()) rep(j, A.front().size()) {
            (*this)[i + 1][j + 1] = A[i][j] + (*this)[i + 1][j] + (*this)[i][j + 1] - (*this)[i][j];
        }
    }

    // [x1, x2) x [y1, y2)の範囲の区間和を求める
    // xとyの順番に注意すること！！
    T sum(long long x1, long long y1, long long x2, long long y2) {
        T ret = 0;

        ll a1 = ceil(x1, W) * W, b1 = ceil(y1, H) * H, a2 = floor(x2, W) * W, b2 = floor(y2, H) * H;

        ret += (*this)[H][W] * ((a2 - a1) / W) * ((b2 - b1) / H); // 中央
        ret += (*this)[y2 - b2][W] - (*this)[y2 - b2][W - (a1 - x1)]; // 左上
        ret += ((*this)[H][W] - (*this)[H][W - (a1 - x1)]) * ((b2 - b1) / H); // 中央左
        ret += (*this)[H][W] - (*this)[H][W - (a1 - x1)] - (*this)[H - (b1 - y1)][W] + (*this)[H - (b1 - y1)][W - (a1 - x1)]; // 左下
        ret += (*this)[y2 - b2][W] * ((a2 - a1) / W); // 中央上
        ret += (*this)[y2 - b2][x2 - a2]; // 右上
        ret += ((*this)[H][W] - (*this)[H - (b1 - y1)][W]) * ((a2 - a1) / W); // 中央下
        ret += (*this)[H][x2 - a2] - (*this)[H - (b1 - y1)][x2 - a2]; // 右下
        ret += (*this)[H][x2 - a2] * ((b2 - b1) / H); // 中央右

        return ret;
    }

    friend ostream& operator<<(ostream& os, PatternCumulativeSum cs) {
        rep(i, cs.size()) {
            rep(j, cs.front().size()) {
                os << cs[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};