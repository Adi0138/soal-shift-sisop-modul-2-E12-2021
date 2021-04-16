#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <limits.h>

void killProcess(char arg0[],char arg1[], char pwd[]){
    FILE *file;
    char file_path[PATH_MAX];
    size_t n=2;
    size_t len = strlen(arg0);
    if (n > len)
        return;
    memmove(arg0, arg0+n, len-n+1);

    strcpy(file_path,pwd);
    strcat(file_path,"/kill.sh");
    file=fopen(file_path,"w");
    fprintf(file,"#!/bin/bash\n");
    if(strcmp(arg1,"-z")==0){
        fprintf(file,"pkill -f %s\n",arg0);
    }
    else if(strcmp(arg1,"-x")==0){
        fprintf(file, "kill %d\n", getpid());
    }
    fprintf(file,"rm -- $0");
    fclose(file);
}

int main(int argc, char* argv[]) {
    pid_t pid, sid,pid1,pid3,pid2,pid4;
    char cwd[PATH_MAX],timeEpoch[PATH_MAX],nameF[PATH_MAX],zip_name[PATH_MAX],times[PATH_MAX],link[PATH_MAX],buffer [PATH_MAX], dest[PATH_MAX];
    pid_t child_id;
    int status;
    time_t rawtime,epoch;
    struct tm *timeinfo,*loctime;
    getcwd(cwd,sizeof(cwd));
    pid = fork();

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {  
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    killProcess(argv[0],argv[1],cwd);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    while (1) {
        strcpy(dest, cwd);
        strcat(dest,"/");
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime(buffer,PATH_MAX,"%Y-%m-%d_%T",timeinfo);
        strcat(dest,buffer);
        pid1=fork();
        if(pid1==0){
            pid2=fork();
            if(pid2==0){
                printf("2");
                char *argv[] = {"mkdir","-p", dest, NULL};
                execv("/bin/mkdir", argv);
            }
            else{
                while((wait(&status))>0);
                int i=1;
                while(i<=10){
                    pid3=fork();
                    if(pid3==0){
                        time(&epoch);
                        loctime=localtime(&epoch);
                        strftime(timeEpoch,PATH_MAX,"/%Y-%m-%d_%T",loctime);
                        strcpy(nameF,dest);
                        strcat(nameF,timeEpoch);
                        epoch=(epoch%1000)+50;
                        sprintf(times,"%ld",epoch);
                        strcpy(link,"https://picsum.photos/");
                        strcat(link,times);
                        char *path[] = {"wget","-o",nameF,link,NULL};
                        execv("/usr/bin/wget",path);
                    }
                    sleep(5);
                    i++;
                }
                pid4=fork();
                if(pid4==0){
                    chdir(cwd);
                    strcpy(zip_name,dest);
                    strcat(zip_name,".zip");
                    char *zipFile[]={"zip","-mrq",zip_name,buffer,NULL};
                    execv("/usr/bin/zip",zipFile);
                }
                exit(0);
                
            }
        }
        else if(pid1>0){
            sleep(40);
        }
    }
}