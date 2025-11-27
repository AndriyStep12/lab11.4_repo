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

    // 1. Дізнаємось, скільки всього рядків у файлі
    int totalLines = CountLines(fName);

    // 2. Головний цикл: йдемо від останнього номера рядка до 1-го
    for (int targetLine = totalLines; targetLine >= 1; targetLine--) {

        ifstream fin(fName); // Відкриваємо файл заново для кожного рядка
        string line;

        // Пропускаємо всі рядки до потрібного (targetLine)
        // Наприклад, якщо треба 4-й рядок, пропускаємо 1, 2, 3
        for (int current = 1; current <= targetLine; current++) {
            getline(fin, line);
        }

        // Тепер у змінній 'line' знаходиться потрібний рядок

        // 3. Обробляємо рядок (видаляємо символ)
        string processedLine = "";
        for (char c : line) {
            if (c != excludeChar) {
                processedLine += c;
            }
        }

        // 4. Записуємо у файл G
        fout << processedLine << endl;

        fin.close(); // Закриваємо, щоб у наступній ітерації відкрити знову
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