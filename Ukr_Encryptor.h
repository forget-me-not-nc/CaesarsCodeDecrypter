#pragma once 

#include "Encryptor.h"
#include "Ukr_decoder.h"
#include <map>      //підключення мап
#include <string>   //підключення строк


using std::string;  
using std::map;

class Ukr_Encryptor : Encryptor //клас унаслідуваний від Encryptor
{
public:
    Ukr_Encryptor();    //конструктор
	~Ukr_Encryptor();   //деконструктр
        
    void Encryption(string& Text, int key);    //метод кодування

private:
   
    map <int, int> conversion_map = { {-32,-31}, {-31,-30}, {-30,-29}, {-29,-76}, {-76,-28},        //мапа переходів
                                      {-28,-27}, {-27,-70}, {-70,-26}, {-26,-25}, {-25,-24},        
                                      {-24,-77}, {-77,-65}, {-65,-23}, {-23,-22}, {-22,-21},
                                      {-21,-20}, {-20,-19}, {-19,-18}, {-18,-17}, {-17,-16},
                                      {-16,-15}, {-15,-14}, {-14,-13}, {-13,-12}, {-12,-11},
                                      {-11,-10}, {-10,-9}, {-9,-8}, {-8,-7}, {-7,-4},
                                      {-4,-2}, {-2, -1}, {-1,-32} };
 
};