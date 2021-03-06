#include "unp.h"

int main(int argc, char** argv)
{
    if (argc != 2) {
        err_quit("usage: ./unix_bind <pathname>");
    }

    int sockfd = Socket(AF_LOCAL, SOCK_STREAM, 0);

    unlink(argv[1]);

    struct sockaddr_un addr1;
    bzero(&addr1, sizeof(addr1));
    addr1.sun_family = AF_LOCAL;
    strncpy(addr1.sun_path, argv[1], sizeof(addr1.sun_path)-1);

    Bind(sockfd, (SA *) &addr1, SUN_LEN(&addr1));

    //unlink(argv[1]);

    struct sockaddr_un addr2;
    socklen_t len = sizeof(addr2);
    Getsockname(sockfd, (SA *) &addr2, &len);
    printf("bound name = %s, returned len = %d\n", addr2.sun_path, len);

    exit(0);
}
