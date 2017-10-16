# import sys
while(True):
    try:
        hashm=raw_input()
    except EOFError:
        break
    hashm=int(hashm)
    opp=input()
    print(opp - hashm)
