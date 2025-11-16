#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableSet {
    set<T> original;
    long long N;
    T offset_key;

    struct iterator {
        typename set<T>::iterator it;
        const RotatableSet* rset;

        iterator(typename set<T>::iterator it, RotatableSet* rset) : it(it), rset(rset) {}

        iterator& operator++() {
            ++it;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        iterator& operator--() {
            --it;
            return *this;
        }

        iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }

        T key() const {
            T key = *it + rset->offset_key;
            if (rset->N > 0) key %= rset->N;
            return key;
        }

        operator T() const {
            return key();
        }

        bool operator==(const iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;
        }
    };

    struct const_iterator {
        typename set<T>::const_iterator it;
        const RotatableSet* rset;

        const_iterator(typename set<T>::const_iterator it, const RotatableSet* rset) : it(it), rset(rset) {}

        const_iterator& operator++() {
            ++it;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }

        const_iterator& operator--() {
            --it;
            return *this;
        }

        const_iterator operator--(int) {
            const_iterator temp = *this;
            --(*this);
            return temp;
        }

        T key() const {
            T key = *it + rset->offset_key;
            if (rset->N > 0) key %= rset->N;
            return key;
        }

        operator T() const {
            return key();
        }

        bool operator==(const const_iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const const_iterator& other) const {
            return it != other.it;
        }
    };

    RotatableSet() : N(0), offset_key(0) {}
    RotatableSet(long long n) : N(n), offset_key(0) {}
    RotatableSet(set<T> st, long long n = 0) : original(st), N(n), offset_key(0) {}

    // keyの値をx増やす
    // key    : 3, 1, 4, 1, 5, 9
    // key + 1: 4, 2, 5, 2, 6, 10
    T add_key(T x) {
        offset_key += x;
        if (N > 0) offset_key %= N;
        return offset_key;
    }

    // keyの値をx減らす
    // key    : 3, 1, 4, 1, 5, 9
    // key - 1: 2, 0, 3, 0, 4, 8
    T subtract_key(T x) {
        if (N > 0) x %= N;
        offset_key += N - x;
        if (N > 0) offset_key %= N;
        return offset_key;
    }

    pair<iterator, bool> insert(T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        // original.insert(key);
        auto result = original.insert(key);
        return {iterator(result.first, this), result.second};
    }

    iterator insert(iterator hint, T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        auto it = original.insert(hint.it, key);
        return iterator(it, this);
    }

    iterator find(T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        return iterator(original.find(key), this);
    }

    void erase(T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        original.erase(key);
    }

    iterator erase(iterator it) {
        if (it == end()) return end();
        it.it = original.erase(it.it);
        return it;
    }

    iterator lower_bound(T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        return iterator(original.lower_bound(key), this);
    }

    iterator upper_bound(T key) {
        key += N - offset_key;
        if (N > 0) key %= N;
        return iterator(original.upper_bound(key), this);
    }

    iterator begin() {
        auto first = original.begin();
        return iterator(first, this);
    }

    iterator end() {
        return iterator(original.end(), this);
    }

    bool contains(T key) const {
        key += N - offset_key;
        if (N > 0) key %= N;
        return original.contains(key);
    }

    void dump() {
        cerr << "offset_key: " << offset_key << endl;
        cerr << "original: ";
        fore(p, original) cerr << p << " ";
        cerr << endl;

        cerr << "rotated: ";
        auto it = original.begin();
        while (it != original.end()) {
            cerr << it << " ";
            ++it;
        }
        cerr << endl;
    }

    friend ostream& operator<<(ostream& os, const RotatableSet<T>& st) {
        auto it = st.begin();
        while (it != st.end()) {
            os << it << " ";
            ++it;
        }
        return os;
    }
};