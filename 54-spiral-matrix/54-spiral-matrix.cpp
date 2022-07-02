class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int w = matrix[0].size(), h = matrix.size();
        int layer = 0;
        while(w > 1 && h > 1){
            for(int i = layer; i < layer+w-1; i++)
                order.push_back(matrix[layer][i]);
            for(int i = layer; i < layer+h-1; i++)
                order.push_back(matrix[i][layer+w-1]);
            for(int i = layer+w-1; i > layer && h > 1; i--)
                order.push_back(matrix[layer+h-1][i]);
            for(int i = layer+h-1; i > layer && w > 1; i--)
                order.push_back(matrix[i][layer]);
            
            layer++;
            w -= 2;
            h -= 2;
        }
        
        if(h == 1){
            for(int i = layer; i < layer+w; i++)
                order.push_back(matrix[layer][i]);
        }else if(w == 1){
            for(int i = layer; i < layer+h; i++)
                order.push_back(matrix[i][layer]);
        }
        
        return order;
    }
};