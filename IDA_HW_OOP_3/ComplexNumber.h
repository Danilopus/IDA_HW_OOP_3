#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>

//enum keycodes {Esc=27, Enter=13};
static std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"} };
//std::map <int, int> codes_of_digits { {"Esc", 27}, {"Enter", 13} };



struct ComplexNumber
{	
//private:/
//protected:
	double _real_part;
	double _imagine_part;
};

//class ComplexNumber
//{
//public:
//	double _real_part;
//	double _imagine_part;
//};

class ComplexNumber_class_through_inheritance : public ComplexNumber
{
	//ComplexNumber _complex_number;
	int index = 0;
	static std::vector <ComplexNumber_class_through_inheritance*> _numbers_list;
public:
	//static std::vector <ComplexNumber_class_through_inheritance*> _numbers_list;
	//ComplexNumber_class(double real_part = -1, double imagine_part = -1) : _complex_number { real_part, imagine_part }	{}	
	//не могу заставить работать инициализацию через :
	//ComplexNumber_class(double real_part = -1, double imagine_part = -1): _real_part(real_part), _imagine_part(imagine_part)
	ComplexNumber_class_through_inheritance(double real_part = -1, double imagine_part = -1)
	{
		ComplexNumber::_real_part = real_part;
		_imagine_part = imagine_part;
		_numbers_list.push_back(this);
	}


	static void Initialisation(int provided_at_startup_complex_number_quantity)
	{
		for (int i{ 0 }; i < provided_at_startup_complex_number_quantity; i++)
		{
			ComplexNumber_class_through_inheritance* ptr = new ComplexNumber_class_through_inheritance(Get_Random(0.0, 100.0), Get_Random(0, 100));
			_numbers_list.push_back(ptr);
		}
	}
	static void Show_List_of_available_numbers()
	{

		for (int i = 0; i < _numbers_list.size(); i++)
		{
			std::cout << "\n" << "[" << i + 1 << "] ";
			_numbers_list[i]->Show();
		}
		std::cout << "\n";
	}
	static void ShowMethods()
	{
		std::cout << '\n' << '\n';
		std::cout << "Summation [+]" << '\n';
		std::cout << "Substract [-]" << '\n';
		std::cout << "Multiply  [*]" << '\n';
		std::cout << "Divide    [/]" << '\n';
	}
	//static int Check_action_input(int keycode)
	static int Check_action_input()
	{
		int keycode = _getch();
		switch (keycode)
		{
		case 1:	return 1;
		case 2:	return 2;
		case 3:	return 3;
		default: 
			std::cout << "\nkeycode " << keycode;
			//std::cout << "\nPress key of operation [+] [*] [-] [/]" << "\n";
			Check_action_input();
			//ShowMethods();
		}
	}
	static ComplexNumber_class_through_inheritance* Get_Operand(int operand_number)
	{
		std::cout << "\nOperand_" << operand_number << ": Choose operand from list[number] or enter new[press Enter]";
		int input = _getch();
		//if (keycodes[input] == "Enter")
		if (input == 27)
		{
			return New_number_input();
		}
		//else if (keycodes[input] == "Esc") return;
		//else if (input == 27) return;
		else
		{
			//_getch(); придумать 2х значный ввод
			return _numbers_list[input];
		}
	}
	static void User_Choice_Handle()
	{
		//int action = Check_action_input(getch());
		int action = Check_action_input();

		ComplexNumber_class_through_inheritance* Operand_1 = Get_Operand(1);
		ComplexNumber_class_through_inheritance* Operand_2 = Get_Operand(2);
		
			switch (action)
			{
			//case 1: (*Operand_1 + *Operand_2).Show(); break;



			default: std::cout << "\nkeycode " << action;

			}

		
	}
	void Show()
	{
		char plus_for_positive = '+';
		if (_imagine_part < 0) plus_for_positive = '\0';
		std::cout << _real_part << plus_for_positive << _imagine_part << "i";
	}


	static ComplexNumber_class_through_inheritance* New_number_input()
	{
		std::cout << '\n' << "Enter real part -> ";
		int real_part = Get_Int_SA();
		std::cout << '\n' << "Enter imagine part -> ";
		int imagine_part = Get_Int_SA();
		//ComplexNumber_class_through_inheritance& new_obj_ref = *new ComplexNumber_class_through_inheritance(real_part, imagine_part);
		//return new_obj_ref;
		return new ComplexNumber_class_through_inheritance(real_part, imagine_part);
	}


};

std::vector <ComplexNumber_class_through_inheritance*> ComplexNumber_class_through_inheritance::_numbers_list;


//class ComplexNumber_class_through_including
//{
//	ComplexNumber _complex_number;
//
//public:
//	//ComplexNumber_class_through_including(double real_part = -1, double imagine_part = -1) : _complex_number { real_part, imagine_part }	{}
//
//	static void Initialisation()
//	{
//
//	}
//};
