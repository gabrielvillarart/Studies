#include "Core.h"

class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {

        if (keys.contains(val))
            return false;

        keys.emplace(val);
        return true;
    }
    
    bool remove(int val) {
        
        if (keys.contains(val)) {
            keys.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {

        if (keys.size() == 0) return 0;

        auto it = keys.begin();
        advance(it,fastRandom() % keys.size());

        return *it;
    }

private:
    unordered_set<int> keys;
};

void test() {
    RandomizedSet* randomizedSet = new RandomizedSet();
    randomizedSet->insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet->remove(2); // Returns false as 2 does not exist in the set.
    randomizedSet->insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet->getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet->remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet->insert(2); // 2 was already in the set, so return false.
    randomizedSet->getRandom(); // Since 2 is the only number in the set, getRandom() will always 
    delete randomizedSet;

    while (true)
    {
        int r = RandomizedSet::fastRandom() % 10;
    }
}