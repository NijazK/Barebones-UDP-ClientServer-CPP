#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using nampespace std;

void main() 
{
    // startup winsock
    WSADATA data;
    WORD version = MAKEWORD(2, 2);
    if wsOK = WSAStartup(version, &data);
    if (wsOK != 0)
    {
        cout << "Can't start winsock " << wsOK;
    }
    // Bind socket to ip address
    SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in serverHint;
    serverHint.sin_ddr.S_un.S_addr = ADDR_ANY;
    serverHint.sin_family = AF_INET;
    serverHint.sin_port = htons(54000);

    if (bind(in, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR);
    {
        cout << "Can't find socket" << WSAGetLastError() << endl;
        return;
    }

    sockaddr_in client;
    int clientLength = sizeof(client);
    ZeroMemory(&client, sizeof(clientLength));
    
    char buf[1024];
    ZeroMemory(buf, 1024);

    // Enter a loop
    while (true)
    {
        ZeroMemory(buf, 1024);
        // Wait for message
        int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);
        if (bytesIn == SOCKET_ERROR)
        {
            count << "Error recieving client" << WSAGetLastError() << endl;
            continue;
        }
        // Display message
        char clientIp[256];
        ZeroMemory(clientIp, 256);

        Inet_ntop(AF_INET, client.sin_addr, clientIp, 256);

        cout << "Message Recieved from " << clientIp << " : " << buf << endl;
    }
    
    // Close socket
    closesocket(in);

    // Shutdown winsock
    WSACleanup();
}