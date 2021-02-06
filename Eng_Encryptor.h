#pragma once
#include "Encryptor.h"
#include <string>

using std::string;

class Eng_Encryptor : Encryptor
{
public:
	Eng_Encryptor();	//конструктор
	~Eng_Encryptor();	//деконструктор

	void Encryption(int key, string& Text); //метод кодування
};

