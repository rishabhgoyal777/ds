read exp
stack<string> s
push if opaerand
when operator pop 2 operand AND push concatenated string("(" +operand 2 + operator + operand 1 + ")")


this is method for passing single character:
string op(1, exp[i]);
string op(length, char)
s.push(op)

for passing concatenated string:
string temp = ("(" +operand 2 + operator + operand 1 + ")")
s.push(temp)
