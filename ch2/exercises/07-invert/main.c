int main()
{
}

/* invert: flips the n bits of x starting at p; p and n are positive */
unsigned invert(unsigned x, int p, int n)
{
    unsigned xBitsToFlip = (x >> (p+1-n)) & ~(~0 << n);
    unsigned desiredBits = (~0 << (p + n)) | ~(xBitsToFlip << p) | ~(~0 << n);;

    return x & desiredBits; 
}
