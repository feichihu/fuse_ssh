#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int
main() {
    int i = 0;
    for(i=0;i<1000;i++){
        int fd0 = open("foo", O_RDWR);
        if (fd0==NULL){
            printf("open foo error");
            exit(1);
        }
        close(fd0);
    }
    struct rusage usg;
    getrusage(RUSAGE_SELF, &usg);
    printf("stime:%ld.%06ld\n", usg.ru_stime.tv_sec, usg.ru_stime.tv_usec);
    printf("utime:%ld.%06ld\n", usg.ru_utime.tv_sec, usg.ru_utime.tv_usec);
   return 0;
}