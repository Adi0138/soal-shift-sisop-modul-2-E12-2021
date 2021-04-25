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

char *cut(char *arr){
	int n,i;
	char* cuts;

	for(i=0;arr[i]!='\0';i++);
		n=i-4+1;

	if(n<1) return NULL;

	cuts=(char*)malloc(n*sizeof(char));

	for(i=0;i<n-1;i++)
		cuts[i]=arr[i];
	cuts[i]='\0';
	return cuts;
}

void execute(char command[],char *arg[]){
	int status;
	pid_t child_id;
	child_id=fork();
	if(child_id == 0){
		printf("%s", command);
		execv(command, arg);
	}
	else while ((wait(&status))>0);
}

int main() {
	unzip_deletefolder();
	DIR *path;
	path = opendir("/home/tristan/modul2/petshop");
	struct dirent *ps;
	if(path!=NULL){
		while((ps=readdir(path))!=NULL){
			if (strcmp(ps->d_name,".")==0 || strcmp(ps->d_name,"..")==0) continue;
		        if (fork()==0)  continue;
			char *files=cut(ps->d_name);
	        	char *files1;
		        while (files1=strtok_r(files,"_",&files)){
				int i=0;
	        	        char jenis[20];
				char nama[20];
				char umur[20];
        	        	char *foto=files1;
	      	                char *namafoto;
		                while (namafoto=strtok_r(foto,";",&foto)){
			                if (i==0){
						char files[100]="/home/tristan/modul2/petshop/";
                			        strcat(files,namafoto);
	                	        	char *argv[]={"mkdir","-p",files,NULL};
	        	                	execute("/bin/mkdir",argv);
		                	        strcpy(jenis,namafoto);
			                }
        			        if (i==1){
						strcpy(nama,namafoto);
			                }
        			        if (i==2){
	        		                strcpy(umur,namafoto);
        	        		}
					i++;
	        	    	}
				while ((wait(NULL))>0);
        		        char a[100];
	                	strcpy(a, "/home/tristan/modul2/petshop/");
	        	        strcat(a,ps->d_name);
              		
				char b[100];
        		        strcpy(b, "/home/tristan/modul2/petshop/");
	                	strcat(b,jenis); 
	        	        strcat(b,"/"); 
		                strcat(b,nama); 
        		        strcat(b,".jpg");
	                	char *argv[]={"cp",a,b,NULL};
	        	        execute("/bin/cp",argv);
            
				char c[100];
        		        strcpy(c, "/home/tristan/modul2/petshop/");
	          		strcat(c,jenis);
	        	  	strcat(c,"/keterangan.txt");
          
			        char d[100];
        			strcat(d,"nama : ");
		        	strcat(d,nama);
	       			strcat(d,"\numur: ");
		        	strcat(d,umur);
	        		strcat(d,"tahun\n\n");
          
		        	FILE *x;
	        		x=fopen(c,"a");
			        fputs(d,x);
        			fclose(x);
		        }
			char delete[100] = "/home/tristan/modul2/petshop/";
        		strcat(delete, ps->d_name);
			char *args[3] = {"rm", delete, NULL};
			execv("/bin/rm", args);
		}
		closedir(path);
	}
	return 0;

}
