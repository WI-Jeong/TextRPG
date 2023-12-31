#include<iostream>
#include <string>


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

enum Job
{
	J_None,
	J_Knight,
	J_Archer,
	J_Wizard
};

enum Battle
{
	B_None,
	B_Attack,
	B_Back
};

struct Inventory
{
	int IGold;
};


struct Player
{
	char P_Name[32];
	char P_JobName[32];
	Job eJob;
	int P_AttackMax;
	int P_AttackMin;
	int P_ArmorMax;
	int P_ArmorMin;
	int P_HP;
	int P_HPMax;
	int P_MP;
	int P_MPMax;
	int P_Exp;
	int P_Level;
	Inventory eInventory;
};



struct Monster
{
	char M_Name[32];
	int M_AttackMax;
	int M_AttackMin;
	int M_ArmorMax;
	int M_ArmorMin;
	int M_HP;
	int M_HPMax;
	int M_MP;
	int M_MPMax;
	int M_Exp;
	int M_Level;
	int M_GoldMax;
	int M_GoldMin;
};



int main()
{
	srand((unsigned int)time(0));
	rand();

	char str[32];

	Player player = {};
	std::cout << "이름 : ";
	std::cin.getline(str, 32);


	int iJob = J_None;

	while (iJob == J_None)
	{
		system("cls");
		std::cout << "1. 기사" << std::endl;
		std::cout << "2. 궁사" << std::endl;
		std::cout << "3. 마법사" << std::endl;
		std::cout << "직업을 선택하세요 : ";
		std::cin >> iJob;

		if (iJob <= J_None || iJob > J_Wizard)
			iJob = J_None;

	}

	player.P_Level = 1;
	player.P_Exp = 0;
	player.eInventory.IGold = 10000;
	player.eJob = (Job)iJob;




	switch (player.eJob)
	{
	case J_Knight:
		strcpy_s(player.P_JobName, "기사");
		player.P_AttackMin = 5;
		player.P_AttackMax = 10;
		player.P_ArmorMin = 15;
		player.P_ArmorMax = 20;
		player.P_HPMax = 500;
		player.P_HP = 500;
		player.P_MP = 100;
		player.P_MPMax = 100;
		break;
	case J_Archer:
		strcpy_s(player.P_JobName, "궁수");
		player.P_AttackMin = 10;
		player.P_AttackMax = 15;
		player.P_ArmorMin = 10;
		player.P_ArmorMax = 15;
		player.P_HPMax = 400;
		player.P_HP = 400;
		player.P_MP = 200;
		player.P_MPMax = 200;
		break;
	case J_Wizard:
		strcpy_s(player.P_JobName, "마법사");
		player.P_AttackMin = 15;
		player.P_AttackMax = 20;
		player.P_ArmorMin = 5;
		player.P_ArmorMax = 10;
		player.P_HPMax = 300;
		player.P_HP = 300;
		player.P_MP = 300;
		player.P_MPMax = 300;
		break;
	}

	Monster MonsterArr[BP_Back - 1] = {};

	strcpy_s(MonsterArr[0].M_Name, "고블린");

	MonsterArr[0].M_AttackMin = 20;
	MonsterArr[0].M_AttackMax = 30;
	MonsterArr[0].M_ArmorMin = 2;
	MonsterArr[0].M_ArmorMax = 5;
	MonsterArr[0].M_HP = 100;
	MonsterArr[0].M_HPMax = 100;
	MonsterArr[0].M_MP = 10;
	MonsterArr[0].M_MPMax = 10;
	MonsterArr[0].M_Level = 1;
	MonsterArr[0].M_Exp = 1000;
	MonsterArr[0].M_GoldMin = 500;
	MonsterArr[0].M_GoldMax = 1500;

	strcpy_s(MonsterArr[1].M_Name, "트롤");

	MonsterArr[1].M_AttackMin = 80;
	MonsterArr[1].M_AttackMax = 130;
	MonsterArr[1].M_ArmorMin = 60;
	MonsterArr[1].M_ArmorMax = 90;
	MonsterArr[1].M_HP = 2000;
	MonsterArr[1].M_HPMax = 2000;
	MonsterArr[1].M_MP = 100;
	MonsterArr[1].M_MPMax = 100;
	MonsterArr[1].M_Level = 51;
	MonsterArr[1].M_Exp = 7000;
	MonsterArr[1].M_GoldMin = 6000;
	MonsterArr[1].M_GoldMax = 8000;

	strcpy_s(MonsterArr[2].M_Name, "드래곤");

	MonsterArr[2].M_AttackMin = 250;
	MonsterArr[2].M_AttackMax = 500;
	MonsterArr[2].M_ArmorMin = 200;
	MonsterArr[2].M_ArmorMax = 400;
	MonsterArr[2].M_HP = 30000;
	MonsterArr[2].M_HPMax = 30000;
	MonsterArr[2].M_MP = 20000;
	MonsterArr[2].M_MPMax = 20000;
	MonsterArr[2].M_Level = 10;
	MonsterArr[2].M_Exp = 30000;
	MonsterArr[2].M_GoldMin = 20000;
	MonsterArr[2].M_GoldMax = 50000;


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
		{
			std::cout << "잘못 입력했습니다." << std::endl;
			system("pause");
			continue;
		}

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

			Monster monster = MonsterArr[input - 1];

			while (true)
			{
				switch (input)
				{
				case BP_Easy:
					std::cout << "+++++++++++++++++++++++++쉬움++++++++++++++++++++++++" << std::endl;
					break;
				case BP_Normal:
					std::cout << "++++++++++++++++++++++++보통++++++++++++++++++++++++" << std::endl;
					break;
				case BP_Hard:
					std::cout << "++++++++++++++++++++++++어려움++++++++++++++++++++++++" << std::endl;
					break;
				}
					std::cout << "++++++++++++++++++++++++플레이어++++++++++++++++++++++++" << std::endl;
					std::cout << "이름 : " << player.P_Name << "\t직업 : " << player.P_JobName << std::endl;
					std::cout << "레벨 : " << player.P_Level << "\t경험치 : " << player.P_Exp << std::endl;
					std::cout << "공격력 : " << player.P_AttackMin << "~" << player.P_AttackMax << "방어력 : " << player.P_ArmorMin << "~" << player.P_ArmorMax << std::endl;
					std::cout << "체력 : " << player.P_HP << "/" << player.P_HPMax << "마나 : " << player.P_MP << "/" << player.P_MPMax << std::endl;
					std::cout << "보유골드 : " << player.eInventory.IGold << "Gold : " << std::endl << "\n";

					std::cout << "++++++++++++++++++++++++몬스터++++++++++++++++++++++++" << std::endl;
					std::cout << "이름 : " << monster.M_Name << "\t레벨 : " << std::endl;
					std::cout << "공격력 : " << monster.M_AttackMin << "~" << monster.M_AttackMax << "방어력 : " << monster.M_ArmorMin << "~" << monster.M_ArmorMax << std::endl;
					std::cout << "체력 : " << monster.M_HP << "/" << monster.M_HPMax << "마나 : " << monster.M_MP << "/" << monster.M_MPMax << std::endl;
					std::cout << "획득경험치 : " << monster.M_Exp << "\t획득골드" << monster.M_GoldMin << "~" << monster.M_GoldMax << std::endl << "\n";

					std::cout << "1.공격" << std::endl; 
					std::cout << "2. 도망가기" << std::endl;
					std::cout << "메뉴를 선택하세요" << std::endl;
					std::cin >> input;

					if (input == B_Back)
						break;
					else if (input <= B_None || input > B_Back)
						continue;

					switch (input)
					{
					case B_Attack:
						int P_AttackMin = rand() % (player.P_AttackMax - player.P_AttackMin+1) + player.P_AttackMin;
						break;
						
					}


		case MM_Store:
			break;
		case  MM_Inventory:
			break;
		default:
			std::cout << "잘못 입력했습니다." << std::endl;
			break;
				
			}
		}
	}

	return 0;
}