#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <cstdlib>
#include <unordered_map>
#include <typeinfo>
#include <string.h>
using namespace std;

//int main(){
//    string data_name[14] = {"fuhuijin.txt", }
//    int line = 0;
//    char ch;
//    while((ch = cin.get()) != 'Q'){
//        if(ch == '\n')
//            line++;
//    }
//    cout << line << endl;
//    return 0;
//}
vector<string> readfiledir(){
    struct dirent *ptr;
    DIR *dir;
    string PATH="/home/gz/下载/calculateParty/data3";
    dir = opendir(PATH.c_str());
    vector<string> files;
    cout << "文件列表：" << endl;
    while((ptr=readdir(dir)) != NULL){
        if(ptr->d_name[0] == '.')
            continue;
//        cout << ptr->d_name << endl;
        files.push_back(ptr->d_name);
    }
    return files;
}

int main(){
    ifstream infile;
    ofstream outfile;
    vector<string> files;
    files = readfiledir();
    unordered_map<string, int> people;
    int count = 0;
    for(int i = 0; i < files.size(); i++){
        cout << files[i] << endl;
//        cout << typeid(files[i]).name() << endl;
        infile.open("data3/"+ files[i]);
        if(!infile.is_open()){
            cout << "Can't open file. Bye.\n";
            exit(EXIT_FAILURE);
        }
        string *line = new string[15];
//        getline(infile, line[j]);
        int j = 0;
        while(getline(infile, line[j], ' ')){
//            char str[10];
//            str[10]  = line[j];
            string str = line[j];
//            cout << line[j] << " : "<< line[j].size() << endl;
            if (str[str.size() - 1] == '\n'){
//                str[strlen(str) - 1] = '\0';
	        line[j] = str.substr(0, str.size()-1);
            }    
            cout << line[j] << " : "<< line[j].size() << endl;
            if (people.find(line[j]) == people.end()) 
                people[line[j]] = 1;
            else
                people[line[j]]++;
            j++;
            count++;
        }
        if (infile.eof())
            cout << "End of file reached.\n";
        else if (infile.fail())
            cout << "Input terminated by data mismatch.\n";
        else
            cout << "Input terminated for unknown reason.\n";
        infile.close();
        cout << "file: " << i << " heiheiheiheiheihei"<< endl;
    }
    outfile.open("order.txt");
    
    for(unordered_map<string, int>::iterator iter = people.begin(); iter != people.end(); iter++){
        cout << iter->first << " : " << iter->second << endl;
//        outfile << iter->second << " : " << iter->first << endl;
        outfile << iter->first << " : " << iter->second << endl;
    }
    outfile.close();
    cout << "总投票数" << count << endl;
//    if (infile.eof())
//        cout << "End of file reached.\n";
//    else if (infile.fail())
//        cout << "Input terminated by data mismatch.\n";
//    else
//        cout << "Input terminated for unknown reason.\n";
    return 0;
}
