/**
  * @brief Simply Append Zero Bytes to any files
  *
  * @author downtownguy
  * @date 2016-11-07
  *
  */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static void append_line2file(string filepath, string line) {
    std::ofstream file;
    file.open(filepath, std::ios::out | std::ios::app);
    if (file.fail()) {
        throw std::ios_base::failure(std::strerror(errno));
    }
    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);
    file << line << std::endl;
}

void help(char *argv[]) {
    cout<<"Usage: "<<argv[0]<<" file"<<endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        help(argv);
        return 0;
    }
    char bytes[4];
    memset(bytes, '0', sizeof(char) * 4);
    string apps(bytes);
    append_line2file(argv[1], apps);
    cout<<"Append To File Done"<<endl;
    return 0;
}
