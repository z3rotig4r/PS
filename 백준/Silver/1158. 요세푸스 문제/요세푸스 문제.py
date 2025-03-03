# 1158

# 계산 예시 몇 개로 해보니 딱 "LINKED-LIST" 견적이 나옴

# 출력 구현이 생소해서 난이도에 비해 어려웠던 느낌

from collections import deque

N, K = map(int, input().split())
cnt = 0

result = []

link_list = deque()
for i in range(N):
    link_list.append(i+1)

while len(link_list):
    cnt += 1
    if cnt == K:
        p = link_list.popleft()
        result.append(p)
        cnt = 0
    else:
        tmp = link_list.popleft()
        link_list.append(tmp)

formatted = f"<{', '.join(str(x) for x in result)}>"
print(formatted)