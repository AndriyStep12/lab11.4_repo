#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateFileF(const string& fname);
void ProcessFiles(const string& fName, const string& gName, char excludeChar);
void PrintFileContent(const string& fname);
int CountLines(const string& fname);