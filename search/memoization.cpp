#include "../base.cpp"

template<typename Key, typename Value>
struct Memoization {
    map<Key, Value> memo;

    Memoization() {};

    Value get (Key key) {
        if (!memo.contains(key)) {
            memo[key] = f(key);
        }
        
        return memo[key];
    }

    virtual Value f(Key key) = 0; 
};