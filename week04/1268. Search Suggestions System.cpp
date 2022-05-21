// https://leetcode.com/problems/search-suggestions-system/
// Time Complexity: O(N*logN)
// Spcae Complexity: O(logN)

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> results;
        string pattern="";
        
        auto it = products.begin();
        
        for(char ch:searchWord) {
            pattern += ch;
            vector<string> suggestions;
            
            it = lower_bound(it, products.end(), pattern);
            for(int i=0; i<3 && (it + i) != products.end(); i++)
            {
                string& nextPattern=*(it+i);
                if(pattern != nextPattern.substr(0,pattern.size())) 
                    break;
                
                suggestions.push_back(nextPattern);
            }
            
            results.push_back(suggestions);
        }
        
        return results;
    }
};