# 10808

# 가벼운 브론즈 문제는 빠르게

import sys

input = sys.stdin.readline

s = input().rstrip()

ref = "abcdefghijklmnopqrstuvwxyz"

arr = [0] * 26

for i in s:
    for k in range(len(ref)):
        if i == ref[k]:
            arr[k] += 1

for i in arr:
    print(i, end=' ')