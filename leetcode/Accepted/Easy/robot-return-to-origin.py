#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# FILE: robot-return-to-origin.py
#
# @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
#
# LINK: https://leetcode.com/problems/robot-return-to-origin/
#
# DATE CREATED: 21-01-21 01:53:55 (+06)
# LAST MODIFIED: 21-01-21 01:58:50 (+06)
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------------
# 21-01-21     1.0         Deleted code is debugged code.
#
#               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
#              _/  _/        _/_/    _/    _/    _/_/    _/
#             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
#      _/    _/  _/        _/    _/_/    _/    _/    _/_/
#       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
#
##############################################################################


class Solution:
    def judgeCircle(self, moves: str) -> bool:
        countL = 0
        countR = 0
        countD = 0
        countU = 0

        for item in moves:
            if item == 'R':
                countR += 1
            elif item == 'L':
                countL += 1
            elif item == 'D':
                countD += 1
            elif item == 'U':
                countU += 1

        if countU == countD and countL == countR:
            return True
        else:
            return False
