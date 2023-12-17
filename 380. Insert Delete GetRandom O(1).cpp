class RandomizedSet {
public:
    set<int> s;
    vector<int> elements;  
    RandomizedSet() {
    }

    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false; 
        }
        s.insert(val);
        elements.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = s.find(val);
        if (it != s.end()) {
            s.erase(it);
            auto vectorIt = find(elements.begin(), elements.end(), val);
            if (vectorIt != elements.end()) {
                elements.erase(vectorIt);
            }

            return true;
        }

        return false; 
    }

    int getRandom() {
        if (!elements.empty()) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, elements.size() - 1);
            int randomIndex = dis(gen);

            return elements[randomIndex];
        }

        return -1; 
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */