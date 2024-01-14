# Exercise 2-9

In a two's complement number system, `x &= (x-1)` deletes the rightmost 1-bit in `x`. Explain why.
Use this observation to write a faster version of `bitcount`.

## Answer

In a two's complement number system, -1 is assigned a 1 at every bit position. The operation `x-1` is equivalent to
`x+(-1)`. Suppose the rightmost 1-bit is at position _n_ from the right. The bits at positions 0,...,_n-1_ are all 0s,
and when computing the sum `x+(-1)`, they all become 1. At position _n_, we add the rightmost 1 of `x` to the `1`
from `(-1)`, which flips that to a 0, and forces a 1 to be carried. There are two possibilities at position _n+1_:

1. If `x` has a 0-bit, the 1-carry from the previous column and the 1-bit from the `(-1)` are added, resulting
again in 0, and a carry 1-bit.

2. If `x` has a 1-bit, then that bit, plus the carry, plus the 1-bit from the `(-1)` make up 3, which in binary is
1, and a 1 is carried over.

In both cases, the _(n+1)_-th bit of `x` is unchanged, and a 1 is carried. By induction, this happens for every other
position thereafter. The result is that `x` is unchanged, except that the rightmost 1 and every bit to the right of it is flipped (negated). Now computing `&` of this resulting number `(x-1)` with `x` leaves all bits to the left of the
rightmost 1 of `x` unchanged, and since every bit to the right of and including the rightmost 1 has been inverted, they
all become 0 with the `&` operation. Since every bit to the right of the rightmost 1 was already 0 in `x`, the result
is that only the 1 at the _n_-th position changed, to 0.
