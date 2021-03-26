#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);
    return 0;
}
