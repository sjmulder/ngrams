#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define NMAX 8

int
main(int argc, char **argv)
{
	int i;
	long n;
	char s[NMAX+1];

	if (argc != 2) {
		fputs("usage: ngrams <n>\n", stderr);
		return 1;
	}

	n = strtol(argv[1], NULL, 10);
	if (n<1 || n>8) {
		fputs("bad n, must be 1-8\n", stderr);
		return 1;
	}

	s[n] = '\0';
	for (i=0; i<n-1; i++)
		s[i] = (char)getchar();
	
	while ((i = getchar()) != EOF) {
		s[n-1] = (char)i;
		puts(s);
		memmove(s, s+1, n-1);
	}

	return 0;
}
