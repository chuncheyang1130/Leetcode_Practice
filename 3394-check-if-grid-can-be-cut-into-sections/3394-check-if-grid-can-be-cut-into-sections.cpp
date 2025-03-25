class Solution {
public:
    static bool cmpByX(vector<int>& v0, vector<int>& v1){
        if (v0[0] < v1[0] || (v0[0] == v1[0] && v0[2] < v1[2]))
            return true;
        return false;
    }
    static bool cmpByY(vector<int>& v0, vector<int>& v1){
        if (v0[1] < v1[1] || (v0[1] == v1[1] && v0[3] < v1[3]))
            return true;
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        stack<int> st_x;
        st_x.push(0);

        sort(rectangles.begin(), rectangles.end(), cmpByX);
        for (int i = 0; i < rectangles.size(); i++){
            if (rectangles[i][0] >= st_x.top())
                st_x.push(rectangles[i][2]);
            else if (rectangles[i][2] > st_x.top()){
                st_x.pop();
                st_x.push(rectangles[i][2]);
            }
        }
        
        if (st_x.size() >= 4)
            return true;

        stack<int> st_y;
        st_y.push(0);
        sort(rectangles.begin(), rectangles.end(), cmpByY);
        for (int i = 0; i < rectangles.size(); i++){
            if (rectangles[i][1] >= st_y.top())
                st_y.push(rectangles[i][3]);
            else if (rectangles[i][3] > st_y.top()){
                st_y.pop();
                st_y.push(rectangles[i][3]);
            }
        }

        if (st_y.size() >= 4)
            return true;

        return false;
    }
};