#include <sstream>
#include <iostream>
#include <fstream>

int point_inside_circle (float x_circle, float y_circle, float radius, float x_point, float y_point) {
    if  ((x_circle - x_point) * (x_circle - x_point) + (y_circle - y_point) * (y_circle - y_point) < radius * radius) return 1; // внутри окружности
    
    else if ((x_circle - x_point) * (x_circle - x_point) + (y_circle - y_point) * (y_circle - y_point) > radius * radius) return 2; // снаружи окружности
     
    else if ((x_circle - x_point) * (x_circle - x_point) + (y_circle - y_point) * (y_circle - y_point) == radius * radius) return 0; // лежит на окружности

    else return -1;   
}


int main(int argc, char* argv[]){
    std::string s; // строка в которую читаем
    std::ifstream f1(argv[1]);
    std::ifstream f2(argv[2]);  // // открываем файл для чтения
    float x0, y0, r, x1, y1;

    std::getline(f1, s);
    std::istringstream ss(s);
    ss >> x0 >> y0; // достаем координаты центра окружности
    std::getline(f1, s);
    r=std::stof(s); // достаем радиус окружности
    
    while(std::getline(f2, s)){
        std::istringstream ss(s); 
        ss >> x1 >> y1; // достаем координаты точки
        std::cout << point_inside_circle(x0,y0,r,x1,y1) << "\n";
    }

    f1.close(); // закрываем файлы
    f2.close(); 
}