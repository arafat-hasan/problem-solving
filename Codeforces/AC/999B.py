#!/usr/bin/env python3
#
# FILE: 999B.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: http://codeforces.com/contest/999/problem/B
#
# DATE CREATED: 22-06-18 01:07:13 (+06)
# LAST MODIFIED: 22-06-18 03:33:43 (+06)
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

n = int(input())
res = list(input())

for i in range(n):
    if n % (i + 1) == 0:
        res[:i+1] = res[i::-1]

print("".join([str(x) for x in res]))
