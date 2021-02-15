Input :  Prefix :  *+AB-CD
Output : Infix : ((A+B)*(C-D))

read exp in reverse
stack<string> s
push if opaerand
when operator pop 2 operand AND push concatenated string("(" +operand1 + operator + operand 2 + ")")



this is method for passing single character:
string op(1, exp[i]);
string op(length, char)
s.push(op)

for passing concatenated string:
string temp = ("(" +operand1 + operator + operand 2 + ")")
s.push(temp)
