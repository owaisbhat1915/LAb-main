#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PIPE_NAME "/tmp/myfifo"
#define BUFFER_SIZE 256

int main()
{
    int fd;
    char buffer[BUFFER_SIZE];

    // create the named pipe if it doesn't exist
    mkfifo(PIPE_NAME, 0666);

    // open the named pipe for writing
    fd = open(PIPE_NAME, O_WRONLY);

    printf("Enter data to write to the named pipe:\n");

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        write(fd, buffer, BUFFER_SIZE);
    }

    // close the named pipe
    close(fd);

    // remove the named pipe
    unlink(PIPE_NAME);

    return 0;
}
