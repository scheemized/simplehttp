#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
//#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
#define PORT 8080
#define MAX_CLIENTS 20
int main(int argc, char const *argv[]) {
    std::cout << "Hello World!" << std::endl;
    printf("%s: Hi, this is from printf\n", __FUNCTION__);

    // Attempt to create socket object...
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) 
    {
        printf("%s: ERROR!! Failed to create socket object!\n", __FUNCTION__);
        return 0;
    }
    else 
    {
        printf("%s: SUCCESS!! Created socket object! socket val: <%d>\nContinuing...\n", __FUNCTION__, sock_fd);
    }

    // make sockaddr_in struct
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);

    if (bind(sock_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        printf("%s: Failed to bind!\n", __FUNCTION__);
        return -1;
    } else {
        printf("%s: SUCCESS!! bind operation was successful\n", __FUNCTION__);

    }
    
    if ( int err = listen(sock_fd, MAX_CLIENTS) < 0 )
    {
        printf("%s: ERROR!! listen operation FAILED! err code: <%d>\n", __FUNCTION__, err);
        return -1;
    } else {
        printf("%s: SUCCESS!! server is now listening! Max Clients: <%d>\n", __FUNCTION__, MAX_CLIENTS);
    }

    while(true)
    {
        printf("\n !!!! **** ... Waiting for new connection ... **** !!!!\n\n"); 
        sleep(1);
    }


    close(sock_fd);
    return 0;
}
