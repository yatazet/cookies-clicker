#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;
enum class Keys {
	NOSET,
	ENTER = 0x0D,
	ESC = 0x1B,
	SPACE = 0x20,
};
void sell(int cookies, int money)
{
	if (cookies > 1) money += cookies / 2 + cookies / 4;
	cookies = 0;
	system("cls");
	cout << "Current cookies: " << cookies << "\tCurrent Money: " << money;
}
void farm(int cookies, int level, int money)
{
	while (true)
	{
		if (_kbhit())
		{
			switch (static_cast<Keys>(_getch()))
			{
			case Keys::ENTER:
				if (level == 1) cookies++;
				if (level == 2) cookies += 5;
				if (level == 3) cookies += 10;
				if (level == 4) cookies += 100;
				if (level == 5) cookies += 1000;
				if (level == 6) cookies += 10000;
				if (level == 7) cookies += 100000;
				if (level == 8) cookies += 1000000;
				if (level == 9) cookies += 10000000;
				if (level == 10) cookies += 100000000;
				if (cookies >= 10) level = 2;
				if (cookies >= 100) level = 3;
				if (cookies >= 1000) level = 4;
				if (cookies >= 10000) level = 5;
				if (cookies >= 100000) level = 6;
				if (cookies >= 1000000) level = 7;
				if (cookies >= 10000000) level = 8;
				if (cookies >= 100000000) level = 9;
				if (cookies >= 1000000000) level = 10;
				if (cookies >= 10000000000) level = 11;
				if (level == 11) cout << "YOU WON" << endl;
				system("cls");
				cout << "Current cookies: " << cookies << "\tCurrent Money: " << money;
				break;
			case Keys::ESC:
				exit(0);
				break;
			case Keys::SPACE:
				sell(cookies, money);
			}
		}
	}
}
int main()
{
	int cookies = 0;
	int money = 0;
	int level = 1;
	farm(cookies, level, money);
}