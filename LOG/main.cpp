#include <iostream>
<<<<<<< HEAD
=======
#include <chrono>
#include <thread>
>>>>>>> 699bb89f4afee8e0d956818aca0da68d13c00f4c
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

<<<<<<< HEAD
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
=======
        long long logIntervalSeconds;
        std::cout << "Enter the log interval in seconds: ";
        std::cin >> logIntervalSeconds;

        std::string buildCommand = compilerPath + " -Wall " + filePath + " -o output.exe 2>&1";
        auto lastLogTime = std::chrono::steady_clock::now();
        while (true) {
            auto currentTime = std::chrono::steady_clock::now();
            if (currentTime - lastLogTime >= std::chrono::seconds(logIntervalSeconds)) {
                // Perform the build process
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

                // Update the last log time
                lastLogTime = currentTime;
            }
        }
>>>>>>> 699bb89f4afee8e0d956818aca0da68d13c00f4c
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
