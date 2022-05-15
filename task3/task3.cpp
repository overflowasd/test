#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void recursion(json& ja, json jb){
        for (auto &ia : ja){
            for (auto &ib : jb){
                if (ia["id"]==ib["id"]) {
                    ia["value"]=ib["value"];
                }
            }     
            if (ia.contains("values") ) {
                recursion(ia["values"], jb);
            }
            
            
        } 
   }

int main(int argc, char* argv[]){
    
    std::ifstream f1(argv[1]);
    std::ifstream f2(argv[2]); 

    json j1 = json::parse(f1);
    json j2 = json::parse(f2);
    
   // j2["values"].merge_patch(j1["tests"]);

    recursion(j1["tests"],j2["values"]);

    std::ofstream f3("report.json");
    f3 << std::setw(1) << j1 << std::endl;
    
        
}