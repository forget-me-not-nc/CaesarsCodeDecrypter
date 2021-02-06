#include "Eng_Encryptor.h"
#include "Encryptor.h"

Eng_Encryptor::Eng_Encryptor() 
{

}

Eng_Encryptor::~Eng_Encryptor() 
{

}

void Eng_Encryptor::Encryption(int key, string& Text)
{
    if (key >= 26)
    {
        key -= 26;  //забераємо непотрібну кількість ітерацій
    }

    for (int i = 0; i < key; i++)   //цикл зсуву
    {
        for (char& iter : Text) //проходимося по тексту
        {
            if (isalpha(iter))  //якщо буква ТО
            {
                if (iter == 'Z')       //міняємо на одну вправо по алфавіту 
                {
                    iter = 'A';
                }
                else if (iter == 'z')
                {
                    iter = 'a';
                }
                else
                {
                    iter++;
                }
            }
        }
    }

}
