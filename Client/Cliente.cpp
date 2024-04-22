#include <iostream>
#include <string>

int main() {
    const char* SERVER_IP = "localhost";
    const int PORT = 12345;

    std::string message;
    std::cout << "Conectando al servidor. Escribe un mensaje: ";
    std::getline(std::cin, message);

    std::cout << "Mensaje enviado al servidor: " << message << std::endl;

    return 0;
}
