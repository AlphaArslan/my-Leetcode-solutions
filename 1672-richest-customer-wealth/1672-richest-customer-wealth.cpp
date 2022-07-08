class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // get the sums of all row
        // then return their max
        
        int max = 0, sum = 0;
        
        for(auto r : accounts)
        {
            sum = accumulate(r.begin(), r.end(), 0);
            if(sum > max)
                max = sum;
        }
        
        return max;
    }
};