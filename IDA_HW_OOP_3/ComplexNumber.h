#pragma once
#include <vector>

struct ComplexNumber
{	
//private:
protected:
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
	static std::vector <ComplexNumber_class_through_inheritance*> _numbers_list;
public:
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
			
			//_numbers_list[i]->_real_part = Get_Random(0, 100);
			//_numbers_list[i]->_imagine_part = Get_Random(0, 100);
		}
	}
	static void Show_List_of_available_numbers()
	{

	}
	static void ShowMethods();
	static void User_Choice_Handle();

};

class ComplexNumber_class_through_including
{
	ComplexNumber _complex_number;

public:
	ComplexNumber_class_through_including(double real_part = -1, double imagine_part = -1) : _complex_number { real_part, imagine_part }	{}

	static void Initialisation()
	{

	}
};
