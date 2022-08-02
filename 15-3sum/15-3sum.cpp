class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        short i = 0, j = 0, k = 0;
        vector<vector<int>> triplets;
        
        // sort the numbers and remove any duplicate elements
        sort( nums.begin(), nums.end() );
        short size = nums.size();
        
        // loop over the sorted set and extract triplets
        while(i < size - 2)
        {
            j = i + 1;
            k = size - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    triplets.push_back( {nums[i], nums[j], nums[k]} );
                }
                if(sum >= 0)
                {
                    k--;
                    // avoid duplicates in k
                    while(j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else
                {
                    j++;
                }
            }
            
            i++;
            // prevent duplicales in i
            while(i < size - 2 && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        
        //triplets.erase( unique( triplets.begin(), triplets.end() ), triplets.end() );
        return triplets;
    }
};