#include "Eng_decoder.h"
#include "Decoder.h"
#include <string>
#include <algorithm>
#include <map>

using std::string;
using std::map;

Eng_decoder::Eng_decoder() : temp_key(0), min_diff(100000)  //встановлюємо початковий мін. ключ та мін. частоту
{

}

Eng_decoder::~Eng_decoder()
{

}

void Eng_decoder::Decode(string& Code)
{
    string temp_Sentence = Code.substr(0, Code.size()); //тимчасова строка з якою буде проводитися робота 

    Eng_letter_counter(temp_Sentence);  //підраховуємо букви

    for (int alphabet = 0; alphabet < 26; alphabet++)   //цикл зміщення
    {
        Key_shift(temp_Sentence);   
    }

    Eng_Cipher_Decryption(Res_key, Code);   //розшифровуємо вже на відомий ключ
}

void Eng_decoder::Eng_Cipher_Decryption(int key, string& Sentence)
{

    for (int i = 0; i < key; i++) {     //цикли зміщення на ключ

        for (char& iter : Sentence) 
        {    
            if (isalpha(iter))
            {
                if (iter == 'a')
                {
                    iter = 'z';
                }
                else if (iter == 'A')
                {
                    iter = 'Z';
                }
                else
                {
                    iter--;
                }
            }
        }
    }
}

void Eng_decoder::Eng_letter_counter(const string& sentence)
{

    for (auto i : sentence)
    {
        if (isalpha(i))
        {
            letters_amount++;   
        }
    }

}

void Eng_decoder::Key_shift(string& sentence)
{
    for (char& i : sentence) {

        if (isalpha(i)) //якщо буква то
        {
            if (i == 'a')
            {
                i = 'z'; 
            }
            else
            {
                i--;        //робимо зсув
            }
        }
    }

    char letter = 'a';      //буква для порівняння
    float temp_arr_of_diff[26]; //масив для запису частот

    for (int lett = 0; lett < 26; lett++)   //цикл запису частот
    {
        temp_arr_of_diff[lett] = Frequency_counter(sentence, letter);
        letter++;   //проходимося по всім буквам
    }   

    Difference(temp_arr_of_diff);   //записуємо мінімальну загальну частоту
}

float Eng_decoder::Frequency_counter(const string& sentence, char letter)
{
    int freq = 0;

    for (auto iter : sentence)
    {
        if (iter == letter) //підраховуємо кількіть повторів букви
        {
            freq++;
        }

    }

    float result = (float)(freq * 100) / letters_amount;    //знаходимо частоту букви

    return result;  //повертаємо частоту
}

void Eng_decoder::Difference(float array_of_freq[])
{
    int index = 0;
    double total_difference = 0;

    for (auto iter : eng_letter_freq)
    {
        total_difference += abs(iter.second - array_of_freq[index]);    //сумуємо всі частоти
        index++;
    }

    this->temp_key++;

    if (min_diff > total_difference)   
    {
        min_diff = total_difference;     //перезаписуємо мінмальну частоту 
        Res_key = temp_key;

        if (Res_key == 26)
        {
            Res_key = 0;    //налаштовуємо корректність ключа
        }
    }

}