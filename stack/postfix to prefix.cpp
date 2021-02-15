Input :  Postfix : AB+CD-*
Output : Prefix :  *+AB-CD

read exp
stack<string> s
push if operand
when operator pop 2 operand AND push concatenated string(operator  + operand1 + operand 2 )



this is method for passing single character:
string op(1, exp[i]);
string op(length, char)
s.push(op)

for passing concatenated string:
string temp = (operator  + operand1 + operand 2 )
s.push(temp)
