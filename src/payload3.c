#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int
main() {
    int i = 0;
    int fd0 = open("foo", O_RDWR);
    if (fd0==NULL){
        printf("open foo error");
        exit(1);
    }
    char *buf = malloc(1000000*sizeof(char));
    memset(buf, '-', 1000000);
    int nb0 = write(fd0, buf, 1000000);
    free(buf);
    for(int i=0;i<1000000;i++){
        int nb1 = pread(fd0, buf, 1, rand()%1000000);
    }
    close(fd0);
    struct rusage usg;
    getrusage(RUSAGE_SELF, &usg);
    printf("stime:%ld.%06ld\n", usg.ru_stime.tv_sec, usg.ru_stime.tv_usec);
    printf("utime:%ld.%06ld\n", usg.ru_utime.tv_sec, usg.ru_utime.tv_usec);
   return 0;
}