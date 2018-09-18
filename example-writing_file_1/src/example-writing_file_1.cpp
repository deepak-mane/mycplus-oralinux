//============================================================================
// Name        : example-writing_file_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <spawn.h>

using namespace std;

int main(int argc, char* argv[], char *env[])
{
    int ret;
    pid_t child_pid;
    posix_spawn_file_actions_t child_fd_actions;
    if (ret = posix_spawn_file_actions_init (&child_fd_actions))
        perror ("posix_spawn_file_actions_init"), exit(ret);
    if (ret = posix_spawn_file_actions_addopen (&child_fd_actions, 1, "./mylog.txt",
            O_WRONLY | O_CREAT | O_APPEND, 0644))
        perror ("posix_spawn_file_actions_addopen"), exit(ret);
    if (ret = posix_spawn_file_actions_adddup2 (&child_fd_actions, 1, 2))
        perror ("posix_spawn_file_actions_adddup2"), exit(ret);

    if (ret = posix_spawnp (&child_pid, "date", &child_fd_actions, NULL, argv, env))
        perror ("posix_spawn"), exit(ret);
}
