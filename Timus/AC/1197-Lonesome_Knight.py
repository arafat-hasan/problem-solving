#!/usr/bin/env python3
#
# FILE: 1197-Lonesome_Knight.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK:
#
# DATE CREATED: 15-06-18 15:40:41 (+06)
# LAST MODIFIED: 15-06-18 17:29:41 (+06)
#
# VERDICT: Accepted
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------------
# 15-06-18     1.0         Deleted code is debugged code.
#
#               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
#              _/  _/        _/_/    _/    _/    _/_/    _/
#             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
#      _/    _/  _/        _/    _/_/    _/    _/    _/_/
#       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
#
##############################################################################

dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]  # Knight Direction

N = int(input())

while (N > 0):
    N -= 1
    pos = input()
    x = ord(pos[0]) - ord('a')
    y = int(pos[1]) - 1
    ans = 0
    for i in range(0, 8):
        new_x = x + dx[i]
        new_y = y + dy[i]
        if new_x >= 0 and new_x < 8 and new_y >= 0 and new_y < 8:
            ans += 1
    print(ans)
