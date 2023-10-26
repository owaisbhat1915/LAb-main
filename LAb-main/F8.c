#include <stdio.h>
#include<stdlib.h>
#include<rpc.h>
#include<string.h>

void print(){
    printf("Implementation of IPC using RPC.");
}
int main(){
    rpc_server_init();
    rpc_register("Print",Print);
    rpc_server_run();
    return 0;
}