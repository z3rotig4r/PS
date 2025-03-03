# 10799

# 중점적으로 생각한 것: 괄호를 저장하는 데이터 구조가 어떤 것이여야 효율적인 연산이 가능한가?
# 레이저와 쇠막대기의 데이터 표현 차이는 "괄호의 인접성"이다.

# (레이저 개수 + 1) 만큼 쇠막대기 개수가 됨

# 처음에는 Razor Index를 한꺼번에 구해 '막대당' 몇 개로 분할 되는지 세려고 했지만, 비효율적인 연산 Loop 1회로 끝낼 수 있게 계산하기

import sys

input = sys.stdin.readline

s = input().rstrip()

stack = []

result = 0

for i in range(len(s)):
    stack.append(s[i])
    if s[i] == ')': 
        stack.pop()
        if s[i-1] == '(':
            # Razor Part
            stack.pop()
            result += len(stack)
        elif s[i-1] == ')':
            # Stick Part(Edge Case)
            stack.pop()
            result += 1

print(result)