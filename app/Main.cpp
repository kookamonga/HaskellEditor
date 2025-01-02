#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void editorLoop(string content);
string readLines();

int main() {
    cout << "Welcome to the Simple C++ Text Editor!" << endl;
    cout << "Commands: [edit], [save <filename>], [quit]" << endl;
    editorLoop("");
    return 0;
}

void editorLoop(std::string content) {
    cout << "> ";
    string command;
    getline(cin, command);

    istringstream iss(command);
    string cmd;
    iss >> cmd;

    if (cmd == "edit") {
        cout << "Enter your text (type ':done' on a new line to finish):" << endl;
        string newContent = readLines();
        editorLoop(content + newContent);
    } else if (cmd == "save") {
        string filename;
        iss >> filename;
        ofstream outFile(filename);
        outFile << content;
        outFile.close();
        cout << "File saved as: " << filename << endl;
        editorLoop(content);
    } else if (cmd == "quit") {
        cout << "Exiting editor. Goodbye!" << endl;
    } else {
        cout << "Unknown command. Available commands: [edit], [save <filename>], [quit]" << endl;
        editorLoop(content);
    }
}

string readLines() {
    string line, allLines;
    while (true) {
        getline(cin, line);
        if (line == ":done") {
            break;
        }
        allLines += line + "\n";
    }
    return allLines;
}
