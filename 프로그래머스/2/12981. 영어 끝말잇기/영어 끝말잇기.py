def solution(n, words):
    answer = []

    # 번호는 n%i + 1
    # 차례는 n/i + 1
    
    length = len(words)
    
    for i, x in enumerate(words):
        if i == length -1:
            answer = [0, 0]
            break
        next = words[i+1]
        if x[-1] != next[0] or next in words[:i+1]:
            answer.append((i+1)%n + 1)
            answer.append((i+1)//n + 1)
            return answer
            
    return answer