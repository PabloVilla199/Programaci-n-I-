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

    // Crear un socket del servidor
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Configurar la información de la dirección del servidor
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);  // Puerto 8080
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Vincular el socket a la dirección y puerto
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Escuchar conexiones entrantes
    listen(serverSocket, 5);

    std::cout << "Esperando conexiones..." << std::endl;

    // Aceptar la conexión entrante
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    std::cout << "Cliente conectado." << std::endl;

    // Enviar datos al cliente
    const char* message = "¡Hola, cliente!";
    send(clientSocket, message, strlen(message), 0);

    // Cerrar los sockets
    closesocket(clientSocket);
    closesocket(serverSocket);

    // Limpiar la inicialización de Winsock
    WSACleanup();

    return 0;
}
