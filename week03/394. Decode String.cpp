// https://leetcode.com/problems/decode-string/
// Time Complexity: O(N)
// Space Complexity: O(N) 

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> words;
        string result = "";
        int i = 0;

        while(i < s.length()){
            if(isdigit(s[i])){
                int count = 0;
                while(isdigit(s[i])){
                    count = count*10 + (s[i] - '0');
                    i++;
                }
                counts.push(count);
            }
            else if(s[i] == '['){
                words.push(result);
                result = "";
                i++;
            }
            else if(s[i] == ']'){
                string temp = words.top();
                words.pop();
                int count = counts.top();
                counts.pop();
                while(count--){
                    temp += result;
                }
                result = temp;
                i++;
            }
            else{
                result += s[i];
                i++;
            }
        }

        return result;
    }
};