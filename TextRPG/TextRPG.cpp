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
		std::cout << "++++++++++++++++++++++++�κ�++++++++++++++++++++++++" << std::endl;
		std::cout << "1. ����" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. �κ��丮" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cout << "�޴��� �����ϼ��� : ";
		int input = 0;
		std::cin >> input;

		if (input == MM_Exit)
			break;
		else if (input <= MM_None || input > MM_Exit)
			std::cout << "�߸� �Է��߽��ϴ�." << std::endl;
		system("pause");
			continue;

		switch (input)
		{
		case MM_Battle:
			while (true)
			{
				system("cls");
				std::cout << "++++++++++++++++++++++++����++++++++++++++++++++++++" << std::endl;
				std::cout << "1. ����" << std::endl;
				std::cout << "2. ����" << std::endl;
				std::cout << "3. �����" << std::endl;
				std::cout << "4. �ڷΰ���" << std::endl;
				std::cout << "�޴��� �����ϼ��� : ";
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
			std::cout << "�߸� �Է��߽��ϴ�." << std::endl; 
			break;
		}
	}

	return 0;
}