class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int sum;
        while(n != 1){
            st.insert(n);
            sum = 0;
            
            while(n != 0){
                sum += pow(n%10, 2);
                n /= 10;
            }
            if(st.find(sum) != st.end())
                return false;
            n = sum;
        }
        return true;
    }
};