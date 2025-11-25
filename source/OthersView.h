#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>

class OthersView : public Singleton<OthersView>
{

	friend class Singleton<OthersView>;
	OthersView() = default;
	virtual ~OthersView() = default;

public:


	void IngameInitMSG() {
		std::cout << "InGame‰Šú‰»" << std::endl;
	}

	void RodView() {
		std::cout << "============================================================" << std::endl;
	}

};
