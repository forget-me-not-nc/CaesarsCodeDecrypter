#pragma once
#include "Decoder.h"
#include <string>
#include <map>

using std::string;
using std::map;

class Eng_decoder : public Decoder  //унаслідований клас
{
public:

    Eng_decoder();      //конструктор
    void Decode(string& Code);  //метод початку процесу
    ~Eng_decoder();     //деконструктор

private:

    int temp_key;   //тимчасова змінна для запису ключа
    double min_diff;    //змінна для мінімальної частоти

    map <char, double> eng_letter_freq = { {'a',8.497}, {'b',1.492}, {'c',2.202}, {'d',4.253}, {'e',12.702},    //мапа частот
                                           {'f',2.228}, {'g',2.015}, {'h',6.094}, {'i',6.966}, {'j',0.153},
                                           {'k',1.292}, {'l',4.025}, {'m',2.406}, {'n',6.749}, {'o',7.507},
                                           {'p',1.929}, {'q',0.095}, {'r',5.987}, {'s',6.327}, {'t',9.356},
                                           {'u',2.758}, {'v',0.978}, {'w',2.560}, {'x',0.150}, {'y',1.994},
                                           {'z',0.077} };

    void Eng_Cipher_Decryption(int key, string& Sentence);  //метод декодування на відомий вже ключ
    void Eng_letter_counter(const string& sentence);        //метод підрахунку слів
    void Key_shift(string& sentence);                       //метод зсуву
    float Frequency_counter(const string& sentence, char letter);   //метод підрахунку частоти букви
    void Difference(float array_of_freq[]);     //метод знаходження мінімальної загальної частоти

};