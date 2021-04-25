#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>



void move(char *fName, char *stevFolder)
{
    int status;
    struct dirent *dp;
    DIR *dir = opendir(fName);
    if(dir != NULL){
        while((dp = readdir(dir))){
            pid_t child = fork();
            if (child == 0 && (strcmp(dp->d_name, ".") == 0 && strcmp(dp->d_name, "..") == 0))
            {
                exit(EXIT_SUCCESS);
            }
            if (child == 0)
            {
                char pathName[10];
                strcpy(pathName, fName);
                strcat(pathName, "/");
                strcat(pathName, dp->d_name);
                char *_move[] = {"mv", pathName, stevFolder, NULL};
                execv("/bin/mv", _move);
            }
            while(wait(&status)>0);
        }
        (void) closedir(dir);
    }
}

int main() {
    int status;
    int daemonStatus;
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/atenggen/sisop21/modul2")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  int birthday = 9;
int birthmonth = 3;
int birthdayHour = 22;
int birthdayMinute = 22;
int birthdaySecond = 0;

  while (1) {
    // Tulis program kalian di sini
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

// 6jam sebelum
    if (birthmonth == t->tm_mon && birthday == t->tm_mday && birthdayHour-6 == t->tm_hour && 
    birthdayMinute == t->tm_min && birthdaySecond == t->tm_sec)
    {
        pid_t c1, c2, c3, c4;
        c1 = fork();
        c2 = fork();
        c3 = fork();
        c4 = fork();
        if(c1 == 0){
            pid_t pid1, pid2;
            pid1 = fork();
            pid2 = fork();
            if(pid1 == 0){
                if(pid2 == 0){
                    char *makedir1[] = {"mkdir", "Musyik", NULL};
                    execv("/bin/mkdir", makedir1);
                }else{
                    while((wait(&status))>0);
                    move("MUSIK", "Musyik");
                    char *removemusik[] = {"rm", "-r", "MUSIK", NULL};
                    execvp("rm", removemusik);
                }
            }else{
                if(pid2 == 0){
                    char *downloadmusik[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_stevany.zip", "-q", NULL};
                    execv("/bin/wget", downloadmusik);
                }else{
                    while((wait(&status))>0);
                    char *unzipmusik[] = {"unzip", "-qq", "Musik_for_stevany.zip", NULL};
                    execv("/bin/unzip", unzipmusik);
                }
            }
        }
        else if(c2 == 0){
            pid_t pid1, pid2;
            pid1 = fork();
            pid2 = fork();
            if(pid1 == 0){
                if(pid2 == 0){
                    char *makedir2[] = {"mkdir", "Fylm", NULL};
                    execv("/bin/mkdir", makedir2);
                }else{
                    while((wait(&status))>0);
                    move("FILM", "Fylm");
                    char *removefilm[] = {"rm", "-r", "FILM", NULL};
                    execvp("rm", removefilm);
                }
            }else{
                if(pid2 == 0){
                    char *downloadfilm[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_stevany.zip", "-q", NULL};
                    execv("/bin/wget", downloadfilm);
                }else{
                    while((wait(&status))>0);
                    char *unzipfilm[] = {"unzip", "-qq", "Film_for_stevany.zip", NULL};
                    execv("/bin/unzip", unzipfilm);
                }
            }
        }
        else if(c3 == 0){
            pid_t pid1, pid2;
            pid1 = fork();
            pid2 = fork();
            if(pid1 == 0){
                if(pid2 == 0){
                    char *makedir3[] = {"mkdir", "Pyoto", NULL};
                    execv("/bin/mkdir", makedir3);
                }else{
                    while((wait(&status))>0);
                    move("FOTO", "Pyoto");
                    char *removefoto[] = {"rm", "-r", "FOTO", NULL};
                    execvp("rm", removefoto);
                }
            }else{
                if(pid2 == 0){
                    char *downloadfoto[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_stevany.zip", "-q", NULL};
                    execv("/bin/wget", downloadfoto);
                }else{
                    while((wait(&status))>0);
                    char *unzipfoto[] = {"unzip", "-qq", "Foto_for_stevany.zip", NULL};
                    execv("/bin/unzip", unzipfoto);
                }
            }
        }
    }
    // saat ultah
    else if(birthmonth == t->tm_mon && birthday == t->tm_mday && birthdayHour == t->tm_hour && 
    birthdayMinute == t->tm_min && birthdaySecond == t->tm_sec)
    {
        pid_t cid;
        cid = fork();
        if (cid == 0)
        {
            char *zip[] = {"zip", "-vmqr", "Lopyu_Stevany.zip", "Musyik", "Fylm","Pyoto", NULL};
            execv("/bin/zip", zip);
        }
        while((wait(&status))>0);
    }
    while((wait(&daemonStatus))>0)
    sleep(1);
  }
}
