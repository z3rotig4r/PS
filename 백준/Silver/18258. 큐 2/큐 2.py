# 18258
import sys
from collections import deque

# push
def push(queue, num):
    queue.append(num)
# pop
def pop(queue):
    if len(queue) == 0:
        print(-1)
    else:
        print(queue.popleft())
# size
def size(queue):
    print(len(queue))
# empty
def empty(queue):
    if len(queue) == 0:
        print(1)
    else:
        print(0)
# front
def front(queue):
    if len(queue) == 0:
        print(-1)
    else:
        print(queue[0])
# back
def back(queue):
    if len(queue) == 0:
        print(-1)
    else:
        print(queue[-1])
# main func
def main():
    N = int(input())
    queue = deque()
    for _ in range(N):
        inline = sys.stdin.readline().split()
        cmd = inline[0]
        if cmd == 'push':
            num = int(inline[1])
            push(queue, num)
        elif cmd == 'pop':
            pop(queue)
        elif cmd == 'size':
            size(queue)
        elif cmd == 'empty':
            empty(queue)
        elif cmd == 'front':
            front(queue)
        elif cmd == 'back':
            back(queue)

if __name__ == '__main__':
    main()