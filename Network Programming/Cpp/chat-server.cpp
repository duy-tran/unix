#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

using namespace std;

int main()
{
    int client, server1, server2;
    int portNum = 5001;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    stringstream msg;
    msg.str("");
    struct sockaddr_in server_addr;
    socklen_t size;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket server has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    /* ---------- BINDING THE SOCKET ---------- */

    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) 
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

    /* ------------- LISTENING CALL ------------- */
    /* ---------------- listen() ---------------- */

    listen(client, 2);

    /* ------------- ACCEPTING CLIENTS  ------------- */

    int clientCount = 1;
    server1 = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server1 < 0) 
        cout << "=> Error on accepting..." << endl;
    while (server1 > 0) 
    {
        strcpy(buffer, "=> Server connected...\n");
        cout << "=> Connected with the client #" << clientCount << endl;
        //cout << "\n=> Enter # to end the connection\n" << endl;
        server2 = accept(client,(struct sockaddr *)&server_addr,&size);
        if (server2 < 0) 
            cout << "=> Error on accepting..." << endl;
        while (server2 > 0) {   
            strcpy(buffer, "client1");
            send(server1, buffer, bufsize, 0);
            cout << "=> Connected with the client #" << ++clientCount << ", client1 go first!" << endl;
            
            cout << "Client1: ";
            do {
                recv(server1, buffer, bufsize, 0);
                cout << buffer << " ";
                msg << buffer << " ";
                if (*buffer == '#') {
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');
            send(server2, msg.str().c_str(), bufsize, 0);
            do {
                cout << "\nClient2: ";
                do {
                    recv(server2, buffer, bufsize, 0);
                    cout << buffer << endl;
                    send(server1, buffer, bufsize, 0);
                    if (*buffer == '#') {
                        *buffer = '*';
                        isExit = true;
                    }
                } while (*buffer != '*');

                cout << "\nClient1: ";
                do {
                    recv(server1, buffer, bufsize, 0);
                    cout << buffer << endl;
                    send(server2, buffer, bufsize, 0);
                    if (*buffer == '#') {
                        *buffer == '*';
                        isExit = true;
                    }
                } while (*buffer != '*');

            } while (!isExit);

            /* ---------------- CLOSE CALL ------------- */

            cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
            close(server1);
            close(server2);
            cout << "\nGoodbye..." << endl;
            isExit = false;
            exit(1);
        }
    }

    close(client);
    return 0;
}
