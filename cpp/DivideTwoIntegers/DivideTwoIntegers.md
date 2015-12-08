###Divide Two Integers
URL: https://leetcode.com/problems/divide-two-integers/</br>
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

__Code:__

	#define INT_MAX     2147483647
	#define INT_MIN     (-INT_MAX - 1)

	int divide(int dividend, int divisor) {

	    int sign = (float)dividend / divisor > 0 ? 1 : -1;
	    unsigned int dvd = dividend > 0 ? dividend : -dividend;
	    unsigned int dvs = divisor > 0 ? divisor : -divisor;

	    unsigned int bit_num[32];
	    unsigned int i=0;
	    long long d = dvs;
	    bit_num[i] = d;
	    while( d <= dvd ){
	        bit_num[++i] = d = d << 1;
	    }
	    i--;

	    unsigned int result = 0;
	    while(dvd >= dvs){
	        if (dvd >= bit_num[i]){
	            dvd -= bit_num[i];
	            result += (1<<i);
	        }else{
	            i--;
	        }
	    }

	    //becasue need to return `int`, so we need to check it is overflowed or not.
	    if ( result > INT_MAX && sign > 0 ) {
	        return INT_MAX;
	    }
	    return (int)result * sign;
	}