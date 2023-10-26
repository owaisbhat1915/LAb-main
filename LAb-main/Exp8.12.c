#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MESSAGE_H

#define MESSAGE_SIZE 256

typedef struct {
    long mtype;             // message type
    char mtext[MESSAGE_SIZE];   // message data
} message_t;

#define MESSAGE_TYPE 1

int main()
{
    int msgid;
    message_t message;

    // create a message queue
    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // receive a message
    if (msgrcv(msgid, &message, sizeof(message.mtext), MESSAGE_TYPE, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", message.mtext);

    // remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
