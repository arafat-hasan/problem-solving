#!/usr/bin/env python3
#
# FILE: 994A.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: http://codeforces.com/contest/994/problem/A
#
# DATE CREATED: 17-06-18 22:29:02 (+06)
# LAST MODIFIED: 17-06-18 23:15:25 (+06)
#
# VERDICT: Accepetd
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------------
# 17-06-18     1.0         Deleted code is debugged code.
#
#               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
#              _/  _/        _/_/    _/    _/    _/_/    _/
#             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
#      _/    _/  _/        _/    _/_/    _/    _/    _/_/
#       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
#
##############################################################################

n, m = map(int, input().split())

n_list = list(map(int, input().split()))
m_list = list(map(int, input().split()))

ans = []

for item in n_list:
    if item in m_list:
        ans.append(item)
print (" ".join([str(x) for x in ans]))
