/*
 * COPYRIGHT NOTICE
 * Copyright (c) 2015
 * All rights reserved
 * 
 * @author       : colin.dj
 * @mail         : daijun163mail@163.com
 * @path         : /home/dj/my/workspace/my_prj/wsnrouter-stress/test
 * @file         : stress_test.c
 * @date         : 2015-04-25 16:19
 * @algorithm    : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>   //for gethostbyname
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF 4096
#define SERVER_PORT 6666

int 
do_connected(char *addr)
{
    int sockfd;
    struct hostent *host;
    struct sockaddr_in servaddr;
    
    if (addr = NULL) {
        perror("use: ./stress_test [upstream]\n");
        exit(-1);
    }

    host = gethostbyname(addr);
    if (host == NULL) {
        perror("failed to get upstream by name\n");
        exit(-1);
    }

    //create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perrorr("failed to estabish a socket\n");
        exit(1);
    }

    /* init sockfd */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(servaddr.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in)) == -1) {
        perror("failed to connect to upstream\n");
        exit(1);
    }
    printf("Successful to connect the upstream\n");

    return sockfd;
}

int 
main(int argc, char *argv[])
{
    
}
