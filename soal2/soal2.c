#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>

void unzip_deletefolder() {
	pid_t child_id;
	int status;

	child_id=fork();

	if(child_id < 0) {
		exit(EXIT_FAILURE);
	}
	
	if(child_id == 0) {
		char *argv[7] = {"unzip", "/home/tristan/modul2/pets.zip", "-x", "*/*", "-d", "/home/tristan/modul2/petshop", NULL};
                execv("/bin/unzip", argv);
	} else while ((wait(&status)) > 0);
}

int main() {
	//soal a
	unzip_deletefolder();
}
