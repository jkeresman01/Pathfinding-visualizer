#pragma once

#include <iostream>
#include <string>

#define LOG(severity, message)                                                 \
    std::cerr << severity "file: " << __FILE__ << ", line: " << __LINE__       \
              << ", msg: " << message << "\n";

#define LOG_DEBUG(message) LOG("[DEBUG]: ", message)
#define LOG_INFO(message) LOG("[INFO]:  ", message)
#define LOG_WARN(message) LOG("[WARN]:  ", message)
#define LOG_ERROR(message) LOG("[ERROR]: ", message)
