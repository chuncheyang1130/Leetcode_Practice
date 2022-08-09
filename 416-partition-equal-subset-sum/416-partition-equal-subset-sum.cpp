class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        
        set<int> st;
        vector<int> new_element;
        
        for(int i = 0; i < nums.size(); i++){
            for(auto it = st.begin(); it != st.end(); it++)
                new_element.push_back(*it+nums[i]);
            
            for(int i = 0; i < new_element.size(); i++)
                st.insert(new_element[i]);
            
            st.insert(nums[i]);
            new_element.clear();
            total += nums[i];
        }
        
        if(total % 2)
            return false;
        else return st.find(total/2) != st.end();
    }
};