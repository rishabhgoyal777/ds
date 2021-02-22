Expression contains redundant bracket or not
https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

bool checkRedundancy(string& str)
{
    // create a stack of characters
    stack<char> st;

    // Iterate through the given expression
    for (auto& ch : str) {
  
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();

            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;

            while (top != '(') {

                // Check for operators in expression
                if (top == '+' || top == '-' ||          // mtlb ki bracket ke andar kahi pe operator hai
                    top == '*' || top == '/')
                    flag = false;

                // Fetch top element of stack
                top = st.top();
                st.pop();
            }

            // If operators not found
            if (flag == true)
                return true;
        }

        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
