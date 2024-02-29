#include "Logger.hpp"

Logger::Logger() : channelType(OutputChannel::CONSOLE), outputChannel(&std::cout), userLogLevel(LogLevel::INFO) {}

Logger::~Logger() {
    if (outputChannel && channelType == OutputChannel::FILE) {
        std::ofstream* fileStream = dynamic_cast<std::ofstream*>(outputChannel);
        if (fileStream) {
            fileStream->close();
            delete fileStream;
        }
    }
}

void Logger::setOutputChannel(FILE* output) {
    if (output == stdout) {
        outputChannel = &std::cout;
        channelType = OutputChannel::CONSOLE;
    } else if (output == stderr) {
        outputChannel = &std::cerr;
        channelType = OutputChannel::CONSOLE;
    } else {
        throw std::invalid_argument("Invalid output channel specified.");
    }
}

void Logger::setLogFile(const std::string& logFileName) {
    std::ofstream* fileStream = new std::ofstream(logFileName);
    if (!fileStream->is_open()) {
        throw std::runtime_error("Failed to open log file: " + logFileName);
    }
    outputChannel = fileStream;
    channelType = OutputChannel::FILE;
}

void Logger::write(LogLevel level, const char* format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    // Determine if the message should be displayed based on the user log level
    bool displayMessage = false;
    switch (userLogLevel) {
        case LogLevel::INFO:
            displayMessage = (level == LogLevel::INFO);
            break;
        case LogLevel::WARNING:
            displayMessage = (level == LogLevel::INFO || level == LogLevel::WARNING);
            break;
        case LogLevel::ERROR:
            displayMessage = (level == LogLevel::INFO || level == LogLevel::WARNING || level == LogLevel::ERROR);
            break;
        case LogLevel::CRITICAL:
            displayMessage = true;
            break;
    }

    if (displayMessage) {
        if (channelType == OutputChannel::CONSOLE) {
            switch (level) {
                case LogLevel::INFO:
                    std::cout << "[INFO] " << buffer << std::endl;
                    break;
                case LogLevel::WARNING:
                    std::cerr << "[WARNING] " << buffer << std::endl;
                    break;
                case LogLevel::ERROR:
                    std::cerr << "[ERROR] " << buffer << std::endl;
                    break;
                case LogLevel::CRITICAL:
                    std::cerr << "[CRITICAL] " << buffer << std::endl;
                    break;
            }
        } else if (channelType == OutputChannel::FILE) {
            switch (level) {
                case LogLevel::INFO:
                    *outputChannel << "[INFO] " << buffer << std::endl;
                    break;
                case LogLevel::WARNING:
                    *outputChannel << "[WARNING] " << buffer << std::endl;
                    break;
                case LogLevel::ERROR:
                    *outputChannel << "[ERROR] " << buffer << std::endl;
                    break;
                case LogLevel::CRITICAL:
                    *outputChannel << "[CRITICAL] " << buffer << std::endl;
                    break;
            }
        }
    }
}

void Logger::configureLogging() {
    std::string outputOption;
    std::string logFileName;
    std::string logLevelStr;

    std::cout << "Choose output option (console/file): ";
    std::cin >> outputOption;

    if (outputOption == "file") {
        std::cout << "Enter log file name: ";
        std::cin >> logFileName;
        setLogFile(logFileName);
    } else if (outputOption != "console") {
        throw std::invalid_argument("Invalid output option specified. Please choose 'console' or 'file'.");
    }

    std::cout << "Choose log level (info/error/warning/critical): ";
    std::cin >> logLevelStr;

    if (logLevelStr == "info")
        userLogLevel = LogLevel::INFO;
    else if (logLevelStr == "error")
        userLogLevel = LogLevel::ERROR;
    else if (logLevelStr == "warning")
        userLogLevel = LogLevel::WARNING;
    else if (logLevelStr == "critical")
        userLogLevel = LogLevel::CRITICAL;
    else
        throw std::invalid_argument("Invalid log level specified.");
}

OutputChannel Logger::getChannelType() const {
    return channelType;
}
