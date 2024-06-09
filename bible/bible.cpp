#include <iostream>
#include <Windows.h>

typedef bool(*searchFunction)(const char*, const char*);//создание типа указателя на функцию, которая принимает два указателя на строки типа `char` и возвращает значение типа `bool`

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // подключение русского языка

    HINSTANCE hinstLib; //объявление переменной, которая будет хранить дескриптор загруженной  dill библиотеки.
    searchFunction search; //объявление переменной типа указатель на функцию, которая будет хранить адрес экспортированной функции "search"
    char str[100];
    char chars[50];

    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);

    std::cout << "Введите символы для поиска: ";
    std::cin.getline(chars, 50);

    hinstLib = LoadLibrary(TEXT("search.dll")); //загрузка библиотеки "search.dll" и получение ее дескриптора в переменную hinstLib.
    if (hinstLib != NULL) {
        search = (searchFunction)GetProcAddress(hinstLib, "search"); // получение адреса экспортированной из DLL-библиотеки функции "search" и сохранение его в переменную "search"
        if (search != NULL) {
            bool result = search(str, chars);
            std::cout << "Содержит ли строка " << '"' << str << '"' << " символы " << '"' << chars << '"' << "?" << std::endl;
            if (result > 0)
            {
                std::cout << "Да!"<< std::endl;
            }
            else if (result == 0)
            {
                std::cout << "Нет! " << std::endl;
            }

        }
        FreeLibrary(hinstLib); //выгрузка загруженной DLL библиотеки из памяти.
    }

    return 0;
}
