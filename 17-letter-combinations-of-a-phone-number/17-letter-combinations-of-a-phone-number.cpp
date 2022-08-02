class Solution {
private:
    vector<vector<string>> digitString_lut = {
        {"a", "b", "c"},              // 2
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}          // 9
    };
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combination;
        
        for(auto digit : digits)
        {
            if(combination.size() == 0)
            {
                for(auto c : digitString_lut[digit - '2'])
                {
                    combination.push_back(c);
                }
            }
            else
            {
                vector<string> temp;
                for(auto c : digitString_lut[digit - '2'])
                {
                    for(auto s : combination)
                    {
                        temp.push_back(s + c);
                    }
                }
                combination = temp;
            }
        }
        
        return combination;
    }
};