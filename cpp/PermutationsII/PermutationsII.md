###Permutations II
URL: https://leetcode.com/problems/permutations-ii/</br>
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,</br>
`[1,1,2]` have the following unique permutations:</br>
`[1,1,2]`, `[1,2,1]`, and `[2,1,1]`.

__Code:__

	// To deal with the duplication number, we need do those modifications:
	//    1) sort the array [pos..n].
	//    2) skip the same number.
	vector<vector<int> > permute(vector<int> &num) {

	    vector<vector<int> > vv;
	    vv.push_back(num);

	    if (num.size() <2){
	        return vv;
	    }
	        
	    int pos=0;
	    while(pos<num.size()-1){
	        int size = vv.size();
	        for(int i=0; i<size; i++){
	            //sort the array, so that the same number will be together
	            sort(vv[i].begin()+pos, vv[i].end());
	            //take each number to the first
	            for (int j=pos+1; j<vv[i].size(); j++) {
	                vector<int> v = vv[i];
	                //skip the same number 
	                if (j>0 && v[j]==v[j-1]){
	                    continue;
	                }
	                int t = v[j]; 
	                v[j] = v[pos];
	                v[pos] = t;
	                vv.push_back(v);
	            }
	        }
	        pos++;
	    }
	    return vv;
	}