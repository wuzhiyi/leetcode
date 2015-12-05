###Evaluate Reverse Polish Notation
URL: https://leetcode.com/problems/evaluate-reverse-polish-notation/</br>
Evaluate the value of an arithmetic expression in [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

Some examples:

	  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
	  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

__Code:__

	class Solution {
	#define ERROR  err=false;continue
	public:
	    int evalRPN(vector<string> &tokens) {
	        int i =0;
	        bool err = false;
	        vector<int> exp;
	        for (int i=0; i<tokens.size() && !err; i++ ){
	            if( isOp(tokens[i])==true ) {
	                if (exp.size() >= 2) {
	                    int lhs, rhs;
	                    rhs = exp.back();
	                    exp.pop_back();
	                    lhs = exp.back();
	                    exp.pop_back();

	                    int evlValue;
	                    if (tokens[i]=="+"){
	                        evlValue = lhs + rhs;    
	                    }else if (tokens[i]=="-"){
	                        evlValue = lhs - rhs;
	                    }else if (tokens[i]=="*"){
	                        evlValue = lhs * rhs;
	                    }else if (tokens[i]=="/"){
	                        evlValue = lhs / rhs;
	                    }
	                    
	                    exp.push_back(evlValue);
	                        
	                }else{
	                    ERROR;
	                }
	            }else if (isNum(tokens[i])) {
	                exp.push_back(value);
	            }else {
	                ERROR;
	            }
	        }
	        if (err==true){
	            return 0;
	        }
	        
	        if (exp.size()==1){
	            return exp.back();
	        }
	        return 0;        
	                
	    }
	    
	private:
	    long value;
	    
	    bool isOp(string &op) {
	        return (op=="+" || op=="-" || op=="*" || op=="/");
	    }
	    
	    bool isNum(string &num) {
	        char *end;
	        value = strtol(num.c_str(), &end, 10); 
	        if (end == num.c_str() || *end != '\0' || errno == ERANGE){
	            return false;
	        }
	        return true;
	    }
	};