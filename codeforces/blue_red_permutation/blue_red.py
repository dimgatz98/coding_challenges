
def solve(ar, colors):
    print()
    l = []
    for i in range(len(ar)):
        l.append([])

    for i in range(len(ar)):
        if colors[i] == 'B':
            if ar[i] < 1:
                print("NO")
            start = ar[i] - 1 if ar[i] <= len(ar) else len(ar) - 1
            for j in range(start, -1, -1):
                l[j].append(i)

        if colors[i] == 'R':
            if ar[i] > len(ar):
                print("NO")
            start = ar[i] - 1 if ar[i] >= 1 else 0
            for j in range(start, len(ar)):
                l[j].append(i)

    sorted_list = list(sorted(l, key = len))
    # delete repetitively the least important element
    # # of the least populated list from sorted_list

if __name__ == '__main__':
    tc = int(input())
    for i in range(tc):
        n = int(input())
        tmp = input()
        ar = list([int(x) for x in tmp.split(" ")])
        colors = input()
        solve(ar, colors)
