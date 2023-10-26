#include "prog.h" 
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>

int main() {
    CLIENT *cl;
    int *result;

    // Create a client handle for the server at localhost:8000
    cl = clnt_create("localhost", PROG, PROG_VERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror("Error");
        exit(1);
    }

    // Call the remote procedure on the server
    result = add_1(&arg, cl);
    if (result == NULL) {
        clnt_perror(cl, "Error");
        exit(1);
    }

    // Print the result
    printf("Result: %d\n", *result);

    // Free the client handle
    clnt_destroy(cl);

    return 0;
}
