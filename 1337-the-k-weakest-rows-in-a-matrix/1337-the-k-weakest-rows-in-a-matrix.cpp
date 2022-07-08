typedef pair<short, int> pair_t;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // we are going to loop over the rows [ vector<int> ]
        // the sum of each row indicates the number of soldiers.
        // number of soldiers will be stored in vector<int> soldier_vec,
        // soldier_vec will then be sorted and Kth element will be extracted.
        
        vector<int> rv;
        vector<pair_t> soldier_vec;
        
        // calculate number of soldiers in each row.
        int i = 0;
        for(auto row : mat)
        {
            //cout << accumulate(row.begin(), row.end(), 0) << endl;
            soldier_vec.push_back( { i , accumulate(row.begin(), row.end(), 0) } );
            
            i++;
        }
        
        // sort rows from weakest to strongest
        // sort based on the second element in pair (soldiers_num)
        // if equal, sort based on the first element in pair (row index)
        sort(soldier_vec.begin(), soldier_vec.end(),
            [](const pair_t &l, const pair_t &r)
             {
                // if the number of soldiers is not equal, return smaller 
                if (l.second != r.second) {
                    return l.second < r.second;
                }

                // if the number of soldirs is equal, return smaller index.
                return l.first < r.first;
             }
            );
        
        
        for(int i = 0; i < k; i++)
        {
            cout << "row: " << soldier_vec[i].first << "  soldiers:" << soldier_vec[i].second << endl;
            rv.push_back(soldier_vec[i].first);
        }
        
        
        return rv;
        
    }
};