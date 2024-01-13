int main()
{
}

/* invert: flips the n bits of x starting at p; p and n are positive */
unsigned invert(unsigned x, int n)
{
    /* still missing n bits on the left */
    unsigned leftBitsShiftedRight = x >> n;
    unsigned rightBitsShiftedLeft = x & ~(~0 << n);

    unsigned m = leftBitsShiftedRight;
    while (m > 0) {
	rightBitsShiftedLeft << 1;
	m >> 0;
    }

    return rightBitsShiftedLeft | leftBitsShiftedRight; 
}
