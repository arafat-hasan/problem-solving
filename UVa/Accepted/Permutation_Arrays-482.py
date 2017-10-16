#!/usr/bin/env python3

T=int(input())
while (T > 0):
    input()
    v = [int(x) for x in input().split()]
    T -= 1
    text = input()
    text=text.split(' ')
    data= [None] * len(v)
    j=int(0)
    for i in v:
        data[i-1] = text[j]
        j += 1
    for i in data:
        print(i)
    if T != 0:
        print()

