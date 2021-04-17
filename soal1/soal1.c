#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main() {
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

  if ((chdir("/home/atenggen/sisop21/modul2/soal1")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
    pid_t c1, c2, c3;
  c1 = fork();
  c2 = fork();
  c3 = fork();

  if(c1 == 0)
  {
    pid_t pid1, pid2;
    pid1 = fork();
    pid2 = fork();

    if(pid1 == 0)
    {
        if(pid2 == 0)
        {
            char *mkdir1[4] = {"mkdir", "Musyik", "/home/atenggen/sisop21/modul2/", NULL};
            execv("/bin/mkdir", mkdir1);
        }
    //  
    //  {
    //      char *downloadmusik[6] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_For_Stefany.zip", NULL};
    //      execv("/bin/wget", downloadmusik);
    //  }
    }
  }
  if(c2 == 0)
  {
    pid_t pid1, pid2;
        pid1 = fork();
        pid2 = fork();
        if(pid1 == 0)
        {
            if(pid2 == 0)
            {
                char *mkdir2[4] = {"mkdir", "Fylm", "/home/atenggen/sisop21/modul2/", NULL};
                execv("/bin/mkdir", mkdir2);
            }
        }

  }
  if(c3 == 0)
  {
    pid_t pid1, pid2;
        pid1 = fork();
        pid2 = fork();
        if(pid1 == 0)
        {
            if(pid2 == 0)
            {
              char *mkdir3[4] = {"mkdir", "Pyoto", "/home/atenggen/sisop21/modul2/", NULL};
              execv("/bin/mkdir", mkdir3);
            }
        }
  }
  sleep(1);
 }
}
