#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

/* Наименьшее количество ходов будет при приведении всех элементов к серединному значению
если массив имеет нечетное число элементов, или к любому значению между двумя серединными
элементами, если массив имеет четное число элементов */

int main(int argc, char* argv[]){
    std::ifstream f1(argv[1]); // открываем файл для чтения
    std::vector<int> nums; // массив nums
    std::string s; // строка в которую читаем
    int count = 0; // количество ходов
    int median; // серединное значение
    
    while(std::getline(f1, s)){
        nums.push_back(std::stoi(s));   // заполняем массив
    }

    sort(nums.begin(),nums.end());   // сортируем
    median=nums[nums.size()/2];      // медиана, или элемент справа от нее (если четное количество элементов)
    

    for (int i = 0; i < nums.size(); i++) {
        count+=abs(median-nums[i]);    
    }

    std::cout << count << std::endl;
    f1.close();

}