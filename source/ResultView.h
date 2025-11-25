#pragma once
#include "Singleton.h"
#include <iostream>

class ResultView : public Singleton<ResultView>
{
	
	friend class Singleton<ResultView>;
	ResultView() = default;
	virtual ~ResultView() = default;
public:

	// クリアビュー
	void ClearMSG() {
		std::cout << "とうばつ　かんりょう！" << std::endl;
		std::cout << "1: リスタート  2: 未定" << std::endl;
	}
	// オーバービュー
	void OverMSG() {
		std::cout << "とうばつ　しっぱい！" << std::endl;
		std::cout << "1: リスタート  2: 未定" << std::endl;
	}

	

};
