#include <iostream>
#include <WS2tcpip.h>
#include<string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    string ipAddress = "127.0.0.1";
    int port = 54000;

    WSAData data;
    WORD ver = MAKEWORD(2, 2);

    int wsResult = WSAStartup(ver, &data);

    if (wsResult != 0) {
        cerr << "Cannot start winsock" << wsResult << endl;
        return 1;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        cerr << "Cannot create socket " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));

    if (connResult == SOCKET_ERROR) {
        cerr << "Cannot connect to server" << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    char buf[4096];
    int num1, num2;

    do {
        cout << "Enter 1.number: ";
        cin >> num1;
        cout << "Enter 2.number: ";
        cin >> num2;

        if (send(sock, to_string(num1).c_str(), sizeof(num1), 0) == SOCKET_ERROR ||
            send(sock, to_string(num2).c_str(), sizeof(num2), 0) == SOCKET_ERROR) {
            cerr << "Error sending data" << endl;
            break;
        }

        ZeroMemory(buf, 4096);
        int byteReceived = recv(sock, buf, 4096, 0);

        if (byteReceived > 0) {
            cout << "Server> " << buf << endl;
        }

    } while (num1 != 0 && num2 != 0);

    closesocket(sock);
    WSACleanup();
    return 0;
}
