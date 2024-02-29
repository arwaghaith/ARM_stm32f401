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
};

#endif // LOGGER_HPP
