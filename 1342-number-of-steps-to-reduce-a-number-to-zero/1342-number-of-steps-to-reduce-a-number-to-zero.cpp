class Solution {
public:
    int numberOfSteps(int num) {
        
        int steps = 0;
        
        // reduce the number until it's zero
        while (num != 0)
        {
            if(num % 2 == 0)
                num /= 2;
            else
                num -= 1;
            
            steps++;
        }
        
        return steps;
    }
};