#include "unp.h"

void dg_clnt(FILE* fp, int sockfd, const SA* pservaddr, socklen_t serv_len)
{
    int n;
    char sendline[MAXLINE];
    char recvline[MAXLINE+1];
    while (Fgets(sendline, MAXLINE, fp) != NULL) {
        Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, serv_len);
        n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        recvline[n] = '\0';
        Fputs(recvline, stdout);
    }
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        err_quit("usage: ./udpclnt01 <ip> <port>");
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    int sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    dg_clnt(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

    exit(0);
}
