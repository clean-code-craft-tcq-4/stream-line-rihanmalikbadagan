#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bmsSender.h"

main()
{
    // Creating child process
    int p = fork();
    if (p > 0)
    {
        senderProcess();
    } else{
        receiverProcess();
    }

}