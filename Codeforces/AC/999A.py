#!/usr/bin/env python3
#
# FILE: 999A.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: http://codeforces.com/contest/999/problem/A
#
# DATE CREATED: 22-06-18 00:48:55 (+06)
# LAST MODIFIED:
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
problem_list = list(map(int, input().split()))

ans = 0

for item in problem_list:
    if(item <= k):
        ans += 1
    else:
        break

if ans != n:
    for item in reversed(problem_list):
        if(item <= k):
            ans += 1
        else:
            break

print(ans)

