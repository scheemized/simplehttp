#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
    std::cout << "Hello World!" << std::endl;
    printf("%s: Hi, this is from printf\n", __FUNCTION__);

    string f = "hisdf";

    return 0;
}
