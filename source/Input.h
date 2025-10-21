#pragma once
#include<iostream>
#include<string>

namespace Input
{
	inline char GetChar()
	{
		return std::cin.get();
	}

	inline std::string GetString()
	{
		std::string input;
		std::getline(std::cin, input);
		return input;
	}

	
}