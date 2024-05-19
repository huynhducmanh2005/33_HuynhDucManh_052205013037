#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void printgach(const string& filename) {
    ifstream file(filename);
    int lineCount = 0;
    string line;
    vector<string> gach;

    while (getline(file, line)) {
        lineCount++;
        if (!line.empty() && line[0] == '-') {
            gach.push_back(line);
        }
    }
    file.close();
    cout << "So dong:" << lineCount << endl;
    cout << "Cac dong bat dau bang\"-\":\n";
    for (const auto& line : gach) {
        cout << line << endl;
    }
}

int main() {
    cout << "The zoo" << endl;
    string filename = "data.txt";
    printgach(filename);

    return 0;
}