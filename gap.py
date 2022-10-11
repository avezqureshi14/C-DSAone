def solution(N):
    res = 0
    st = -1
    for i in range(N.bit_length()):
        if N & (1 << i):
            if st != -1:
                res = max(res, i - st - 1)
            st = i

    return res