memo = set()

def get_first_lowercase(a):
    for i, c in enumerate(a):
        if c == c.lower():
            return i
    return -1

def solve(a, b):
    global memo
    if f"{a}{b}" in memo:
        return False
    memo.add(f"{a}{b}")

    i = get_first_lowercase(a)

    if (i == -1 and a != b) or len(a) < len(b) or (a[0] == a[0].upper() and a[0] != b[0]):
        return False
    if a == b:
        return True

    new_a_1 = f"{a[:i]}{a[i + 1:]}"
    new_a_2 = f"{a[:i]}{a[i].upper()}{a[i + 1:]}"
    return solve(new_a_1, b) or solve(new_a_2, b)

if __name__ == '__main__':
    tc = 1
    tc = int(input())

    for i in range(tc):
        a = input()
        b = input()
        result = "YES" if solve(a, b) else "NO"
        print(result)
