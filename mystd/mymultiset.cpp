#pragma once
#include "../base.cpp"

template <typename T, typename S = long long>
struct MultiSet : public map<T, S> {
    S N;
    ll n_duplicates;
    using mp = map<T, S>;

    MultiSet() : N(0), n_duplicates(0) {};

    S insert(T x, S n = 1) {
        N += n;
        
        auto it = mp::find(x);
        if (it == mp::end() and n > 1) n_duplicates++;
        else if (it != mp::end() and it->second == 1 and n > 0) n_duplicates++;
        return (*this)[x] += n;
    }

    S erase(T x, S n = 1) {
        if (!mp::contains(x)) return 0;
        
        chmin(n, (*this)[x]);
        N -= n;

        auto it = mp::find(x);
        if (it->second == n and n > 1) n_duplicates--;
        else if (it->second == n + 1) n_duplicates--;

        (*this)[x] -= n;

        if ((*this)[x] == 0) {
            mp::erase(x);
            return 0;
        }
        else {
            return (*this)[x];
        }
    }

    void erase_all(T x) {
        auto it = mp::find(x);

        if (it == mp::end()) return;
        else if (it->second > 1) n_duplicates--;

        N -= (*this)[x];
        mp::erase(x);
    }

    T front() {
        return mp::begin()->first;
    }

    T back() {
        return mp::rbegin()->first;
    }

    void pop() {
        erase(front());
    }

    void pop_back() {
        erase(back());
    }

    S count_all() {
        return N;
    }

    S count(T x) {
        if (!mp::contains(x)) return 0;
        return (*this)[x];
    }

    // キー以上の最小の要素を見つけるイテレータを返すメソッド
    typename mp::iterator find_greater_than_or_equal(T key) {
        return mp::lower_bound(key);
    }

    // キーを超える最小の要素を見つけるイテレータを返すメソッド
    typename mp::iterator find_greater_than(T key) {
        return mp::upper_bound(key);
    }

    // キー以下の最大の要素を見つけるイテレータを返すメソッド, ない場合はendを返す
    typename mp::iterator find_less_than_or_equal(T key) {
        auto it = mp::upper_bound(key);
        return it == mp::begin() ? mp::end() : --it;
    }

    // キー未満の最大の要素を見つけるイテレータを返すメソッド, ない場合はendを返す
    typename mp::iterator find_less_than(T key) {
        auto it = mp::lower_bound(key);
        return it == mp::begin() ? mp::end() : --it;
    }
};