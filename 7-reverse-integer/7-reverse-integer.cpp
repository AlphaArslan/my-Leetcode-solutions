class Solution {
public:
    int reverse(int x) {
        // handle the special case of zero and -2147483648
        if( x == 0 || x == -2147483648 )
        {
            return 0;
        }
        
        // get the absolute value of x
        int abs_x = abs(x);
        short sign = ( x >= 0 )? 1 : -1;
        
        // how many digits in abs_x
        int digits = log10(abs_x) + 1;

        // decompose the number into a vector of its digits in reverse
        vector<short> digits_vec(digits);
        for(int i = 0; i < digits; i++)
        {
            digits_vec[i] = abs_x % 10;
            abs_x /= 10;
        }
        
        // check if the reversed number is out of range
        if(digits == 10)
        {
            vector<short> max = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
            
            for(int i = 0; i < 10; i++)
            {
                if(digits_vec[i] > max[i] ) return 0;
                if(digits_vec[i] < max[i] ) break;
            }
        }
        
        // recompose the reversed number
        int rev_x = digits_vec[digits - 1];
        int mul = 1;
        for(int i = digits - 2; i >= 0; i--)
        {
            mul *= 10;
            rev_x += digits_vec[i] * mul;
        }

        return rev_x * sign ;
    }
};