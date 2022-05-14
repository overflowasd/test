#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::string s; // строка в которую читаем
    std::ifstream f1(argv[1]);
    std::ifstream f2(argv[2]); 
    std::string s1="\"id\"";
    std::string s2="\"value\"";

    std::ofstream out;
    out.open("./report.json");
    while(std::getline(f1, s)){
        if (s.find(s1) == std::string::npos) {
            out << s << std::endl;
        } else continue;
    }
     
    std::cout << "End of program" << std::endl;
    
   /* while(std::getline(f2, s)){
        if (s.find(s1) != std::string::npos) {
            
}
    }*/
}