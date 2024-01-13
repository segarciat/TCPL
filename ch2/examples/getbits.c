/* getbits: get n bits form position p. For example, getbits(x, 4, 3) returns three bits in positions 4, 3, 2 
 * assumes position 0 is at the right end, and n and p are sensible positive values
 * */
unsigned getbits(unsigned x, int p, int n)
{
   return (x >> (p+1-n)) & ~(~0 << n);
}
