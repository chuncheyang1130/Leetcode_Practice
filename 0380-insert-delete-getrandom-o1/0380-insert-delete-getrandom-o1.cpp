class RandomizedSet {
public:
    unordered_map<int,int> tab;
    vector<int> vec;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (tab.find(val) == tab.end()){
            vec.push_back(val);
            tab[val] = vec.size()-1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if (tab.find(val) == tab.end())
            return false;

        auto it = tab.find(val);
        int vec_end = vec.back();

        vec[it->second] = vec_end;
        vec.pop_back();

        tab[vec_end] = it->second;
        tab.erase(val);

        return true;
    }
    
    int getRandom() {
        int ind = rand() % vec.size();
        return vec[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */