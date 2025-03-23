#pragma once
#include "../base.cpp"

// judgeを満たす[left, right)の組み合わせの数を求める
// inner: [left, right)が条件を満たすとき，[left, right)の部分区間も条件を満たす
// insert(value, idx): idx番目の要素をvalueに追加する処理
// judge(value): valueが条件を満たすかどうかを判定する関数
// erase(value, idx): idx番目の要素をvalueから削除する処理
template <typename T>
ll shakutori_inner_count(ll N, function<T()> e, function<void(T&, ll)> insert, function<bool(const T&)> judge, function<void(T&, ll)> erase) {
    T value = e();
    assert(judge(value) == true);

    ll count = 0;

    ll right = 0;
    rep(left, N) {
        while (right < N and judge(value)) {
            insert(value, right);
            right++;
        }

        if (!judge(value)) {
            right--;
            erase(value, right);
        }

        if (judge(value)) {
            count += right - left;
        }

        if (right == left) {
            insert(value, right);
            right++;
        }
        
        erase(value, left);
    }
    
    return count;
};

// judgeを満たす[left, right)の組み合わせの数を求める
// outer: [left, right)が条件を満たすとき，[left, right)を含む区間も条件を満たす
// insert(value, idx): idx番目の要素をvalueに追加する処理
// judge(value): valueが条件を満たすかどうかを判定する関数
// erase(value, idx): idx番目の要素をvalueから削除する処理
template <typename T>
ll shakutori_outer_count(ll N, function<T()> e, function<void(T&, ll)> insert, function<bool(const T&)> judge, function<void(T&, ll)> erase) {
    T value = e();
    assert(judge(value) == false);

    ll count = 0;

    ll right = 0;
    rep(left, N) {
        while (right < N and !judge(value)) {
            insert(value, right);
            right++;
        }

        count += N - right;

        if (right == left) {
            insert(value, right);
            right++;
        }
        
        erase(value, left);
    }
    
    return count;
};

// judgeを満たす[left, right)のうち最小の区間長を求める
// insert(value, idx): idx番目の要素をvalueに追加する処理
// judge(value): valueが条件を満たすかどうかを判定する関数
// erase(value, idx): idx番目の要素をvalueから削除する処理
template <typename T>
ll shakutori_min_range(ll N, function<T()> e, function<void(T&, ll)> insert, function<bool(const T&)> judge, function<void(T&, ll)> erase) {
    T value = e();
    assert(judge(value) == false);

    ll min_range = inf64;

    ll right = 0;
    rep(left, N) {
        while (right < N and !judge(value)) {
            insert(value, right);
            right++;
        }

        if (judge(value)) {
            chmin(min_range, right - left);
        }

        if (right == left) {
            insert(value, right);
            right++;
        }
        
        erase(value, left);
    }
    
    return min_range;
};

// judgeを満たす[left, right)のうち最大の区間長を求める
// insert(value, idx): idx番目の要素をvalueに追加する処理
// judge(value): valueが条件を満たすかどうかを判定する関数
// erase(value, idx): idx番目の要素をvalueから削除する処理
template <typename T>
ll shakutori_max_range(ll N, function<T()> e, function<void(T&, ll)> insert, function<bool(const T&)> judge, function<void(T&, ll)> erase) {
    T value = e();
    assert(judge(value) == true);

    ll max_range = 0;

    ll right = 0;
    rep(left, N) {
        while (right < N and judge(value)) {
            insert(value, right);
            right++;
        }

        if (!judge(value)) {
            right--;
            erase(value, right);
        }

        if (judge(value)) {
            chmax(max_range, right - left);
        }

        if (right == left) {
            insert(value, right);
            right++;
        }
        
        erase(value, left);
    }
    
    return max_range;
};