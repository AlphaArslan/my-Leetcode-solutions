class Solution {
public:
    int myAtoi(string s) {
        long int number = 0;
        unsigned short index = 0;
        short sign = 1;
        
        // skip whitespaces
        while(s[index] == ' ')
        {
            index++;
        }
        
        // detect sign
        if(s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if(s[index] == '+')
        {
            sign = 1;
            index++;
        }
        
        // skip leading zeroes
        while(s[index] == '0')
        {
            index++;
        }
        
        // yeild the number
        short digits_num = 0;
        while(isdigit(s[index]) && digits_num < 11 )
        {
            number *= 10;
            number += s[index] - '0';
            index++;
            digits_num++;
        }
        
        // apply the sign
        number *= sign;
        
        // check for off-limit numbers
        if(number > INT_MAX)
        {
            return INT_MAX;
        }
        else if(number < INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            return (int)number;
        }
    }
};