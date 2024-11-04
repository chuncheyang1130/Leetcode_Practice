class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int nrow = moveTime.size();
        int ncol = moveTime[0].size();
        // cout << nrow << " " << ncol << endl;
        
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push(make_pair(0, make_pair(0, 0)));

        while (!pq.empty()){
            pair<int, pair<int,int>> p = pq.top();
            pq.pop();
            int r = p.second.first;
            int c = p.second.second;
            int cur_time = p.first;

            if (visited[r][c])
                continue;
            // cout << r << " " << c << " " << cur_time << endl;
            // cout << cur_time << endl;
            visited[r][c] = true;

            if (r == nrow-1 && c == ncol-1)
                return cur_time;

            if (r != 0 && !visited[r-1][c]){
                int t = max(cur_time+1, moveTime[r-1][c]+1);
                pq.push(make_pair(t, make_pair(r-1, c)));
            }

            if (r != nrow-1 && !visited[r+1][c]){
                int t = max(cur_time+1, moveTime[r+1][c]+1);
                pq.push(make_pair(t, make_pair(r+1, c)));
            }

            if (c != 0 && !visited[r][c-1]){
                int t = max(cur_time+1, moveTime[r][c-1]+1);
                pq.push(make_pair(t, make_pair(r, c-1)));
            }

            if (c != ncol-1 && !visited[r][c+1]){
                int t = max(cur_time+1, moveTime[r][c+1]+1);
                pq.push(make_pair(t, make_pair(r, c+1)));
            }               
        }

        return 0;
    }
};