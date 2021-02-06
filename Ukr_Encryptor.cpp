#include "Ukr_Encryptor.h"
#include "Encryptor.h"

#include <algorithm>	//для функції переводу в нижній регістр

Ukr_Encryptor::Ukr_Encryptor()	
{

}

Ukr_Encryptor::~Ukr_Encryptor()
{

}

void Ukr_Encryptor::Encryption(string& Text, int key)
{
	if (key >= 33)
	{
		key -= 33;		//для того щоб забрати лишні ітерації
	}

	int size = Text.size();	//змінна для запису розімрності строки

	std::transform(Text.begin(), Text.end(), Text.begin(), tolower);	//перевід в нижній регістр
	
	int* Text_to_ascii = new int[size];		//динамічний массив чисел, код яких відповідє кожній букві тексту 

	for (int iter = 0; iter < size; iter++)
	{
		Text_to_ascii[iter] = (int)Text[iter];	//заповнюємо масив
	}

	for (int shift = 0; shift < key; shift++)		//початок зміщення на певний ключ
	{
		for (int index = 0; index < size; index++)
		{
			if (conversion_map.count(Text_to_ascii[index]) > 0)
			{
				auto res = conversion_map.find(Text_to_ascii[index]);	//шукаємо кожен елемент масиву в мапі переходів 
				Text_to_ascii[index] = res->second;		//присвоюємо значення з мапи відповідного ключа
			}
		}
	}

	Text.clear();	//очищуємо строку для запису зашифрованого тексту

	for (int i = 0; i < size; i++)
	{
		char symbol = (char)Text_to_ascii[i];	//переводимо в char кожен елемент масиву
		Text += symbol;
	}

	delete[] Text_to_ascii;		//видаляємо динамічний массив
}
