AMZ_Word
======
http://www.spoj.com/problems/AMZSEQ/

one[i] = one[i-1] + two[i-1]
two[i] = one[i-1] + two[i-1] + thr[i-1]
thr[i] = two[i-1] + thr[i-1]

/        \   /       \   /          \
| one[i] |   | 1 1 0 |   | one[i-1] |
| two[i] | = | 1 1 1 | * | two[i-1] |
| thr[i] |   | 0 1 1 |   | thr[i-1] |
\        /   \       /   \          /

/        \   /       \i-1 /        \
| one[i] |   | 1 1 0 |    | one[1] |
| two[i] | = | 1 1 1 | *  | two[1] |
| thr[i] |   | 0 1 1 |    | thr[1] |
\        /   \       /    \        /

one[1] = 1
two[1] = 1
thr[1] = 1

ans[n] = one[n] + two[n] + thr[n]
