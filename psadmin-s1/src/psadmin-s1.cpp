//============================================================================
// Name        : psadmin-s1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/* Spawn a child process running a new program. PROGRAM is the name
 of the program to run; the path will be searched for this program.
 ARG_LIST is a NULL-terminated list of character strings to be
 passed as the program's argument list. Returns the process ID of
 the spawned process. */
int spawn(char* program, char** arg_list) {
	pid_t child_pid;
	/* Duplicate this process. */
	child_pid = fork();
	if (child_pid != 0)
		/* This is the parent process. */
		return child_pid;
	else {
//	    char *argv[] = { "/bin/sh", "-c", "env", 0 };
//	    char *envp[] =
//	    {
//		"USER=psadm2",
//		"HOME=/home/psadm2"
//		"LOGNAME=psadm2",
//		"_JAVA_OPTIONS=-Djava.security.egd=file:/dev/./urandom",
//		"PS_HOME=/opt/oracle/psft/pt/ps_home8.56.08",
//		"PS_CFG_HOME=/home/psadm2/psft/pt/8.56",
//		"PS_APP_HOME=/opt/oracle/psft/pt/fscm_app_home",
//		"PS_JRE=/opt/oracle/psft/pt/ps_home8.56.08/jre",
//		"PS_LIBPATH=/opt/oracle/psft/pt/ps_home8.56.08/bin",
//		"PS_SERVER_CFG=/opt/oracle/psft/pt/ps_home8.56.08/setup/psdmtx.cfg",
//		"PS_DM_LOG=/home/psadm2/PS_DM/log",
//		"PS_DM_DATA_IN=/opt/oracle/psft/pt/ps_home8.56.08/data",
//		"PS_DM_DATA_OUT=/home/psadm2/PS_DM/data",
//		"DM_HOME=/home/psadm2/PS_DM",
//		"PS_SERVER_CFG=/opt/oracle/psft/pt/ps_home8.56.08/setup/psdmtx.cfg",
//		"PS_DM_SCRIPT=/opt/oracle/psft/pt/ps_home8.56.08/scripts",
//		"PS_HOSTTYPE=oel-6-x86_64",
//		"PS_SERVDIR=/home/psadm2/PS_CACHE",
//		"SQR_HOME=/opt/oracle/psft/pt/ps_home8.56.08/bin/sqr/ORA",
//		"LD_LIBRARY_PATH=/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64/native_threads:/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64/server:/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64:/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0/bin:/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0/lib:/opt/oracle/psft/db/oracle-server/12.1.0.2/lib::/opt/oracle/psft/pt/ps_home8.56.08/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin/interfacedrivers:/opt/oracle/psft/pt/ps_home8.56.08/bin/sqr/ORA/bin:/opt/oracle/psft/pt/ps_home8.56.08/optbin:/opt/oracle/psft/pt/ps_home8.56.08/verity/linux/_ilnx21/bin:/opt/oracle/psft/db/oracle-server/12.1.0.2/lib",
//		"PSJLIBPATH=/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64/native_threads:/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64/server:/opt/oracle/psft/pt/ps_home8.56.08/jre/lib/amd64",
//		"COBPATH=/opt/oracle/psft/pt/ps_home8.56.08/cblbin",
//		"TNS_ADMIN=/opt/oracle/psft/db",
//		"PATH=/home/psadm2/anaconda3/bin:/opt/oracle/psft/pt/ps_home8.56.08/jre/bin:/opt/oracle/psft/pt/ps_home8.56.08/python:/opt/oracle/psft/pt/ps_home8.56.08/appserv:/opt/oracle/psft/pt/ps_home8.56.08/setup:/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0/bin:.:/opt/oracle/psft/db/oracle-server/12.1.0.2/bin:/opt/oracle/psft/db/oracle-server/12.1.0.2/OPatch:/opt/oracle/psft/db/oracle-server/12.1.0.2/perl/bin:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/opt/puppetlabs/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin/sqr/ORA/bin:/opt/oracle/psft/pt/ps_home8.56.08/verity/linux/_ilnx21/bin:/home/psadm2/bin",
//		"TUXDIR=/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0",
//		"ORACLE_HOME=/opt/oracle/psft/db/oracle-server/12.1.0.2",
//        0
//	    };
//	    execve(argv[0], &argv[0], envp);
//	    fprintf(stderr, "Oops!\n");
		/* Now execute PROGRAM, searching for it in the path. */
		execvp(program, arg_list);
		/* The execvp function returns only if an error occurs. */
		fprintf (stderr, "an error occurred in execvp\n");
		abort();
	}
}
int main() {
	/* The argument list to pass to the "ls" command. */
	char* arg_list[] = {
		"psadmin", /* argv[0], the name of the program. */
		"-c",
		"sstatus",
		"-d",
		"APPDOM",
		"/",
		NULL /* The argument list must end with a NULL. */
	};

/* Spawn a child process running the "ls" command. Ignore the
 returned child process ID. */
	spawn ("psadmin", arg_list);
	printf ("done with main program\n");
	return 0;
}
