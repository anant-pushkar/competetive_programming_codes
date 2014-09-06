HOW_MANY_GAMES
======
http://www.spoj.com/problems/GAMES/

DO NOT directly use float()

Example:
```
s = "167.0030"
print float(s)*10000
1670029
```
Split using '.' , and convert each part separately to int
