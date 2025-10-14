#pragma once

#include<cassert>
#include<stdexcept>

#define AssertExcept(text){\
	assert(false && text);\
	throw std::runtime_error(text);\
}\

