class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        int n=s.length();
        for(char ch: s){
            if(ch=='{' || ch=='(' || ch=='['){
                s1.push(ch);
            }
            else{
                if(s1.empty()){
                    return false;
                }
                if(ch=='}' && s1.top() != '{'){
                    return false;
                }
                if(ch==')' &&  s1.top()!='('){
                    return false;
                }
                if(ch==']' && s1.top()!='['){
                    return false;
                }
                s1.pop();
            }
        }
        return s1.empty();
    }
};