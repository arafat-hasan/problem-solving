#!/usr/bin/env python3
#
# FILE: Love_Calculator-10424.py
#
# @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
#
# LINK:
#
# DATE CREATED: 10-05-17 17:52:59 (+06)
# LAST MODIFIED: 10-05-17 22:13:53 (+06)
#
# DESCRIPTION:
#
# DEVELOPMENT HISTORY:
# Date         Version     Description
# --------------------------------------------------------------
# 10-05-17     1.0         File Created, Accepted, Accepted
#
#


#     ___          ___           ___                       ___
#    /  /\        /  /\         /__/\        ___          /__/\
#   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
#  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
#  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
#     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
#      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
#      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
#     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
#     \__\/      \  \::/       \  \:\         \__\/      \  \:\
#                 \__\/         \__\/                     \__\/
#

#########################################################################


import string

def fun(n):
    if(n < 10):
        return n
    tmp = 0
    while (n > 0):
        tmp += n%10
        n = int(n/10);
    return fun(tmp)

while(True):
    try:
        str1=input().lower()
    except EOFError:
        break
    str2=input().lower()
    sum1=0
    sum2=0
    sz=len(str1)
    for i in str1:
        if i >= 'a' and i <= 'z':
            sum1 += ord(i) - ord('a') + int(1)
    sz=len(str2)
    for i in str2:
        if i >= 'a' and i <= 'z':
            sum2 += ord(i) - ord('a') + int(1)
    sum1=fun(sum1)
    sum2=fun(sum2)
    if sum1 < sum2:
        sum1, sum2 = sum2, sum1
    print('{0:.2f}'.format(((sum2/sum1)*100)), "%")

