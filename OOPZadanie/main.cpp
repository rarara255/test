#include<iostream>

class Calculator
{
public:
	double add(double a, double b)
	{
		return a + b;
	}

	double subtract(double a, double b)
	{
		return a - b;
	}

	double multiply(double a, double b)
	{
		return a * b;
	}

	double divide(double a, double b)
	{
		if (b == 0)
			return 0;
		return a / b;
	}

	
	
};

using MathFunc = double(Calculator::*)(double, double);

double calculate(double a, double b, MathFunc& func)
{
	Calculator calc;
	return (calc.*func)(a,b);
}

	
int main()
{
	setlocale(LC_ALL, "RUS.UTF-8");

	char operation;
	double a, b;
	MathFunc func;
	std::cout << "Введите 1 число: ";
	std::cin >> a;
	std::cout << "Введите 2 число: ";
	std::cin >> b;
	std::cout << "Введите символ(+,-,*,/): ";
	std::cin >> operation;

	switch (operation)
	{
	case '+':
		func = &Calculator::add;
		std::cout << calculate(a, b, func);
		break;
	case '-':
		func = &Calculator::subtract;
		std::cout << calculate(a, b, func);
		break;
	case '*':
		func = &Calculator::multiply;
		std::cout << calculate(a, b, func);
		break;
	case '/':
		func = &Calculator::divide;
		std::cout << calculate(a, b, func);
		break;
	default:
		std::cout << "Неверный знак\n";
	}


	return 0;
}