#include "unp.h"

int main(int argc, char** argv)
{
    char* ptr = NULL;
    char** pptr = NULL;
    struct hostent* hptr = NULL;
    char str[INET_ADDRSTRLEN];

    while (--argc > 0) {
        ptr = *++argv;
        if ((hptr = gethostbyname(ptr)) == NULL) {
            err_msg("gethostbyname for host: %s: %s", ptr, hstrerror(h_errno));
            continue;
        }

        printf("official hostname: %s\n", hptr->h_name);

        for (pptr = hptr->h_aliases; *pptr != NULL; ++pptr) {
            printf("\nalias: %s\n", *pptr);
        }

        switch (hptr->h_addrtype) {
            case AF_INET:
                pptr = hptr->h_addr_list;
                for ( ; *pptr != NULL; ++pptr) {
                    printf("\naddress: %s\n",
                            Inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                }
                break;
            default:
                err_ret("unknown address type");
                break;
        }
    }
    exit(0);
}
