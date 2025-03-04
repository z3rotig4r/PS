# 1406

# Linked List 형태.
# 단순한 배열 문제는 아님
# stack을 사용해야 하는가? => ㅙ? => 
from collections import deque
import sys

input = sys.stdin.readline

stack = list(input().strip())
N = int(input())

length = len(stack)

tmp_list = deque()

# cursor -> Index ? 0a1b2c3d4

for _ in range(N):
    word = input().strip().split()

    if word[0] == 'L':
        # CASE 1
        if len(stack) > 0:
            tmp_list.appendleft(stack.pop())
    elif word[0] == 'D':
        # CASE 2
        if len(tmp_list) > 0:
            stack.append(tmp_list.popleft())
    elif word[0] == 'B':
        # CASE 3
        if len(stack) > 0:
            stack.pop()
            length -= 1
    elif word[0] == 'P':
        # CASE 4
        stack.append(word[1])
        length += 1

tmp_list = list(tmp_list)
print(''.join(stack+tmp_list))