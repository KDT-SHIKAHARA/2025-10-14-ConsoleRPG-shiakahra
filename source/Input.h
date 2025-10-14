#pragma once
#include<iostream>
#include<string>

namespace Input
{
	char GetChar()
	{

		return std::cin.get();
	}

	std::string GetString()
	{
		std::string input;
		std::getline(std::cin, input);
		return input;
	}

	
}