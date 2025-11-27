#include "lab11_4.h"

void CreateFileF(const string& fname) {
    ofstream fout(fname);
    if (!fout) return;
    fout << "Line one: super.\n";
    fout << "Line two: banana.\n";
    fout << "Line three: cherry.\n";
    fout << "Line four: date.\n";
    fout.close();
}

int CountLines(const string& fname) {
    ifstream fin(fname);
    if (!fin) return 0;

    string dummy;
    int count = 0;
    while (getline(fin, dummy)) {
        count++;
    }
    fin.close();
    return count;
}

void ProcessFiles(const string& fName, const string& gName, char excludeChar) {
    ofstream fout(gName);
    if (!fout) {
        cerr << "Error creating output file!" << endl;
        return;
    }

    int totalLines = CountLines(fName);

    for (int targetLine = totalLines; targetLine >= 1; targetLine--) {

        ifstream fin(fName);
        string line;

        for (int current = 1; current <= targetLine; current++) {
            getline(fin, line);
        }

        string processedLine = "";
        for (char c : line) {
            if (c != excludeChar) {
                processedLine += c;
            }
        }

        fout << processedLine << endl;

        fin.close();
    }

    fout.close();
    cout << "Processing complete." << endl;
}

void PrintFileContent(const string& fname) {
    ifstream fin(fname);
    string line;
    cout << "--- " << fname << " ---" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    cout << "------------------" << endl;
    fin.close();
}