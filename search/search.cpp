#include <iostream>
__declspec(dllexport) //объявление функции 'search' как экспортируемой из компилируемой DLL-библиотеки.
bool search(const char* str, const char* chars)//объявление функции 'search', которая принимает два аргумента, указателей на строки типов 'const char*'.
{
    const char* p = chars; //объявление указателя p, который указывает на начало второй переданной строки chars
    while (*p != '\0') //проверка, содержит ли первая переданная строка str текущий символ, на который указывает p
        //(являющийся символом из второй строки chars).Если символ не найден,то возвращает false 
    {
        if (strchr(str, *p) == NULL) {
            return false;
        }
        p++;
    }
    return true;
}