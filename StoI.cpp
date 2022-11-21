class Solution {
public:
    int myAtoi(string s) {
    
        long int result = 0;
        bool isnegative = false, NoFound=false, checked = false;

        for(int i = 0; i < s.length(); i++) {
            
            if(s[i] >= 48 && s[i] <= 57) {

                result *= 10;
                result += (s[i] - 48);
                NoFound = true;

                if( result > INT_MAX || result < INT_MIN)
                    break;  

            }

            else if(NoFound)
                break;

            else if((s[i] == 45 || s[i] == 43) && !checked){

                if(s[i] == 45)
                    isnegative = true;
                checked = true;

            } 
                
            else if(checked || s[i] != 32)
                break;          

        }

        if(isnegative)
            result *= -1;
        
        if(result > INT_MAX)
            return INT_MAX;

        else if(result < INT_MIN)
            return INT_MIN;

        return result;
    }
};