#include <iostream>
#include <WS2tcpip.h>
#include<string>
#include"addition.h"
#include"substraction.h"
#include"multiplication.h"
#include"division.h"

int a, b;
#pragma comment(lib, "ws2_32.lib")

using namespace std;

char buf1[4096];
char buf2[4096];

int main() {
    WSAData wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0) {
        cerr << "Cannot start winsock" << endl;
        return 1;
    }

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET) {
        cerr << "Cannot create a socket" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    listen(listening, SOMAXCONN);
    sockaddr_in client;
    int clientsize = sizeof(client);

    SOCKET clientsocket = accept(listening, (sockaddr*)&client, &clientsize);
    char host[NI_MAXHOST];
    char service[NI_MAXHOST];

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXHOST);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " connected on port " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    closesocket(listening);

    while (true) {
        ZeroMemory(buf1, 4096);
        ZeroMemory(buf2, 4096);

        int byteRecieved1 = recv(clientsocket, buf1, 4096, 0);
        int byteRecieved2 = recv(clientsocket, buf2, 4096, 0);

        if (byteRecieved1 == SOCKET_ERROR || byteRecieved2 == SOCKET_ERROR) {
            cerr << "Error receiving data" << endl;
            break;
        }

        if (byteRecieved1 == 0 || byteRecieved2 == 0) {
            cout << "Client disconnected" << endl;
            break;
        }

        int num1 = stoi(buf1);
        int num2 = stoi(buf2);
        char choise;

        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choise;

        int result;
        addition add0;
        substraction sub0;
        multiplication multi0;
        division div0;
        switch (choise) {
        case '1':
            result = add0.add(num1,num2);
            break;
        case '2':
           result = sub0.sub(num1,num2);
            break;
        case '3':
             result = multi0.multi(num1,num2);
            break;
        case '4':
             result = div0.div(num1,num2);
            break;
        case '5':
            closesocket(clientsocket);
            WSACleanup();
            return 0;
        default:
            cerr << "Invalid input" << endl;
            send(clientsocket, "Invalid input!", 16, 0);
            continue;
        }

        send(clientsocket, to_string(result).c_str(), sizeof(result), 0);
    }

    closesocket(clientsocket);
    WSACleanup();
    return 0;
}
