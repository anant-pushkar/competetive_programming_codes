'''
Project name : Bishops
Created on : Sat May 24 19:40:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BISHOPS/
'''
import sys
for line in sys.stdin.read().splitlines() : print 2*long(line)-2 if long(line)!=1 else 1