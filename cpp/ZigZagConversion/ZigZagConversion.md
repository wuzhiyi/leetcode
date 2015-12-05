###ZigZag Conversion
URL: https://leetcode.com/problems/zigzag-conversion/</br>
The string `"PAYPALISHIRING"`is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R

And then read line by line: `"PAHNAPLSIIGYIR"`</br>
Write the code that will take a string and make this conversion given a number of rows:

	string convert(string text, int nRows);

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

__Code:__

	string convert(string s, int nRows) {
	    //The cases no need to do anything
	    if (nRows<=1 || nRows>=s.size()) return s;
	     
	    vector<string> r(nRows);
	    int row = 0;
	    int step = 1;
	    for(int i=0; i<s.size(); i ++) {
	        if (row == nRows-1) step = -1;
	        if (row == 0) step = 1;
	        //cout << row <<endl;
	        r[row] += s[i];
	        row += step;
	    }
	    
	    string result;
	    for (int i=0; i<nRows; i++){
	        result += r[i];
	    }
	    return result;
	}
