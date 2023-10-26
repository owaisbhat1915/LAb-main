#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define message structure
struct message {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate a unique key for the message queue
    key = ftok("msgq", 'a');

    // Create the message queue with read and write permissions for user
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Send a message to the queue
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, world!");
    msgsnd(msgid, &msg, sizeof(msg), 0);

    // Receive a message from the queue
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Received message: %s\n", msg.mtext);

    // Delete the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
