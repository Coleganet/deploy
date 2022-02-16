#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f stop.sh 
#endif

static  char data [] = 
#define      msg2_z	19
#define      msg2	((&data[1]))
	"\340\131\257\005\202\006\036\311\324\357\306\361\265\376\266\177"
	"\247\047\044\266"
#define      xecc_z	15
#define      xecc	((&data[21]))
	"\256\147\303\265\157\130\213\164\271\216\144\004\121\022\202\026"
#define      tst1_z	22
#define      tst1	((&data[38]))
	"\166\324\265\242\223\164\062\220\276\212\121\310\301\210\254\146"
	"\357\252\222\375\317\076\166\242\023\342\211"
#define      shll_z	10
#define      shll	((&data[64]))
	"\223\246\362\173\042\210\171\325\044\265\347\036"
#define      lsto_z	1
#define      lsto	((&data[75]))
	"\200"
#define      chk1_z	22
#define      chk1	((&data[80]))
	"\030\166\014\067\120\205\325\012\253\032\202\026\223\220\027\073"
	"\341\215\303\036\121\376\221\002\377\227"
#define      msg1_z	42
#define      msg1	((&data[106]))
	"\371\302\316\016\207\302\071\017\224\041\302\225\263\316\144\141"
	"\120\323\121\175\344\043\115\067\003\222\063\216\066\144\317\014"
	"\116\230\051\125\213\104\256\231\330\004\244\037\014\152\160\112"
	"\211\370"
#define      opts_z	1
#define      opts	((&data[152]))
	"\361"
#define      rlax_z	1
#define      rlax	((&data[153]))
	"\267"
#define      pswd_z	256
#define      pswd	((&data[171]))
	"\052\236\251\352\040\135\016\070\323\033\160\354\201\315\346\104"
	"\234\174\054\225\340\215\062\213\373\054\231\051\121\141\120\200"
	"\073\232\177\147\373\026\106\235\360\310\257\164\117\250\207\175"
	"\045\264\023\005\101\105\221\074\162\053\146\303\214\266\103\307"
	"\121\302\056\114\331\164\352\312\075\231\076\214\102\305\012\147"
	"\172\035\155\273\143\377\367\326\052\135\232\266\024\336\175\145"
	"\240\254\262\172\040\234\104\136\066\203\353\171\111\365\341\303"
	"\023\117\176\167\116\166\115\170\323\347\056\347\305\254\115\146"
	"\130\377\341\171\234\046\327\323\251\302\115\363\270\056\266\313"
	"\175\065\102\313\253\220\104\177\167\162\147\075\037\264\243\167"
	"\264\205\361\121\253\310\045\125\213\162\110\103\240\377\017\035"
	"\064\122\351\340\342\055\137\131\240\306\227\300\173\073\070\060"
	"\300\051\201\153\362\246\300\176\031\010\302\271\010\321\327\074"
	"\043\301\035\005\356\175\137\217\104\366\117\277\061\207\360\361"
	"\261\161\135\243\030\035\042\061\046\344\353\057\265\302\154\330"
	"\203\211\336\162\006\076\002\112\064\121\012\146\331\372\130\213"
	"\154\265\057\205\323\121\266\372\065\241\051\352\144\225\303\347"
	"\037\364\264\347\176\255\247\334\271\113\303\007\127\011\350\201"
	"\247\222\154\310\357\173\000\303\226\160\260\027\076\226\134\333"
	"\212\021\302\011\276\152\345\167\265\250\176\015\262\147\217\131"
	"\371\373\041\351\166\042\254\014\223\135"
#define      date_z	1
#define      date	((&data[484]))
	"\022"
#define      text_z	33
#define      text	((&data[491]))
	"\222\156\207\120\330\154\340\031\206\007\107\237\103\366\302\236"
	"\365\027\307\047\043\206\314\276\011\011\365\203\355\122\372\316"
	"\003\102\104\327\113\107\355\310\216\025\107"
#define      tst2_z	19
#define      tst2	((&data[531]))
	"\053\042\250\214\014\103\357\165\136\111\026\102\366\253\333\054"
	"\132\277\075\151\147\070\046\104\221"
#define      chk2_z	19
#define      chk2	((&data[555]))
	"\251\372\131\130\327\073\240\162\133\246\302\136\207\051\125\367"
	"\116\065\304\021\331\233"
#define      inlo_z	3
#define      inlo	((&data[575]))
	"\362\065\214"/* End of data[] */;
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
