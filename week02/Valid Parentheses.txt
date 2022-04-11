class Solution {
public:
    bool isValid(string s) {
    stack<char> strStack;

    for(int i=0; i<s.size(); i++) {
        if(strStack.empty()){
            strStack.push(s[i]);
            continue;
        }

        if(strStack.top()=='(' && s[i]==')')
            strStack.pop();
        else if(strStack.top()=='{' && s[i]=='}')
            strStack.pop();
        else if(strStack.top()=='['&& s[i]==']')
            strStack.pop();
        else
            strStack.push(s[i]);
    }

    if(strStack.empty())
        return true;
    else
        return false;
    }
};