#!/usr/bin/env python

from itertools import permutations

x = input()

cur = int(x)
flag = True
mn = 1e20

for perm in permutations(x):
    tmp = int("".join(perm))
    if tmp > cur:
        mn = min(mn, tmp)
        flag = False

if flag:
    print(0)
else:
    print(mn)
