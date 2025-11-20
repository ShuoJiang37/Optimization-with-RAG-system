#include <stdio.h>          // printf(), fprintf(), scanf()
#include <stdlib.h>         // exit(), free(), strtol()
#include <stdbool.h>
#include <errno.h>          // errno
#ifdef linux
 #include <error.h>         // error()
#endif

#define MAX_N 2000000
#define MAX_V 10001

const char NUL = '\0';
int lineno;
char* linebuff = NULL;
size_t linebuffsize = 0;

int a[MAX_N];
int c[MAX_V] = { 0 };

void
cleanup(int ecode)
{
	if (linebuff)
	{
		free(linebuff);
		linebuff = NULL;
		linebuffsize = 0;
	}

	exit(ecode);
}

bool
readline()
{
	errno = 0;
	if(getline(&linebuff, &linebuffsize, stdin) == -1) // read line
	{
		if(errno == 0)  // EOF?
			return false;

#ifdef linux
		error(0, errno, "Can't read line");
#else
		fprintf(stderr, "Can't read line\n");
#endif
		cleanup(1);
	}

	return true;
}

void
skip_sp(const char** p)
{
	while (**p == ' ')
		(*p)++;
}

int
main(int argc, char** argv)
{
	char* nextp = NULL;
	int t;
	int n;
	int i, j;

	readline();
	lineno = 1;
	const char* s = linebuff;
	n = strtol(s, &nextp, 10);
	s = nextp;

	readline();
	s = linebuff;
	lineno++;

	int max = 0;
	for (i = 0; i < n; ++i)
	{
		skip_sp(&s);
		if (*s == NUL)
			cleanup(0);

		if (*s == '\n')
		{
			if (!readline())
				cleanup(0);

			lineno++;
			s = linebuff;
		}

		t = strtol(s, &nextp, 10);
		s = nextp;

		a[i] = t;
		c[t]++;
		if (t > max)
			max = t;
	}

	const char* sep = "";
	for (i = 0; i <= max; ++i)
	{
		for (j = 0; j < c[i]; ++j)
		{
			printf("%s%d", sep, i);
			sep = " ";
		}
	}

	printf("\n");
	cleanup(0);
	return 0;
}