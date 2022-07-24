class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> suit(4, 0), rank(13, 0);
        for(int i = 0; i < suits.size(); i++){
            suit[suits[i]-'a']++;
            rank[ranks[i]-1]++;
            if(suit[suits[i]-'a'] == 5)
                return "Flush";
            if(rank[ranks[i]-1] == 3)
                return "Three of a Kind";
        }
        
        for(int i = 0; i < rank.size(); i++){
            if(rank[i] == 2)
                return "Pair";
        }
        return "High Card";
    }
};