#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
<<<<<<< HEAD
=======
#include <chrono>
using namespace std;
>>>>>>> 699bb89f4afee8e0d956818aca0da68d13c00f4c

enum class LogLevel {
    INFO = 0,
    ERROR,
    WARNING,
    CRITICAL
};

enum class OutputChannel {
    CONSOLE,
    FILE
};

class Logger {
public:
<<<<<<< HEAD
    Logger();
    ~Logger();
    
    void setOutputChannel(FILE* output);
    void setLogFile(const std::string& logFileName);
    void write(LogLevel level, const char* format, ...);
    void configureLogging();
    OutputChannel getChannelType() const;

private:
    OutputChannel channelType;
    std::ostream* outputChannel;
    LogLevel userLogLevel;
=======
            Logger();
            ~Logger();
            
            void setOutputChannel(FILE* output);
            void setLogFile(const std::string& logFileName);
            void write(LogLevel level, const char* format, ...);
            void configureLogging();
            OutputChannel getChannelType() const;
            int getLogInterval() const;

        private:
            OutputChannel channelType;
            std::ostream* outputChannel;
            LogLevel userLogLevel;
            std::chrono::seconds logIntervalSeconds;

>>>>>>> 699bb89f4afee8e0d956818aca0da68d13c00f4c
};

#endif // LOGGER_HPP
