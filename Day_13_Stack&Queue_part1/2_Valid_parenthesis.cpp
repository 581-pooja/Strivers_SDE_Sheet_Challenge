bool isValidParenthesis(string expression)
{
    stack <char> st;
    for(auto it: expression){
        if(it == '(' || it == '{' || it == '['){
            st.push(it);
        }
        else{
            // edge 1: size of stack before popping
            if(st.size() == 0) return false;

            // edge 2: checking matching parenthesis
            // in stack: Opening brackets will be present & compare that to closing brackets 
            char ch = st.top();
            st.pop();
            if((ch == '(' && it == ')')|| 
                (ch == '{' && it == '}')|| 
                (ch == '[' && it == ']')){
                    continue;
            }
            else return false;
        }
    }
    return st.empty();  // edge 3: check stack is empty at end
}