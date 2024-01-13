int main()
{
}

/* setbits: sets n bits of x starting at p to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned rightNBitsY = y & ~(~0 << n);
    unsigned desiredBits = (~0 << (p + n)) | (rightNBitsY << p) | ~(~0 << n);;

    return x & desiredBits; 
}
