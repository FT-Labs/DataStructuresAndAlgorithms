#!/usr/bin/env python

from itertools import permutations

x = input()

cur = int(x)
flag = True

for perm in permutations(x):
    tmp = int("".join(perm))
    if tmp > cur:
        print(tmp)
        flag = False
        break

if flag:
    print(0)
