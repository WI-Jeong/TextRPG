#include<iostream>

enum MainMenu
{
	MM_None,
	MM_Battle,
	MM_Store,
	MM_Inventory,
	MM_Exit
};

enum BattlePage
{
	BP_None,
	BP_Easy,
	BP_Normal,
	BP_Hard,
	BP_Back
};



int main()
{
	while (true)
	{
		system("cls");
		std::cout << "++++++++++++++++++++++++로비++++++++++++++++++++++++" << std::endl;
		std::cout << "1. 전투" << std::endl;
		std::cout << "2. 상점" << std::endl;
		std::cout << "3. 인벤토리" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cout << "메뉴를 선택하세요 : ";
		int input = 0;
		std::cin >> input;

		if (input == MM_Exit)
			break;
		else if (input <= MM_None || input > MM_Exit)
			std::cout << "잘못 입력했습니다." << std::endl;
		system("pause");
			continue;

		switch (input)
		{
		case MM_Battle:
			while (true)
			{
				system("cls");
				std::cout << "++++++++++++++++++++++++전투++++++++++++++++++++++++" << std::endl;
				std::cout << "1. 쉬움" << std::endl;
				std::cout << "2. 보통" << std::endl;
				std::cout << "3. 어려움" << std::endl;
				std::cout << "4. 뒤로가기" << std::endl;
				std::cout << "메뉴를 선택하세요 : ";
				std::cin >> input;  

				if (input <= BP_None || input > BP_Back) 
					continue;
				else if (input == BP_Back)  
					break;
			}
			break;
		case MM_Store: 
			break;
		case  MM_Inventory:
			break;
		default:
			std::cout << "잘못 입력했습니다." << std::endl; 
			break;
		}
	}

	return 0;
}