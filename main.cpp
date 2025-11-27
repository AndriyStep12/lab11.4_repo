#include "lab11_4.h"

int main() {
    string fName = "F.txt";
    string gName = "G.txt";
    char exclude;

    CreateFileF(fName);
    cout << "Original File:" << endl;
    PrintFileContent(fName);

    cout << "Enter character to remove: ";
    cin >> exclude;

    ProcessFiles(fName, gName, exclude);

    cout << "Result File (Reverse order, no '" << exclude << "'):" << endl;
    PrintFileContent(gName);

    return 0;
}