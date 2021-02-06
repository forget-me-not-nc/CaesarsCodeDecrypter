#include "MyForm.h"
#include "Decoder.h"
#include "Eng_decoder.h"
#include <iostream>
#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")       //для того щоб приховати консоль при запуску форми
#pragma endregion

using namespace System;
using namespace System::Windows::Forms;
using std::string;

void main()
{

    setlocale(LC_ALL, "Ukrainian");                                     //підключення кирилиці
                                                                        //виклик форми 
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Caesarscode::MyForm Form;
    Application::Run(% Form);

}

void Caesarscode::MyForm::FileIn(string str)
{
	//запис у файл
	std::ofstream infile;	//змінна, яка виконує роль файла
	try
	{
		infile.open("Log.txt", std::ios::app);	//відкриваємо файл 

		infile << str << "\n--------------------------------------------------------------------------------------------------\n";
	}
	catch (...)
	{
		MessageBox::Show("Не вдалося відкрити файл!\n"		//вивід повідомлення якщо файл не відкрився
						  "Failed to open file!");
	}
}


