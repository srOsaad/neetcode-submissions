class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for x in s:
            if x=='[' or x=='{' or x=='(':
                stack.append(x)
            else:
                if len(stack)>0:
                    if (x == ')' and stack[len(stack)-1]=='(') or (x=='}' and stack[len(stack)-1]=='{') or (x==']' and stack[len(stack)-1]=='['):
                        stack.pop(len(stack)-1)
                    else:
                        return False
                else:
                    return False
        return len(stack)==0