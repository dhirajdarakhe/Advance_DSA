//  https://practice.geeksforgeeks.org/problems/power-set4302/1#
void f(string s,vector<string> &ans, string x, int i)
	    {
	        if(i>=s.size()) 
	        {
	           if(x.size()) ans.push_back(x);
	            return;
	        }
	        f(s, ans, x+s[i], i+1);
	        f(s, ans, x, i+1);
	    }
	    bool com(string s, string x)
	    {
	       // if()
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    
		    f(s, ans, "", 0);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
