// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(void)
// {
//     pid_t pid;
//     pid = fork();

//     if (pid > 0) 
//     {
//         exit(0);
//     }
//     else
//     {
//         while(1) 
//         {
//             /* 子程式在系統背景跑無限迴圈 */
//             printf("pass");
//         }
//     }
// }

/*
 * daemonize.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 20 seconds and terminates afterwards.
 */

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <signal.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <syslog.h>

// static void skeleton_daemon()
// {
//     pid_t pid;

//     /* Fork off the parent process */
//     pid = fork();

//     /* An error occurred */
//     if (pid < 0)
//         exit(EXIT_FAILURE);

//     /* Success: Let the parent terminate */
//     if (pid > 0)
//         exit(EXIT_SUCCESS);

//     /* On success: The child process becomes session leader */
//     if (setsid() < 0)
//         exit(EXIT_FAILURE);

//     /* Catch, ignore and handle signals */
//     //TODO: Implement a working signal handler */
//     signal(SIGCHLD, SIG_IGN);
//     signal(SIGHUP, SIG_IGN);

//     /* Fork off for the second time*/
//     pid = fork();

//     /* An error occurred */
//     if (pid < 0)
//         exit(EXIT_FAILURE);

//     /* Success: Let the parent terminate */
//     if (pid > 0)
//         exit(EXIT_SUCCESS);

//     /* Set new file permissions */
//     umask(0);

//     /* Change the working directory to the root directory */
//     /* or another appropriated directory */
//     chdir("/");

//     /* Close all open file descriptors */
//     int x;
//     for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
//     {
//         close (x);
//     }

//     /* Open the log file */
//     openlog ("firstdaemon", LOG_PID, LOG_DAEMON);
// }

// int main()
// {
//     skeleton_daemon();

//     while (1)
//     {
//         //TODO: Insert daemon code here.
//         syslog (LOG_NOTICE, "First daemon started.");
//         sleep (20);
//         break;
//     }

//     syslog (LOG_NOTICE, "First daemon terminated.");
//     closelog();

//     return EXIT_SUCCESS;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char* argv[])
{
    FILE *fp= NULL;
    pid_t process_id = 0;
    pid_t sid = 0;
    // Create child process
    process_id = fork();
    // Indication of fork() failure
    if (process_id < 0)
    {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }
    // PARENT PROCESS. Need to kill it.
    if (process_id > 0)
    {
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }
    //unmask the file mode
    umask(0);
    //set new session
    sid = setsid();
    if(sid < 0)
    {
        // Return failure
        exit(1);
    }
    // Change the current working directory to root.
    chdir("/");
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // Open a log file in write mode.
    fp = fopen ("log.txt", "w+");
    while (1)
    {
        //Dont block context switches, let the process sleep for some time
        sleep(1);
        fprintf(fp, "Logging info...\n");
        fflush(fp);
    // Implement and call some function that does core work for this daemon.
    }
    fclose(fp);
    return (0);
}