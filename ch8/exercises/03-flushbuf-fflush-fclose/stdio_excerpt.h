#ifndef _H_STDIO_EXCERPT
#define _H_STDIO_EXCERPT
#ifndef NULL
#define NULL		0
#endif
#define EOF		(-1)
#define BUFSIZ		8192
#define OPEN_MAX	20	/* max files open at once */

typedef struct _iobuf {
    int cnt;	/* characters left */
    char *ptr;	/* next character position */
    char *base;	/* location of buffer */
    int flag;	/* mode of file access */
    int fd;	/* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags {
    _READ  = 01,		/* file open for reading */
    _WRITE = 02,		/* file open for writing */
    _UNBUF = 04,		/* file is unbuffered */
    _EOF   = 010,		/* EOF has occurred in this file */
    _ERR   = 020		/* error occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE*);

#define feof(p)		(((p)->flag & _EOF) != 0)
#define ferror(p)	(((p)->flag & _ERR) != 0)
#define fileno(p)	((p)->fd)

#define getc(p)		(--(p)->cnt >= 0) \
			? (unsigned char) *(p)->ptr++ : _fillbuff(p))
#define putc(x,p)	(--(p)->cnt >= 0) \
			? *(p)->ptr++ = (x): _flushbuf((x), p))
#endif
