class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> table;

        for(int i = 0; i < tasks.size(); i++)
            table[tasks[i]]++;
        
        int count = 0, round_count = 0;
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>> > pq;
        vector<char> round_task;
        
        for(auto it = table.begin(); it != table.end(); it++)
            pq.push(pair<int, char>(it->second, it->first));
        
        while(true){
            if(pq.empty()){
                count += (-n-1+round_count);
                break;
            }
            
            round_count = 0;
            for(int i = 0; i < n+1; i++){
                if(pq.empty())
                    break;
                else{
                    pair<int, char> task = pq.top();
                    round_count++;
                    pq.pop();
                    table[task.second]--;
                    round_task.push_back(task.second);
                }
            }
            
            count += n+1;
            
            for(int i = 0; i < round_task.size(); i++){
                if(table[round_task[i]] > 0)
                    pq.push(pair<int, char>(table[round_task[i]], round_task[i]));
            }
            round_task.clear();
        }

        return count;
    }
};