class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> exprs;
        for(char ch : expression){
            if(ch == '(' || ch == ',')
                continue;
            if(ch == 't' || ch == 'f' || ch == '|' || ch == '&' || ch == '!'){
                exprs.push(ch);
            }
            else if(ch == ')'){
                bool isFalse = false, isTrue = false;
                char newExpr = 't';
                while(exprs.top() != '!' && exprs.top() != '&' && exprs.top() != '|'){
                    if(exprs.top() == 'f') isFalse = true;
                    if(exprs.top() == 't') isTrue = true;
                    exprs.pop();
                }
                if(exprs.top() == '&'){
                    newExpr = isFalse ? 'f' : 't';
                }
                else if(exprs.top() == '|'){
                    newExpr = isTrue ? 't' : 'f';
                }
                else newExpr = isFalse ? 't' : 'f';
                exprs.pop();
                
                exprs.push(newExpr);
               
            }
        }
        return exprs.top() == 't';
    }
};