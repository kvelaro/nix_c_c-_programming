#include <iostream>
//#include <sys/socket.h>
#include <netdb.h>
using namespace std;

void printFamily(struct addrinfo *aip) {
    cout << "Family: ";
    switch(aip->ai_family) {
        case AF_INET:
            cout << "INET";
            break;
        case AF_INET6:
            cout << "INET6";
        break;
        case AF_UNIX:
            cout << "UNIX";
        break;
        case AF_UNSPEC:
        default:
            cout << "UNSPECIFIED";
        break;
    }
    cout << endl;
}

void printProtocol(struct addrinfo *aip) {
    cout << "Protocol: ";
    switch(aip->ai_protocol) {
        case IPPROTO_TCP:
            cout << "TCP";
            break;
        case IPPROTO_UDP:
            cout << "UDP";
            break;
        case IPPROTO_RAW:
            cout << "RAW";
            break;
        default:
            break;
    }
    cout << endl;
}

void printType(struct addrinfo *aip) {
    cout << "Type: ";
    switch(aip->ai_socktype) {
        case SOCK_STREAM:
            cout << "STREAM";
            break;
        case SOCK_DGRAM:
            cout << "DGRAM";
            break;
        case SOCK_RAW:
            cout << "RAW";
            break;
        default:
            cout << "UNKNOWN";
            break;        
    }
    cout << endl;
}

int main(int argc, char **argv) {
    
    struct addrinfo *aiplist, *aip;
    struct addrinfo hint;
    
    if(argc != 3) {
        cout << "Program usage: <program name> <host> <service>" << endl;
        return -1;
    }
    
    hint.ai_flags = AI_CANONNAME;
    hint.ai_family = 0;
    hint.ai_socktype = 0;
    hint.ai_protocol = 0;
    hint.ai_addrlen = 0;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = 0;
    
    if(getaddrinfo(argv[1], argv[2], &hint, &aiplist) < 0) {
        cout << "Failed to get info" << endl;
        return -1;
    }
    
    for(aip = aiplist; aip != NULL; aip = aip->ai_next) {
        printFamily(aip);
        printProtocol(aip);
        printType(aip);        
    }
    
    return 0;
}


    
