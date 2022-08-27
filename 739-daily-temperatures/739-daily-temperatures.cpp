class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> temp;
        temp.push(0);
        
        for(int i = 1; i < temperatures.size(); i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                int top = temp.top();
                ans[top] = i - top;
                temp.pop();
            }
            temp.push(i);
        }
        return ans;
        
    }
};