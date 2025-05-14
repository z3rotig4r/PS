def solution(s):
    answer = True
    
    stack = list()
    
    for x in s:
        if x == '(':
            stack.append(x)
        elif x == ')':
            if len(stack) == 0:
                return False
            stack.pop(-1)
            
    if len(stack) != 0:
        answer = False

    return answer