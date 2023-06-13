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
	static std::vector <ComplexNumber_class_through_inheritance*> _numbers_list;
public:
	//не могу заставить работать инициализацию через :
	//ComplexNumber_class(double real_part = -1, double imagine_part = -1): _real_part(real_part), _imagine_part(imagine_part)
	ComplexNumber_class_through_inheritance(double real_part = -1, double imagine_part = -1);
	static void Initialisation(int provided_at_startup_complex_number_quantity);
	static void MemoryClean();
	static void User_Choice_Handle();
	static void Show_List_of_available_numbers();
	static void ShowMethods();
	static int Check_action_input();
	void Show();
	static ComplexNumber_class_through_inheritance* New_number_input();
	static ComplexNumber_class_through_inheritance* Get_Operand(int operand_number);
	ComplexNumber_class_through_inheritance& operator+(const ComplexNumber_class_through_inheritance& another_complex_number);
	ComplexNumber_class_through_inheritance& operator-(const ComplexNumber_class_through_inheritance& another_complex_number);
	ComplexNumber_class_through_inheritance& operator*(const ComplexNumber_class_through_inheritance& another_complex_number);
	ComplexNumber_class_through_inheritance& operator/(const ComplexNumber_class_through_inheritance& another_complex_number);
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
