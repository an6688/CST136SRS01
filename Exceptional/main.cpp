// Exceptional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sstream>
#include "RangeInt.h"
#include <iostream>

int main()
{
	auto errors{ 0 };
	auto goodTest{ 0 };
	auto testCase{ 0 };

	try
	{
		try// bad test 
		{
			++testCase;
			RangeInt test(10, 15);
			test.setValue(5);
		}
		catch (std::out_of_range &e)
		{
			++errors;
		}

		try// bad test
		{
			RangeInt test(20, 25);
			test.setValue(3);
		}
		catch (std::out_of_range &e)
		{
			++errors;
		}

		try// good test
		{
			RangeInt test(4.5, 10);
			test.setValue(9);
		}
		catch (std::out_of_range &e)
		{
			++errors;
			std::cout << e.what() << std::endl;
		}

	}
	catch (...)// 2 bad test, 1 good test 
	{
		++errors;
		throw;
	}
	system("pause");
	return 0;
}

