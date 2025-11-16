#pragma once
#include "../base.cpp"

template <typename Key, typename Value, typename Map = map<Key, Value>>
struct RotatableMap {
    Map original;
    long long M;
    long long offset_key;

    struct iterator {
        typename Map::iterator it;
        const RotatableMap* rmap;

        iterator(typename Map::iterator it, RotatableMap* rmap) : it(it), rmap(rmap) {}

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

        const Key key() const {
            Key key = it->first + rmap->offset_key;
            if (rmap->M > 0) key %= rmap->M;
            return key;
        }

        Value& value() {
            return it->second;
        }

        const Value& value() const {
            return it->second;
        }

        bool operator==(const iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;
        }
    };

    struct const_iterator {
        typename Map::const_iterator it;
        const RotatableMap* rmap;

        const_iterator(typename Map::const_iterator it, const RotatableMap* rmap) : it(it), rmap(rmap) {}

        const_iterator& operator++() {
            ++it;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }

        const Key key() const {
            Key key = it->first + rmap->offset_key;
            if (rmap->M > 0) key %= rmap->M;
            return key;
        }

        const Value& value() const {
            return it->second;
        }

        bool operator==(const const_iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const const_iterator& other) const {
            return it != other.it;
        }
    };

    RotatableMap() : M(0), offset_key(0) {}
    RotatableMap(Map mp, long long m = 0) : original(mp), M(m), offset_key(0) {}

    // keyの値をx増やす
    // key    : 1, 2, 4, 8, 16, 32 <- add_key
    // value  : 3, 1, 4, 1,  5,  9
    //
    // key + 1: 2, 3, 5, 9, 17, 33
    // value  : 3, 1, 4, 1,  5,  9 
    Key add_key(Key x) {
        offset_key += x;
        if (M > 0) offset_key %= M;
        return offset_key;
    }

    // keyの値をx減らす
    // key    : 1, 2, 4, 8, 16, 32 <- subtract_key
    // value  : 3, 1, 4, 1,  5,  9
    //
    // key - 1: 0, 1, 3, 7, 15, 31
    // value  : 3, 1, 4, 1,  5,  9
    Key subtract_key(Key x) {
        if (M > 0) x %= M;
        offset_key += M - x;
        if (M > 0) offset_key %= M;
        return offset_key;
    }

    Value& operator[](Key key) {
        key += M - offset_key;
        if (M > 0) key %= M;
        
        return original[key];
    }

    Value get(Key key) {
        return this->operator[](key);
    }

    bool contains(Key key) const {
        key += M - offset_key;
        if (M > 0) key %= M;
        return original.contains(key);
    }

    iterator find(Key key) {
        key += M - offset_key;
        if (M > 0) key %= M;
        return iterator(original.find(key), this);
    }

    iterator lower_bound(Key key) {
        key += M - offset_key;
        if (M > 0) key %= M;
        return iterator(original.lower_bound(key), this);
    }

    iterator upper_bound(Key key) {
        key += M - offset_key;
        if (M > 0) key %= M;
        return iterator(original.upper_bound(key), this);
    }

    iterator begin() {
        return iterator(original.begin(), this);
    }

    iterator end() {
        return iterator(original.end(), this);
    }

    const_iterator begin() const {
        return const_iterator(original.begin(), this);
    }

    const_iterator end() const {
        return const_iterator(original.end(), this);
    }

    iterator insert(iterator hint, Key key, Value value) {
        key += M - offset_key;
        if (M > 0) key %= M;

        auto it = original.insert(hint.it, {key, value});
        return iterator(it, this);
    }

    iterator erase(iterator it) {
        if (it == end()) return end();
        it.it = original.erase(it.it);
        return it;
    }

    void dump() {
        cerr << "offset_key: " << offset_key << endl;
        cerr << "original: ";
        fore(p, original) cerr << p.first << ": " << p.second << endl;

        cerr << "rotated: ";
        auto it = begin();
        while (it != end()) {
            Key key = it.key();
            cerr << key << ": " << it.value() << endl;
            ++it;
        }
        cerr << endl;
    }

    friend ostream& operator<<(ostream& os, const RotatableMap<Key, Value>& mp) {
        auto it = mp.begin();
        while (it != mp.end()) {
            os << it.key() << ": " << it.value() << ", ";
            ++it;
        }
        return os;
    }
};