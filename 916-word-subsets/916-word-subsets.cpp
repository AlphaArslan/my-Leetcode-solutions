class Solution {
public:
    vector<int> getCharacterContent(string s)
    {
        /* returns how many times a character (a,.. z) exists in a string s */
        
        vector<int> char_content(26, 0);
        
        for(char c : s)
        {
            char_content[c - 'a']++;
        }
        
        return char_content;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> universalWords;
        
        // reduce all strings in words2 to a minimal superset
        // a minimal superset is a word that combines all subsets with no extra.
        // we will only calculate the character content of that minimal superset.
        vector<int> bmax_content(26, 0);
        vector<int> b_content;
        for(string b : words2)
        {
            b_content = getCharacterContent(b);
            for(int i = 0; i < 26; i++)
            {
                bmax_content[i] = max(bmax_content[i], b_content[i]);
            }
        }
        
        
        // now check every string a in words1 against bmax_content
        vector<int> a_content;
        for(string a : words1)
        {
            a_content = getCharacterContent(a);
            for(int i = 0; i < 26; i++)
            {
                if(a_content[i] < bmax_content[i])
                {
                    goto NOT_UNIVERSAL;
                }
            }
            
            // we only reeach here if a is universal
            universalWords.push_back(a);
            
            NOT_UNIVERSAL:
            ;
        }
        
        return universalWords;
    }
};