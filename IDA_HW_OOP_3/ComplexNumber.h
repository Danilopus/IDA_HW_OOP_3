#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>

/*
int Get_Random(int Range_min = -999, int Range_max = 999)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min = -99999.0, double Range_max = 99999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;
}
int Get_Int_SA() {
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-')
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
*/

//enum keycodes {Esc=27, Enter=13};
static std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"} };
static std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
static std::string big_space = "                                                           ";
static std::map <int, int> codes_of_digits { {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };
static std::map <int, char> codes_of_operation{ {1,'+'}, {2,'-'}, {3,'*'}, {4,'/'} };

//struct ComplexNumber
//{	
////private:
//protected:
//	double _real_part;
//	double _imagine_part;
//};

class ComplexNumber
{
protected:
	double _real_part;
	double _imagine_part;
};

class ComplexNumber_class_through_inheritance : public ComplexNumber
{
	int index = 0;
	static std::vector <ComplexNumber_class_through_inheritance*> _numbers_list;
public:
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
			ComplexNumber_class_through_inheritance* ptr = new ComplexNumber_class_through_inheritance(Get_Random(-100.0, 100.0), Get_Random(-100.0, 100.0));
			//_numbers_list.push_back(ptr);
		}
	}
	static void MemoryClean()
	{
		for (int i = 0; i < _numbers_list.size(); i++)
		{
			delete _numbers_list[i];
		}
		_numbers_list.clear();
	}
	static void User_Choice_Handle()
	{
		int action = Check_action_input();
		if (action == -1) return;
		std::cout << "-------->  " << codes_of_operation[action] << "                                 ";

		ComplexNumber_class_through_inheritance& Operand_1 = *Get_Operand(1);
		if (&Operand_1 == nullptr) return;
		std::cout << "\n   " << codes_of_operation[action];
		ComplexNumber_class_through_inheritance& Operand_2 = *Get_Operand(2);
		if (&Operand_2 == nullptr) return;


		std::cout << "\n\n";
		Operand_1.Show();
		std::cout << "  " << codes_of_operation[action] << "  ";
		Operand_2.Show();
		std::cout << " = ";
		switch (action)
		{
		case 1: (Operand_1 + Operand_2).Show(); break;
		case 2: (Operand_1 - Operand_2).Show(); break;
		case 3: (Operand_1 * Operand_2).Show(); break;
		case 4: (Operand_1 / Operand_2).Show(); break;

		default: std::cout << "\nkeycode " << action;
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
	static int Check_action_input()
	{
		int keycode = _getch();
		//std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		std::cout << console_clear;
		switch (keycode)
		{
		case 27:	return -1;
		case 43:	return 1;
		case 45:	return 2;
		case 42:	return 3;
		case 47:	return 4;

		default:
			//std::cout << "\nkeycode " << keycode;
			std::cout << "Press key of operation [+] [*] [-] [/]";
			Check_action_input();
		}
	}
	void Show()
	{
		char plus_for_positive = '+';
		if (_imagine_part < 0) plus_for_positive = '\0';
		std::cout << std::setprecision(4) << std::setw(5) << _real_part << plus_for_positive << std::setprecision(4) << _imagine_part << "i";
	}
	static ComplexNumber_class_through_inheritance* New_number_input()
	{
		std::cout << big_space;
		std::cout << "\nEnter real part    -> ";
		double real_part = Get_Dbl_SA();
		std::cout << "Enter imagine part -> ";
		double imagine_part = Get_Dbl_SA();
		//ComplexNumber_class_through_inheritance& new_obj_ref = *new ComplexNumber_class_through_inheritance(real_part, imagine_part);
		//return new_obj_ref;
		return new ComplexNumber_class_through_inheritance(real_part, imagine_part);
	}
	static ComplexNumber_class_through_inheritance* Get_Operand(int operand_number)
	{
		std::cout << "\nOperand_" << operand_number << ": Choose operand from list[number] or enter new[press Enter]";
		do
	{
		int input = _getch();
		//std::cout << console_clear;
		if (keycodes[input] == "Enter")
			//if (input == 27)
		{
			std::cout << console_clear;
			return New_number_input();
		}
		else if (keycodes[input] == "Esc") return nullptr;
		//else if (input == 27) return;
		/*else if (input == 0 || input == 224)
		{
			_getch();
			std::cout << "\nTurn NumLock On";
			return nullptr;
		}*/
		else if (49 <= input && input <= 57)
		{
			//_getch(); придумать 2х значный ввод
			std::cout << console_clear;
			if (codes_of_digits[input] >= _numbers_list.size())
			{
				std::cout << console_clear << "index out of range" << big_space;
				return nullptr;
			}
			std::cout << "  [" << codes_of_digits[input] + 1 << "]                                                        ";
			return _numbers_list[codes_of_digits[input]];
		}
		} while (true);
	}
	ComplexNumber_class_through_inheritance& operator+(const ComplexNumber_class_through_inheritance& another_complex_number)
	//ComplexNumber_class_through_inheritance* operator+(const ComplexNumber_class_through_inheritance& another_complex_number)
	{
		double new_real_part = this->_real_part + another_complex_number._real_part;
		double new_imagine_part = this->_imagine_part + another_complex_number._imagine_part;
		return *new ComplexNumber_class_through_inheritance(new_real_part, new_imagine_part);
	}
	ComplexNumber_class_through_inheritance& operator-(const ComplexNumber_class_through_inheritance& another_complex_number)
	{
		double new_real_part = this->_real_part - another_complex_number._real_part;
		double new_imagine_part = this->_imagine_part - another_complex_number._imagine_part;
		return *new ComplexNumber_class_through_inheritance(new_real_part, new_imagine_part);
	}
	ComplexNumber_class_through_inheritance& operator*(const ComplexNumber_class_through_inheritance& another_complex_number)
	{
		double new_real_part = (this->_real_part * another_complex_number._real_part) - (this->_imagine_part * another_complex_number._imagine_part);
		double new_imagine_part = (this->_real_part * another_complex_number._imagine_part) + (this->_imagine_part - another_complex_number._real_part);
		return *new ComplexNumber_class_through_inheritance(new_real_part, new_imagine_part);
	}
	ComplexNumber_class_through_inheritance& operator/(const ComplexNumber_class_through_inheritance& another_complex_number)
	{		
		double x1 = this->_real_part;
		double x2 = another_complex_number._real_part;
		double y1 = this->_imagine_part;
		double y2 = another_complex_number._imagine_part;		
		double new_real_part = (x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2);
		double new_imagine_part = (x2*y1-x1*y2) / (x2 * x2 + y2 * y2);
		return *new ComplexNumber_class_through_inheritance(new_real_part, new_imagine_part);
	}

};

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
