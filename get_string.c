#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int get_string(char *,int);

int main(int argc, char const *argv[])
{
    char string[1024];
    int numRead;
    numRead = get_string(string,1024);   
    write(STDOUT_FILENO,string,numRead);
    return 0;
}

int get_string(char *buffer,int size){

    int numRead  = read(STDIN_FILENO,buffer,size);
    if(numRead == -1){
        perror("Error reading ");
    }
    buffer[numRead] = '\0';
    return numRead;

    

}
