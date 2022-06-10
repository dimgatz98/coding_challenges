#!/bin/python3

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
            count[letter] = [1, [i]]
            continue
        count[letter][1].append(i)
        count[letter][0] += 1

    return count


def reverseShuffleMerge(s):
    count = count_occurencies(s)
    s = s[::-1]

    initial_half_occurencies = {}
    for k, v in count.items():
        initial_half_occurencies[k] = v[0] // 2

    result_occurencies = {}
    result = []
    for letter in s:
        # If letter already in half its total occurencies times skip
        if (
            letter in result_occurencies
            and letter in initial_half_occurencies
            and result_occurencies[letter] == initial_half_occurencies[letter]
        ):
            count[letter][0] -= 1
            continue

        # Delete all the letters on its left that are lexicographically greater
        # and can be found later
        counter = len(result) - 1
        while (
            counter >= 0 and
            result[counter] > letter and
            result_occurencies[result[counter]] - 1 + count[result[counter]][0] >= initial_half_occurencies[result[counter]]
        ):
            result_occurencies[result[counter]] -= 1
            del result[counter]
            counter -= 1

        # Append the letter in the result and update occurencies
        result.append(letter)
        if letter not in result_occurencies:
            result_occurencies[letter] = 1
        else:
            result_occurencies[letter] += 1

        # Decrease the number of remaining occurencies for this letter
        count[letter][0] -= 1

    return "".join(result)


def compare_results(s1, s2, s3):
    print(s1)
    for result in [s2, s3]:
        i = 0
        for letter in result:
            while i < len(s1):
                if s1[i] == letter:
                    print(s1[i], end="")
                    i += 1
                    break
                print(" ", end="")
                i += 1
        print()

if __name__ == '__main__':
    s = input()

    result = reverseShuffleMerge(s)

    print(result + '\n')

    # print("Hackerrank result:")
    # for k, v in count_occurencies("aaaaabccigicgjihidfiejfijgidgbhhehgfhjgiibggjddjjd").items():
    #     print(f"{k}: {v[0]}")

    # print("\nMy result:")
    # for k, v in count_occurencies("aaaaabccigicgjihidfifhejgfijgidgbhhehgjgiibgjddjjd").items():
    #     print(f"{k}: {v[0]}")

    # print()
    # compare_results(
    #     "adigiibbgegjeiagjjiidhfdgdgijaaijfihbjjabchadcigaicgjaihidafigfhhecjgfacijgidgbhhehgfhjgiibggjddcjjd",
    #     "aaaaabccigicgjihidfiejfijgidgbhhehgfhjgiibggjddjjd",
    #     "aaaaabccigicgjihidfifhejgfijgidgbhhehgjgiibgjddjjd"
    # )
