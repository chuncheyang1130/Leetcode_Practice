class RandomizedSet {
public:
    int size = 0;
    int arr[10000];
    unordered_map<int, int> arr_pos;

    RandomizedSet() {
        srand(time(NULL));   
    }
    
    bool insert(int val) {
        if (arr_pos[val] == 0){
            size++;
            arr[size] = val;
            arr_pos[val] = size;
            return true;
        }else return false;
    }
    
    bool remove(int val) {
        if (arr_pos[val] > 0){
            int old_pos = arr_pos[val];
            int tail = arr[size];
            size--;

            arr[old_pos] = tail;
            arr_pos[tail] = old_pos;
            arr_pos[val] = 0;

            return true;
        }else return false;
    }
    
    int getRandom() {
        int rand_pos = rand() % size + 1;
        return arr[rand_pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */