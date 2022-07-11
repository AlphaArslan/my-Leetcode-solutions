class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            1- create a vector "Substring Length" of length = s.size
            2- for each character in the string find how far the next instance
               of this character is (i.e., the length of a non repeating substring)
               and save this value into the "Substring Length" vector.
            3- loop over the vector elements to correct any illegal values.
            4- return max value in vector.
            
            Example:
            String =        "abbcdd"
            vector of substring lengthes = [6, 1, 4, 3, 1, 1]
                Note: 6 is followed by 1, which is not logical. Hence, 6 is modified to 2.
            modified vector = [2, 1, 3, 2, 1, 1]
            max value = 3 (for the "bcd" substring).
            
        */
        
        // save string length
        int str_len = s.size();
        
        // to save the index of the found character.
        int found_idx = 0;
        
        vector<int> substring_len(str_len);
        
        for (int i = 0; i < str_len; i++)
        {
            // find the next instance
            found_idx = s.find(s[i], i+1);
            
            // save it to the vector
            if(found_idx != -1)
            {
                substring_len[i] = found_idx - i;
            }
            else
            {
                substring_len[i] = str_len - i;
            }
            
            //cout << substring_len[i] << endl;
        }
        
        // modify the vector to fix any illegal values and get the max value afet modefication
        int last = 0, max = 0;
        for(int i = str_len - 1; i >=0; i--)
        {
            // modify illegal values
            if(substring_len[i] > last + 1)
            {
                substring_len[i] = last + 1;
            }
            
            // find max
            if(substring_len[i] > max)
            {
                max = substring_len[i];
            }
            
            last = substring_len[i];
            
            //cout << last << endl;
        }
        
        return max;
    }
};