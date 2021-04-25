# Laporan Praktikum Modul 2 Sistem Operasi

Kelompok E12 :
<li>05111840000138 - Gema Adi Perwira
<li>05111940000006 - Daffa Tristan Firdaus
<li>05111940000211 - VICKY THIRDIAN

***Soal 1***
<br>Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 
<br>Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.
<br>Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. 
<br>(a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg 
<br>(b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :).
<br>(c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta 
<br>(d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).
<br>(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany).
<br>(f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
<br>Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

<br>Pada pengerjaan soal ini diperintahkan untuk membuat folder yang isinya merupakan hasil extract dari mendownload banyak file didalam folder yang dizipkan dan juga program 
tersebut diperintahkan bekerja pada 2 sesi yaitu saat 9 April 16:22:00 dan 6 jam setelahnya yaitu 22.00. Yang mana cara kerja sesi tersebut yaitu zip yang sudah didownload yang didalamnya terdapatfolder yang berisikan file tersebut itu diextract lalu dipindahkan ke folderyang namanya sudah diubah. Setelah itu folder-folder hasil extract zip tersebut dizip kembali serta mendelete seluruh folder tadi.
<br>Untuk mengetahui waktunya kita dugunakan code tersebut yang ada pada library ``` time.h ```
```
time_t now = time(NULL);
struct tm *t = localtime(&now);
```
<br>Lalu dibagi 2 sesi yaitu 6 jam sebelum ulang tahun dan pada saat ulang tahun. Maka dari itu digunakanlah if dengan kondisi
<br>Ini 6 jam sebelum ulang tahun
```
birthmonth == t->tm_mon && birthday == t->tm_mday && birthdayHour-6 == t->tm_hour && birthdayMinute == t->tm_min && birthdaySecond == t->tm_sec
```
<br>Ini saat ulang tahun
```
birthmonth == t->tm_mon && birthday == t->tm_mday && birthdayHour == t->tm_hour && birthdayMinute == t->tm_min && birthdaySecond == t->tm_sec
```

***Soal 2***
<br>Loba bekerja di petshop, suatu saat dia menerima file zip yang berisi foto hewan-hewan pelanggan dan dia disuruh untuk mengategorikan foto-foto tesebut. Karena dia merasa kesusahan untuk mengerjakannya secara manual, dia memutuskan untuk meminta bantuanmu untuk membantu pekerjaannya.
<br>(a) Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
<br>(b) Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.
<br>(c) Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan. Contoh: “/petshop/cat/joni.jpg”.  
<br>(d) Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.
<br>(e) Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.
```
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun


```
<br>Note:
<li>Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan underscore(_).
<li>Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().
<li>Menggunakan fork dan exec.
**Jawaban**:
    
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
```c
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

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
```
merupakan bagian dari daemon process.
```c
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
```
berguna untuk mendapatkan waktu lokal dan mengubah dalam bentuk YYYY-mm-dd_HH:mm:ss, lalu dibuat folder di direktori dimana file dijalankan dan nama filenya berdasarkan waktu yang telah dirubah bentuknya.
```c
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
```
berguna untuk menunggu setelah folder sebelumnya dibuat. Lalu variabel ```epoch``` akan berisi waktu berdasarkan Epoch Univ yang akan digunakan untuk menentukan ukuran piksel dengan rumus ```epoch=(epoch%1000)+50;```. Cara agar terdownload file dengan ukuran piksel seperti diatas adalah "https://picsum.photos/". ```epoc``` Nama filenya akan dibuat berdasarkan waktu lokal yang akan dirubah bentuknya menjadi YYYY-mm-dd_HH:mm:ss. File akan didownload sebanyak 20 kali, dan setiap mendownload akan dijeda selama 5 detik.
```c
pid4=fork();
if(pid4==0){
    chdir(cwd);
    strcpy(zip_name,dest);
    strcat(zip_name,".zip");
    char *zipFile[]={"zip","-mrq",zip_name,buffer,NULL};
    execv("/usr/bin/zip",zipFile);
}
exit(0);
```
berguna untuk menzip folder yang filenya telah didownload sebanyak 20 kali dan filenya ikut dipindahkan ke dalam zip tersebut. Lalu perintah ```exit(0);``` berguna agar keluar dari process agar pembuatan folder tidak sekaligus dibuat ketika mendownload suatu file, sehingga mengakibatkan file akan dibuat dengan interval 5 detik.
```c
else if(pid1>0){
    sleep(40);
}
```
berguna untuk membuat folder baru setelah 40 detik.

