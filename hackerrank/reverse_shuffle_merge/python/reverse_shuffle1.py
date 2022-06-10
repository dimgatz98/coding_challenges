#!/bin/python3

from collections import OrderedDict
from email.mime import base

#
# Complete the 'reverseShuffleMerge' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def count_occurencies(s):
    count = {}

    for i, letter in enumerate(s):
        if letter not in count:
            count[letter] = [i]
            continue
        count[letter].append(i)

    return count

# Return the index of the smallest element greater than or equal to x, or -1
def binary_search(arr, low, high, x):
    mid = (high + low) // 2

    if high > low:
        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return binary_search(arr, low, mid, x)

        else:
            return binary_search(arr, mid + 1, high, x)

    elif high == low and arr[mid] > x:
        return high

    else:
        return -1

def reverseShuffleMerge(s):
    s = s[::-1]

    count = count_occurencies(s)

    for k, v in count.items():
        count[k] = (int(len(v) / 2), v)

    result = []
    max_half_len = max([x[0] for x in count.values()])
    for _ in range(max_half_len):
        base_index = -1
        for k, v in sorted(count.items(), ):
            if v[1][-1] < base_index:
                base_index = v[1][-1]
                result.append(v[1][-1])
                del count[k][1][-1]
                if len(count[k][1]) == count[k][0]:
                    del count[k]
                continue

            ind = binary_search(v[1], 0, len(v[1]) - 1, base_index)
            result.append(v[1][ind])
            base_index = v[1][ind]
            del count[k][1][ind]
            if len(count[k][1]) == count[k][0]:
                del count[k]

    ret = []
    for x in sorted(result):
        ret.append(s[x])
    return "".join(ret)


if __name__ == '__main__':
    s = input()

    result = reverseShuffleMerge(s)

    print(result + '\n')
