#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>

void handleClient(std::istream& is, std::ostream& os) {
    std::string message;
    std::getline(is, message);
    std::reverse(message.begin(), message.end());
    os << message << std::endl;
}

int main() {
    const int PORT = 12345;

    std::cout << "Servidor esperando conexiones en el puerto " << PORT << std::endl;

    while (true) {
        std::cout << "Esperando cliente..." << std::endl;

        std::vector<std::thread> threads;

        while (threads.size() < 5) {
            std::thread([&]() {
                std::string response;
                std::cout << "Cliente conectado. Escribe un mensaje: ";
                std::getline(std::cin, response);
                std::cout << "Respuesta del servidor: " << response << std::endl;
            }).detach();
        }

        for (auto& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    return 0;
}
