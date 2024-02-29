#include <iostream>
#include "Logger.hpp"

int main() {
    Logger logger;

    try {
        logger.configureLogging();

        std::string compilerPath;
        std::cout << "Enter the path of the compiler (e.g., g++): ";
        std::cin >> compilerPath;

        std::string filePath;
        std::cout << "Enter the path of the file to build: ";
        std::cin >> filePath;

        // Set log file if file output is chosen
        
        std::string buildCommand = compilerPath + " -Wall " + filePath + " -o output.exe 2>&1";
        FILE* pipe = popen(buildCommand.c_str(), "r");
        if (!pipe) {
            throw std::runtime_error("Failed to execute build command");
        }

        char buffer[128];
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != nullptr) {
                if (strstr(buffer, "error") != nullptr) {
                    logger.write(LogLevel::ERROR, buffer);
                } else if (strstr(buffer, "warning") != nullptr) {
                    logger.write(LogLevel::WARNING, buffer);
                } else if (strstr(buffer, "note") != nullptr) {
                    logger.write(LogLevel::INFO, buffer);
                }
            }
        }
        pclose(pipe);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
