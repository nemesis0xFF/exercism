#include <string>

namespace log_line {
std::string message(std::string line) {
    int msg_start = line.find(':');
    return line.substr(msg_start + 2);
}

std::string log_level(std::string line) {
    // return the log level$
    int level_start = line.find('[');
    int level_end = line.find(']');
    std::string level = line.substr(level_start + 1, level_end - level_start - 1);
    for (char &c : level) {
        c = toupper(c);
    }
    
    return level;
}

std::string reformat(std::string line) {
    // return the reformatted message
    std::string msg = message(line);
    std::string level = log_level(line);
    std::string reformatted = msg + " (" + level + ")";
    return reformatted;
}
}  // namespace log_line
