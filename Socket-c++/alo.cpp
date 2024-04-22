#include <iostream>
#include <cstring>
#include <winsock2.h>

int main() {
    // Inicializar Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error al inicializar Winsock" << std::endl;
        return 1;
    }

    // Crear un socket del cliente
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Configurar la información de la dirección del servidor
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);  // Puerto 8080
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // IP del servidor

    // Conectar al servidor
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Recibir datos del servidor
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);

    // Mostrar los datos recibidos
    std::cout << "Mensaje del servidor: " << buffer << std::endl;

    // Cerrar el socket del cliente
    closesocket(clientSocket);

    // Limpiar la inicialización de Winsock
    WSACleanup();

    return 0;
}
