using Coord = pair<int,int>;
using State = pair<Coord, int>;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int nrow = moveTime.size();
        int ncol = moveTime[0].size();
        // cout << nrow << " " << ncol << endl;
        
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> pq;
        Coord sp(0, 0);
        State sp_state(sp, 1);
        pq.push(make_pair(0, sp_state));

        while (!pq.empty()){
            pair<int, State> p = pq.top();
            pq.pop();
            int cur_time = p.first;
            State st = p.second;

            Coord coord = st.first;
            int mov = st.second;

            int r = coord.first;
            int c = coord.second;

            if (visited[r][c])
                continue;
            // cout << r << " " << c << " " << cur_time << endl;
            // cout << cur_time << endl;
            visited[r][c] = true;

            if (r == nrow-1 && c == ncol-1)
                return cur_time;

            if (r != 0 && !visited[r-1][c]){
                int t = max(cur_time+mov, moveTime[r-1][c]+mov);
                State st(make_pair(r-1, c), 3-mov);
                pair<int, State> tmp(t, st);
                pq.push(tmp);
            }

            if (r != nrow-1 && !visited[r+1][c]){
                int t = max(cur_time+mov, moveTime[r+1][c]+mov);
                State st(make_pair(r+1, c), 3-mov);
                pair<int, State> tmp(t, st);
                pq.push(tmp);
            }

            if (c != 0 && !visited[r][c-1]){
                int t = max(cur_time+mov, moveTime[r][c-1]+mov);
                State st(make_pair(r, c-1), 3-mov);
                pair<int, State> tmp(t, st);
                pq.push(tmp);
            }

            if (c != ncol-1 && !visited[r][c+1]){
                int t = max(cur_time+mov, moveTime[r][c+1]+mov);
                State st(make_pair(r, c+1), 3-mov);
                pair<int, State> tmp(t, st);
                pq.push(tmp);
            }               
        }

        return 0;        
    }
};