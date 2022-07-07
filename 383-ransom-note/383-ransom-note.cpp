class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int index;
        for(auto c:ransomNote)
        {
            index = magazine.find(c);
            if( index == string::npos)
                return false;
            magazine[index] = '#';      // anything other than lowercase letters
        }
        return true;
    }
};