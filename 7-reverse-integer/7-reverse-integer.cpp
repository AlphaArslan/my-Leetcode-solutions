class Solution {
public:
    int reverse(int x) {
        // handle the special case of zero
        if( x == 0)
        {
            return 0;
        }
        
        // get the absolute value of x
        long int abs_x = abs(x);
        
        // how many digits in abs_x
        int digits = log10(abs_x) + 1;

        // decompose the number into a vector of its digits in reverse
        vector<short> digits_vec(digits, 0);
        for(int i = 0; i < digits && abs_x != 0; i++)
        {
            digits_vec[i] = abs_x % 10;
            abs_x /= 10;
        }
        
        // check if the reversed number is out of range
        if(digits == 10)
        {
            vector<short> max(10);
            if( x >= 0 )
            {
                max = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
            }
            else
            {
                max = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
            }
            
            for(int i = 0; i < 10; i++)
            {
                if(digits_vec[i] > max[i] ) return 0;
                if(digits_vec[i] < max[i] ) break;
            }
        }
        
        // recompose the reversed number
        int rev_x = 0;
        for(int i = 0; i < digits; i++)
        {
            rev_x = rev_x * 10 + digits_vec[i];
        }

        return rev_x * ( x / abs(x) );
    }
};