#!/usr/bin/env python3
#
# FILE: 992A.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: http://codeforces.com/contest/992/problem/A
#
# DATE CREATED: 23-06-18 01:51:03 (+06)
# LAST MODIFIED: 23-06-18 01:53:47 (+06)
#
# VERDICT: Accepetd
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------------
# 23-06-18     1.0         Deleted code is debugged code.
#
#               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
#              _/  _/        _/_/    _/    _/    _/_/    _/
#             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
#      _/    _/  _/        _/    _/_/    _/    _/    _/_/
#       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
#
##############################################################################

n = int(input())
st = set(map(int, input().split()))
if 0 in st: st.remove(0)
print(len(st))
