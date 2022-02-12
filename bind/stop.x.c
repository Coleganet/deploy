#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f stop 
#endif

static  char data [] = 
#define      opts_z	1
#define      opts	((&data[0]))
	"\004"
#define      tst2_z	19
#define      tst2	((&data[4]))
	"\246\366\151\270\131\331\120\273\206\335\022\005\324\004\144\343"
	"\167\017\366\030\345\112\203"
#define      msg1_z	42
#define      msg1	((&data[28]))
	"\206\325\025\220\131\226\135\132\060\272\156\240\350\356\305\304"
	"\176\253\307\063\066\255\055\153\304\272\265\214\263\141\363\363"
	"\162\112\026\074\361\245\150\063\374\142\372\272\036\203\162\300"
	"\040\220\057\335\103"
#define      text_z	33
#define      text	((&data[81]))
	"\310\323\123\260\147\102\135\214\355\037\330\157\226\265\202\266"
	"\354\255\330\261\013\235\224\166\167\373\005\140\212\220\122\025"
	"\152\260\163\156\156\233\131\011\207\034\151"
#define      date_z	1
#define      date	((&data[120]))
	"\007"
#define      rlax_z	1
#define      rlax	((&data[121]))
	"\151"
#define      xecc_z	15
#define      xecc	((&data[124]))
	"\171\075\000\300\305\072\235\171\014\036\332\215\162\124\316\367"
	"\067"
#define      tst1_z	22
#define      tst1	((&data[140]))
	"\025\344\131\131\100\246\260\122\024\020\126\122\344\253\274\250"
	"\215\056\232\042\304\277\247\150\074"
#define      lsto_z	1
#define      lsto	((&data[164]))
	"\150"
#define      shll_z	10
#define      shll	((&data[165]))
	"\037\323\157\077\204\131\362\203\300\227\160"
#define      chk2_z	19
#define      chk2	((&data[176]))
	"\257\132\367\307\114\123\133\071\037\103\321\020\207\324\231\312"
	"\020\023\174\300\266\347"
#define      inlo_z	3
#define      inlo	((&data[198]))
	"\137\025\024"
#define      pswd_z	256
#define      pswd	((&data[239]))
	"\071\372\317\114\164\014\321\255\153\347\026\250\077\124\147\134"
	"\132\371\315\020\047\230\321\336\177\372\302\171\367\132\233\060"
	"\125\152\175\311\167\116\262\155\106\013\375\137\074\071\361\276"
	"\070\141\141\117\320\047\353\352\157\251\265\113\237\272\345\123"
	"\224\133\202\117\210\064\274\316\100\272\056\174\364\040\072\055"
	"\201\234\174\121\304\150\073\064\021\361\177\260\253\145\004\100"
	"\301\206\217\111\273\114\030\373\007\107\170\373\147\263\050\350"
	"\120\245\072\024\015\166\110\037\147\310\320\023\056\324\123\357"
	"\133\343\071\027\060\121\022\067\231\213\063\000\076\133\351\217"
	"\001\044\243\016\232\354\056\002\264\376\026\342\323\152\322\056"
	"\116\013\105\176\135\130\265\366\344\350\367\043\104\341\262\105"
	"\005\125\124\240\101\203\243\366\201\272\331\125\044\253\203\162"
	"\267\311\361\024\042\246\013\006\217\002\051\324\344\334\032\351"
	"\061\156\212\163\361\056\151\163\350\103\310\015\356\114\177\246"
	"\026\161\272\070\027\306\077\247\311\151\173\255\105\225\227\166"
	"\004\041\352\366\117\124\152\070\227\062\105\206\177\305\054\225"
	"\066\347\316\115\255\015\365\166\167\160\043\274\006\273\063\012"
	"\334\035\000\054\162\152\145\011\235\252\220\035\157\275\262\245"
	"\244\201\363\121\217\350\167\342\066\216\213\166\343\362"
#define      chk1_z	22
#define      chk1	((&data[504]))
	"\240\033\113\130\251\362\237\026\171\327\134\367\236\224\302\012"
	"\323\024\202\142\225\326\216\116\023\070\037\361"
#define      msg2_z	19
#define      msg2	((&data[531]))
	"\161\064\164\200\242\012\264\340\330\131\152\035\263\227\250\272"
	"\054\121\206\062\021\017"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	0	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !defined(TRACEABLE)

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !defined(TRACEABLE) */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !defined(TRACEABLE)
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
