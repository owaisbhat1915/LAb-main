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

    // open the named pipe for reading
    fd = open(PIPE_NAME, O_RDONLY);

    while (read(fd, buffer, BUFFER_SIZE) > 0) {
        printf("Data read from named pipe: %s", buffer);
    }

    // close the named pipe
    close(fd);

    return 0;
}
