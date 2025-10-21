#pragma once
#include<iostream>
#include<string>

namespace Input
{
	inline char GetChar()
	{
		char tmp;
		std::cin >> tmp;
		return tmp;
	}

	inline std::string GetString()
	{
		std::string input;
		std::getline(std::cin, input);
		return input;
	}

	
}