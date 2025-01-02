#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void editorLoop(std::string content);
std::string readLines();

int main() {
    std::cout << "Welcome to the Simple C++ Text Editor!" << std::endl;
    std::cout << "Commands: [edit], [save <filename>], [quit]" << std::endl;
    editorLoop("");
    return 0;
}

void editorLoop(std::string content) {
    std::cout << "> ";
    std::string command;
    std::getline(std::cin, command);

    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "edit") {
        std::cout << "Enter your text (type ':done' on a new line to finish):" << std::endl;
        std::string newContent = readLines();
        editorLoop(content + newContent);
    } else if (cmd == "save") {
        std::string filename;
        iss >> filename;
        std::ofstream outFile(filename);
        outFile << content;
        outFile.close();
        std::cout << "File saved as: " << filename << std::endl;
        editorLoop(content);
    } else if (cmd == "quit") {
        std::cout << "Exiting editor. Goodbye!" << std::endl;
    } else {
        std::cout << "Unknown command. Available commands: [edit], [save <filename>], [quit]" << std::endl;
        editorLoop(content);
    }
}

std::string readLines() {
    std::string line, allLines;
    while (true) {
        std::getline(std::cin, line);
        if (line == ":done") {
            break;
        }
        allLines += line + "\n";
    }
    return allLines;
}
