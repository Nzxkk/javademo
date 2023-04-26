#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

#include<stdio.h>
#include<string.h>

#define BUF_SIZE 30

int main(int argc, char* argv[])
{
	char buf[BUF_SIZE];
	int len=0;
	int fd=-1;
	
	
   if(argc != 2){
      printf("wrong parameters\n");
      return -1;
   }

   fd = open(argv[1], O_RDWR);
   
   if(fd == -1){
      printf("error in open file");
	  printf("the error is: %s\n", strerror(errno));
      	  return -1;
   }else{
	   //printf("open file success\n");
	   while((len=read(fd, buf, BUF_SIZE))!=0){
		   write(stdout, buf, len);
	   }
   }
   if(fd>0){
	   close(fd);
   }
   return 0;
}
