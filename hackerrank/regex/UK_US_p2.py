# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

n = int(input())
lines = []
for i in range(n):
    lines.append(input())

t = int(input())
uk_words = []
for i in range(t):
    uk_words.append(input())

words = []
for x in uk_words:
    words.append((re.compile(r"our").sub("or", x), x))

print("words: " , words, "\n", "uk_words: ", uk_words, "\n", "lines: ", lines, sep="")
# count = 0
# for line in lines:
#     for w in line.split(" "):
#         if w == "neighbor" or w == "neighbour":
#             # print(w)
#             count += 1
# print(count)

for (w1, w2) in words:
    res = 0
    for line in lines:
        expr = re.compile("^"+w1+" |^"+w1+"$| "+w1+" | "+w1+"|"+w1+" |"+w1+"$|^"+w2+" |^"+w2+"$| "+w2+" | "+w2+"$|"+w2+" |"+w2+"$")
        res += len(expr.findall(line))
    print(res)
