#include <stdio.h> /* printf */
#define XMAX 1024
#define YMAX 768

struct point {
    int x;
    int y;
};

/* rect: represents a rectangle by the coordinates of diagonally opposite corners
 * (bottom left corner, top right corner */
struct rect {
    struct point pt1;
    struct point pt2;
};

int main()
{
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
		       (screen.pt1.y + screen.pt2.y)/2);

    struct point *pp;
    pp = &middle;
    /* printf("middle of screen is (%d,%d)\n", (*pp).x, (*pp).y); */
    printf("middle of screen is (%d,%d)\n", pp->x, pp->y);
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not.
 * Convention adopted: rectangle includes left and bottom, but not top and right sides */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
	&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of a rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = min(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

