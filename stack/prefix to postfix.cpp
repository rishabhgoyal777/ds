Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
read exp in reverse
stack<string> s
push if operand
when operator pop 2 operand AND push concatenated string(operand1 + operand 2 + operator )



this is method for passing single character:
string op(1, exp[i]);
string op(length, char)
s.push(op)

for passing concatenated string:
string temp = (operand1 + operand 2 + operator )
s.push(temp)
