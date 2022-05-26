def ValidBrackets(str: s):
    stack = []
    for i in range(len(s)):
        if s[i] in "([{":
            stack.append(s[i])
        elif s[i] == ")" and stack[-1] == "(" and stack != []:
            stack.pop()
        elif s[i] == "]" and stack[-1] == "[" and stack != []:
            stack.pop()
        elif s[i] == "}" and stack[-1] == "{" and stack != []:
            stack.pop()
        else:
            return False
    
    return True if stack == [] else False
