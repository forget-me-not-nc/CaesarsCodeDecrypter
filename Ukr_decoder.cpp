#include "Decoder.h"
#include "Ukr_decoder.h"
#include <string>       //для строк
#include <map>          //для пам
#include <algorithm>    //для переведеня строки в нижній регістр

using std::string;
using std::iterator;
using std::map;

Ukr_decoder::Ukr_decoder() : temp_key(0), min_diff(100000)  //встановлюємо початковий мін. ключ та мін. частоту
{

}

Ukr_decoder::~Ukr_decoder()     
{
    
}

void Ukr_decoder::Decode(string& Code)
{
    int* Code_to_ascii = new int[Code.size()];  //масив з чисел, коди яких відповідають тексту
    int* Result = new int[Code.size()];         //масив для записую результуючого тексту

    std::transform(Code.begin(), Code.end(), Code.begin(), tolower);    //перевід в жиній регістр

    for (unsigned int iter = 0; iter < Code.size(); iter++)
    {
        Code_to_ascii[iter] = (int)Code[iter];  //заповненя двох масивів
        Result[iter] = (int)Code[iter];
    }

    Ukr_letter_counter(Code_to_ascii, Code.size()); //визов функції підрахунку букв у тексті

    for (int alphabet = 0; alphabet < 33; alphabet++)   //цикл для проходження по всім зсувам
    {
        Key_shift(Code_to_ascii, Code.size());  //визов функції зсуву тексту на 1
    }

    Ukr_cipher_decryption(Result, Code.size(), Res_key, Code);  //функція декодуваня тексту вже на відомий ключ

    delete[] Code_to_ascii; //видалення динамічних масивів
    delete[] Result;

    if (Res_key != 0)
    { 
        Res_key = abs(Res_key - 33);    //для запису ключа, оскільки зсув виконувся двліво по алфавіту
    }
 
}

void Ukr_decoder::Ukr_cipher_decryption(int* arr, int size, int key, string& str)  
{
    str.clear();    //очищуємо строку

    for (int shift = 0; shift < key; shift++)       //цикли зсуву
    {
        for (int index = 0; index < size; index++)
        {
            if (conversion_map.count(arr[index]) > 0)
            {
                auto res = conversion_map.find(arr[index]); //зсув відповідно мапи
                arr[index] = res->second;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        char symbol = (char)arr[i];     //запис резултату у строку 
        str += symbol;
    }
}

void Ukr_decoder::Ukr_letter_counter(int* arr, int size)    
{
    for (int iter = 0; iter < size; iter++)
    {
        if (conversion_map.count(arr[iter]) > 0)
        {
            letters_amount++;   //змінна яка тримає кількість літер
        }
    }

    if (letters_amount == 0)
    {
        letters_amount = 1;     
    }
}

void Ukr_decoder::Key_shift(int* arr, int size)
{
    for (int index = 0; index < size; index++)
    {
        if (conversion_map.count(arr[index]) > 0)
        {
            auto res = conversion_map.find(arr[index]);     //зсув відповідно мапи
            arr[index] = res->second;
        }
        else
        {
            arr[index] = arr[index];    //якщо відповідний ключ не знайшло, то залишаємо це символ як є
        }
    }

    float temp_arr_of_diff[33]; //массив різниці частот кожної літери алфавіту
    int temp_index = 0; // змінна-індекс массиву частот

    for (auto iter = conversion_map.begin(); iter != conversion_map.end(); iter++)  //проходимося по мапі частот
    {
        temp_arr_of_diff[temp_index] = Frequency_counter(arr, iter->first, size);   //записуємо в масив різницю частот
        temp_index++;
    }

    Difference(temp_arr_of_diff);  
}

float Ukr_decoder::Frequency_counter(int* arr, int letter_ascii, int size)
{
    int freq = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == letter_ascii)     //знаходимо скільки раз появляється дана буква
        {
            freq++;
        }

    }

    float result = (float)(freq * 100) / letters_amount;    //вирахування частоти

    return result;     //повертаємо частоту
}

void Ukr_decoder::Difference(float array_of_freq[])
{
    int index = 0;  //індекс масиву частот
    double total_difference = 0;    //для загальної різниці на зсуві

    for (auto iter : ukr_letter_freq)
    {
        total_difference += abs(iter.second - array_of_freq[index]);    //записуємо різницю
        index++;
    }

    this->temp_key++;   //запис ключа , який = зсуву 

    if (min_diff > total_difference)    
    {
        min_diff = total_difference;    //перезаписуємо мінімальну загальну частоту якщо така появилася
        Res_key = temp_key; //перезаписуємо ключ

        if (Res_key == 33)
        {
            Res_key = 0;    //коректність ключа
        }
    }

}