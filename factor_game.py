#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Question: Two players 1,2. Input a number q, players take turns to say a factor of q other than 1
and q, if that number not exist, the player win. Output the first number player 1 will say to win
the game (optimally), if player 2 will win the game, print 2.
"""
q = int(input('Input q:'))

def firstnum(n):  
    if n==1:
        return 0
    else:   
        p = []
        ans=2
        #if there more than 3 prime factors, say the product of the first two
        for i in range(2,n//2+1):
            while n%i==0:           
                n/=i
                p.append(i)
                if len(p)>2:
                    ans=p[0]*p[1]
                    return ans
        return ans       
print(firstnum(q))