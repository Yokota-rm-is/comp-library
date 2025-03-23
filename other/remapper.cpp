#pragma once
#include "../base.cpp"

template <typename Key, typename Value>
struct Remapper {
    map<Key, Value> mp;
    map<Value, Key> rmp;

    Remapper() {}

    void set(const Key key, const Value value) {
        assert(mp.find(key) == mp.end());
        assert(rmp.find(value) == rmp.end());

        mp[key] = value;
        rmp[value] = key;
    }

    void update(const Key key, const Value value) {
        assert(mp.find(key) != mp.end());
        assert(rmp.find(value) == rmp.end());

        rmp.erase(mp[key]);
        mp[key] = value;
        rmp[value] = key;
    }

    Value get_value(const Key key) {
        assert(mp.find(key) != mp.end());
        return mp[key];
    }

    Key get_key(const Value value) {
        assert(rmp.find(value) != rmp.end());
        return rmp[value];
    }

    bool contains_key(const Key key) {
        return mp.find(key) != mp.end();
    }

    bool contains_value(const Value value) {
        return rmp.find(value) != rmp.end();
    }

    void erase_key(const Key key) {
        assert(mp.find(key) != mp.end());
        Value value = mp[key];
        mp.erase(key);
        rmp.erase(value);
    }

    void erase_value(const Value value) {
        assert(rmp.find(value) != rmp.end());
        Key key = rmp[value];
        rmp.erase(value);
        mp.erase(key);
    }

    void swap_key(const Key key1, const Key key2) {
        assert(mp.find(key1) != mp.end());
        assert(mp.find(key2) != mp.end());

        Value value1 = mp[key1];
        Value value2 = mp[key2];

        mp[key1] = value2;
        mp[key2] = value1;

        rmp[value1] = key2;
        rmp[value2] = key1;
    }

    void swap_value(const Value value1, const Value value2) {
        assert(rmp.find(value1) != rmp.end());
        assert(rmp.find(value2) != rmp.end());

        Key key1 = rmp[value1];
        Key key2 = rmp[value2];

        mp[key1] = value2;
        mp[key2] = value1;

        rmp[value1] = key2;
        rmp[value2] = key1;
    }
};