# Laporan Praktikum Modul 2 Sistem Operasi

Kelompok E12 :
<li>05111840000138 - Gema Adi Perwira
<li>05111940000006 - Daffa Tristan Firdaus
<li>05111940000211 - VICKY THIRDIAN
  
***Soal 3***
<br>Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.
<br>(a). Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].
<br>(b). Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.
<br>(c). Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.
<br>(d). Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.
<br>(e). Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dsdengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).
<br>Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!
<br>Note:
<li>Tidak boleh menggunakan system() dan mkdir()
<li>Program utama merupakan SEBUAH PROGRAM C
<li>Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat

**Jawaban**:
---
```c
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
```
```c
killProcess(argv[0],argv[1],cwd);
```
berguna untuk memanggil fungsi killProcess yang berisi:
```c
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
    if(strcmp(arg1,"-a")==0){
        fprintf(file,"pkill -f %s\n",arg0);
    }
    else if(strcmp(arg1,"-b")==0){
        fprintf(file, "kill %d\n", getpid());
    }
    fprintf(file,"rm -- $0");
    fclose(file);
}
```
pada fungsi ```killProcess```, potongan kode:
```c
size_t n=2;
size_t len = strlen(arg0);
if (n > len)
    return;
memmove(arg0, arg0+n, len-n+1);
```
berguna untuk menghapus dua karakter pertama dari variabel ```arg0```(awalnya berisi ./nama_output) sehingga "./" akan dihapus dari variabel ```arg0```. Lalu :
```c
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
```
berguna untuk membuat file kill.sh yang akan ditulis perintah ```fprintf(file,"pkill -f %s\n",arg0);``` jika variabel ```arg1``` adalah "-z", yang jika dijalankan akan langsung mematikan seluruh pid yang berjalan berdasarkan nama_output yang berada di variabel ```arg0```. Perintah ```fprintf(file, "kill %d\n", getpid());``` akan ditulis pada file kill.sh jika variabel ```arg1``` adalah "-x", yang jika dijalankan akan langsung menunggu sampe process id selesai yaitu jika telah mendownload 20 file dan melakukan zip. ```fprintf(file,"rm -- $0");``` akan menghapus file itu sendiri jika sudah dijalankan.
