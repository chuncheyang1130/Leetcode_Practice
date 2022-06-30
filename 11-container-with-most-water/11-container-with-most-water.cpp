class Solution {
public:
    int maxArea(vector<int>& height) {
        int *l = &height.front(), *r = &height.back();
        int highest = *max_element(height.begin(), height.end());
        int M = 0;
        while(l != r){
            if(M > highest * (int)(r-l))
                return M;
            M = max( (int)(r-l)*(int)min(*l, *r) , M);
            if(*l <= *r)
                l++;
            else r--;
        }
        return M;
    }
};