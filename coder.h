#pragma once
#include <string>
#include <fstream>
#include <QTimer>
#include <QEventLoop>

void Delay(int n);

void MakeBinFromFile(std::string input_file, std::string output_file_path, int64_t mask);

void CheckFileSize(const std::string& name);
