#include "coder.h"

void MakeBinFromFile(std::string input_file, std::string output_file_path, int64_t mask){
    CheckFileSize(input_file);
    std::string str;
    std::ifstream file(input_file, std::ios_base::binary);
    std::ofstream outfile(output_file_path, std::ios_base::binary);
    int64_t res;
    if(file.is_open()){
        while(file.read((char*) &res, sizeof(int64_t))){
            if(file.gcount() == sizeof(int64_t)){
                res ^= mask;
                outfile.write((char*) &res, sizeof(res));
            }
        }
        file.close();
        outfile.close();
    } else {
        return;
    }

}

void Delay(int n){
    QEventLoop loop;
    QTimer::singleShot(n, &loop, SLOT(quit()));
    loop.exec();
}

void CheckFileSize(const std::string& name){
    std::fstream file(name, std::ios_base::binary |  std::ios_base::in | std::ios_base::app);
    if(!file.is_open()){
        std::cout<<"file not open"<<std::endl;
        return;
    }
    std::streampos begin, end;
    begin =  file.tellg();
    file.seekg(0, std::ios_base::end);
    end = file.tellg();
    size_t j = (end - begin)%8;

    if(j % 8 != 0){
        char * ch = new char[8-j];
        for(size_t i = 0; i< (8-j) ; i++){
            ch[i] = 0;
        }
        file.seekg(0, std::ios_base::end);
        file.write(ch, 8-j);
        end = file.tellg();
        delete [] ch;
    }
     file.close();

}
