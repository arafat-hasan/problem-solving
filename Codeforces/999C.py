#!/usr/bin/env python3
#
# FILE: 999C.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: http://codeforces.com/contest/999/problem/C
#
# DATE CREATED: 22-06-18 16:19:52 (+06)
# LAST MODIFIED: 23-06-18 02:31:13 (+06)
#
# VERDICT: Accepetd
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------------
# 22-06-18     1.0         Deleted code is debugged code.
#
#               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
#              _/  _/        _/_/    _/    _/    _/_/    _/
#             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
#      _/    _/  _/        _/    _/_/    _/    _/    _/_/
#       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
#
##############################################################################

n, k = map(int, input().split())
str = input()
dictionary = dict((letter, str.count(letter)) for letter in set(str))

for item in range(26):
    if k == 0:
        break
    key = chr((item + ord('a')))
    if key in dictionary:
        if dictionary[key] >= k:
            dictionary[key] -= k
            k = 0
            break
        else:
            tmp = dictionary[key]
            dictionary[key] -= k
            k -= tmp


ans = list()

for item in reversed(str):
    if item in dictionary:
        if dictionary[item] > 0:
            dictionary[item] -= 1
            ans.append(item)

print("".join([x for x in list(reversed(ans))]))
