###Fraction to Recurring Decimal
URL: https://leetcode.com/problems/fraction-to-recurring-decimal/</br>
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

- Given numerator = 1, denominator = 2, return "0.5".
- Given numerator = 2, denominator = 1, return "2".
- Given numerator = 2, denominator = 3, return "0.(6)".

__Code:__

	/*
	 *  Be careful the following cases:
	 *
	 *    > 0/2
	 *    > 1/0
	 *    > 1/3
	 *    > 2/4
	 *    > 100/2
	 *    > 100/3
	 *    > 1/-4
	 *    > -1/4
	 *    > -1/-4
	 *    > 25/99 = 0.25252525....
	 *    > 1/7 = 0.142857142857...
	 *    > 1/17 = 0.(0588235294117647)
	 */

	string fractionToDecimal(int numerator, int denominator) {
	    string result;
	    //deal with the `ZERO` cases
	    if (denominator == 0){ return result; }
	    if (numerator == 0) { return "0"; }

	    //using long long type make sure there has no integer overflow
	    long long n = numerator;
	    long long d = denominator;

	    //deal with negtive cases 
	    bool sign = ((float)numerator/denominator >= 0);
	    if ( n < 0 ){ n = -n; }
	    if ( d < 0 ){ d = -d; }
	    if (sign == false){
	        result.push_back('-');
	    }

	    long long remainder = n % d;
	    long long division = n / d;
	    ostringstream oss;
	    oss << division;
	    result += oss.str();
	    if (remainder == 0){
	        return result;
	    }
	    //remainder has value, the result is a float
	    result.push_back('.');

	    //using a map to record all of reminders and their position.
	    //if the reminder appeared before, which means the repeated loop begin, 
	    //then, get the place from map to insert "(".
	    //(In C++11, it's better to use unordered_map )
	    map<long long, int> rec;

	    for (int pos=result.size(); remainder!=0; pos++, remainder=(remainder*10)%d ) {
	        if (rec.find(remainder) != rec.end()) {
	            result.insert(result.begin()+rec[remainder], '(');
	            result.push_back(')');
	            return result;
	        }
	        rec[remainder] = pos;
	        result.push_back((remainder*10)/d + '0');
	    }

	    return result;
	}