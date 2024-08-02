#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <iomanip>
#include<algorithm>
#include<random> 

//ゲームルール
void gamerule() {
	std::cout << "In this game, you will create your own species. Your world is defined by temperature and wateriness. Individuals who adapted the environment better are more likely to succeed. In the end, the species with the most animals win." << std::endl << std::endl;
	std::cout << "Each species starts with five individuals, the optimal temperature and wateriness are 25. The environment temperature and wateriness are also 25 in the first round. Each turn, the environment temperature and wateriness will be randomly changed. In the first round, the proportion of grazing and browsing in food is fifty-fifty. The proportion of grazing and browsing in food would also change randomly every turn. " << std::endl << std::endl;
	std::cout << "Each individual need 1 food to survive. If you don’t have enough food the population of your species would decrease. On the other hands, the std::left food can be used to adopt your organism, which would change the optimal temperature and wateriness. The available adaptiveness and cost is written in the table, please press 2 to check. You can also spend 3 food to produce an individual or 1 food to sacrifice one." << std::endl << std::endl;
	std::cout << "At the end of the game, the species with the most animals win. However, if your species extinct during the game, you lose and this game is over." << std::endl << std::endl;
}

//特徴表の出力
void Traitstable() {
	std::cout << std::left << std::setw(5) << "#" << std::setw(20) << "trait" << std::setw(20) << "Temperature" << std::setw(19) << "Wateriness" << std::setw(23) << "Evolution cost" << std::endl;
	std::cout << std::right << std::setw(60) << "Optimal temperature modifying traits" << std::endl;
	std::cout << std::left << std::setw(5) << "1" << std::setw(24) << "Fat" << std::setw(20) << "-5" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "2" << std::setw(24) << "Fur" << std::setw(20) << "-5" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "3" << std::setw(24) << "Burrowing" << std::setw(20) << "+5" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "4" << std::setw(24) << "Nocturnal" << std::setw(20) << "+5" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "5" << std::setw(24) << "Endothermic" << std::setw(20) << "-10" << std::setw(22) << "-" << std::setw(5) << "2" << std::endl;
	std::cout << std::left << std::setw(5) << "6" << std::setw(24) << "Antifreeze" << std::setw(20) << "-10" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "7" << std::setw(24) << "Big ears" << std::setw(20) << "+5" << std::setw(22) << "-" << std::setw(5) << "1" << std::endl;
	std::cout << std::right << std::setw(59) << "Optimal wateriness modifying traits" << std::endl;
	std::cout << std::left << std::setw(5) << "8" << std::setw(24) << "Concentrated urine" << std::setw(20) << "-" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "9" << std::setw(24) << "Salt excretion" << std::setw(20) << "-" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "10" << std::setw(24) << "Webbe feet" << std::setw(20) << "-" << std::setw(22) << "+5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "11" << std::setw(24) << "Raised nostrils" << std::setw(20) << "-" << std::setw(22) << "+5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "12" << std::setw(24) << "Water breathing" << std::setw(20) << "-" << std::setw(22) << "+5" << std::setw(5) << "2" << std::endl;
	std::cout << std::left << std::setw(5) << "13" << std::setw(24) << "Spines" << std::setw(20) << "-" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "14" << std::setw(24) << "Large rumen" << std::setw(20) << "-" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::right << std::setw(66) << "Traits affecting both environmental optima" << std::endl;
	std::cout << std::left << std::setw(5) << "15" << std::setw(24) << "Exoskeleton" << std::setw(20) << "-5" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "16" << std::setw(24) << "Long legs" << std::setw(20) << "+5" << std::setw(22) << "+5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "17" << std::setw(24) << "Sweating" << std::setw(20) << "+5" << std::setw(22) << "+5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "18" << std::setw(24) << "Torpor" << std::setw(20) << "+5" << std::setw(22) << "-5" << std::setw(5) << "1" << std::endl;
	std::cout << std::left << std::setw(5) << "19" << std::setw(24) << "Large size" << std::setw(20) << "-10" << std::setw(22) << "+5" << std::setw(5) << "2" << std::endl;
}

//プレイヤーが二名以上ことを確認する
int check1(int a) {
	while (a < 2) {
		std::cout << "This game need at least two players.Please enter agian." << std::endl;
		std::cin >> a;
		if (a >= 2) break;
	}
	return a;
}

//ゲームの回数が二回以上ことを確認する
int check2(int a) {
	while (a < 2) {
		std::cout << "This game need at least 2 rounds.Please enter agian." << std::endl;
		std::cin >> a;
		if (a >= 2) break;
	}
	return a;
}

//正しい動物種類を選択したことを確認する
int check3(int a) {
	int check3 = 0;
	while (check3 != 1) {
		if (a == 1 || a == 2 || a == 3) {
			check3 = 1;
			return a;
		}
		else {
			std::cout << "Please choose from the options above.Please enter agian." << std::endl;
			std::cin >> a;
		}
	}
}

//ゲームルールの説明と特徴表の出力
void check4(int x) {
	while (1) {
		x = check3(x);
		if (x == 1) gamerule();
		if (x == 2)Traitstable();
		if (x == 3)break;
		std::cout << "Press 1 to see game rules, press 2 to see traits table, press 3 to start the game" << std::endl;
		std::cin >> x;
	}
}


//動物の適応性の計算
int adaptivenesscalculate(int a, int b, int c, int d) {
	int adaptiveness = 0;
	adaptiveness = 100 - (abs(a - b) + abs(c - d));
	return adaptiveness;
}

//食べ物の計算
float foodcalculate(int a, int b, int c, int sg, int sb, int Food, float totalg, float totalb, int grazing, int browsing) {
	//a=vec[i].type, b=vec[i].adap, c=vec[i].pop
	float f = 0;
	if (a == 1) {
		if (sg == 0) {
			f += (float)b * c / 2 / totalg * grazing / 100 * Food / 2;
			//std::cout << "a";　検査用
		}
		if (sg != 0) {
			f += (float)b * c / 2 / totalg * grazing / 100 * Food;
			//std::cout << "b" << f << std::endl;
		}
		if (sb == 0) {
			f += (float)b * c / 2 / totalb * browsing / 100 * Food / 2;
			//std::cout << "c" << f << std::endl;
		}
		if (sb != 0) {
			f += (float)b * c / 2 / totalb * browsing / 100 * Food;
			//std::cout << "d" << f << std::endl;
		}
	}
	if (a == 2) {
		f += (float)b * c / totalb * browsing / 100 * Food;
		//std::cout << "e" << f << std::endl;
	}
	if (a == 3) {
		f += (float)b * c / totalg * grazing / 100 * Food;
		//std::cout << "f" << f << std::endl;
	}
	f = round(f);
	return f;
}

//増加した特徴の判断
void Adaptation(int* T, int* W, float* F, int* P) {
	std::vector <int> v{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 };
	auto begin = v.cbegin();
	auto end = v.cend();
	int a = 0;
	int b = 0;

	while (1) {
		std::cin >> a;
		auto pos = std::find(begin, end, a);
		while (pos == end) {
			std::cout << "Please enter a number from 0 to 22." << std::endl;
			std::cin >> a;
			auto pos = std::find(begin, end, a);
			if (pos != end)break;
		}

		if (a == 0) {
			Traitstable();
		}
		if (a == 1) {
			*T += -5;
			*F += -1;
		}
		if (a == 2) {
			*T += -5;
			*F += -1;
		}
		if (a == 3) {
			*T += +5;
			*F += -1;
		}
		if (a == 4) {
			*T += +5;
			*F += -1;
		}
		if (a == 5) {
			if (*F < 2)std::cout << "Sorry, you don't have enough food." << std::endl;
			else {
				*T += -10;
				*F += -2;
			}
		}
		if (a == 6) {
			*T += -10;
			*F += -1;
		};
		if (a == 7) {
			*T += +5;
			*F += -1;
		}
		if (a == 8) {
			*W += -5;
			*F += -1;
		}
		if (a == 9) {
			*W += -5;
			*F += -1;
		}
		if (a == 10) {
			*W += +5;
			*F += -1;
		}
		if (a == 11) {
			*W += +5;
			*F += -1;
		}
		if (a == 12) {
			if (*F < 2)std::cout << "Sorry, you don't have enough food." << std::endl;
			else {
				*W += +5;
				*F += -2;
			}
		}
		if (a == 13) {
			*W += -5;
			*F += -1;
		}
		if (a == 14) {
			*W += -5;
			*F += -1;
		}
		if (a == 15) {
			*T += -5;
			*W += -5;
			*F += -1;
		}
		if (a == 16) {
			*T += +5;
			*W += +5;
			*F += -1;
		}
		if (a == 17) {
			*T += +5;
			*W += +5;
			*F += -1;
		}
		if (a == 18) {
			*T += +5;
			*W += -5;
			*F += -1;
		}
		if (a == 19) {
			if (*F < 2)std::cout << "Sorry, you don't have enough food." << std::endl;
			else {
				*T += -10;
				*W += +5;
				*F += -2;
			}
		}
		if (a == 20) {
			if (*F < 3)std::cout << "Sorry, you don't have enough food." << std::endl;
			else {
				*P += +1;
				*F += -3;
			}
		}
		if (a == 21) {
			*P += -1;
			*F += -1;
		}
		if (a == 22) {
			*F = 0;
			break;
		}
		if (*F == 0) {
			std::cout << "You used all of your foods." << std::endl;
			std::cout << "Your best temperature is " << *T << ", best wateriness is " << *W << ", the population is " << *P << "." << std::endl;
			break;
		}

		if (*P == 0) {
			break;
		}

		std::cout << "You still have " << *F << " food left!" << "Your best temperature is " << *T << ", best wateriness is " << *W << ", the population is " << *P << "." << std::endl;
		std::cout << "Enter 1 for next adaptation, enter 0 to end the adaptation." << std::endl;
		std::cin >> b;
		while (b != 0 && b != 1) {
			std::cout << "Please enter 0 or 1." << std::endl;
			std::cin >> b;
		}
		if (b == 0) {
			*F = 0;
			break;
		}
		else std::cout << "Please enter the number of the trait that you want to add to your animal." << std::endl;
	}
}

//毎年に温度と湿度の変換
int Dieroll1(int a) {
	int b = 0;
	int c = 1;
	int d = 5;

	//温度と湿度の範囲は０～５０である
	if (a < 0) {
		c = 3;
	}
	if (a > 50) {
		d = 3;
	}
	std::random_device engine;
	std::uniform_int_distribution<int>num(c, d);
	b = num(engine);
	if (b == 1) a += -10;
	if (b == 2) a += -5;
	if (b == 3) a += 0;
	if (b == 4) a += 5;
	if (b == 5) a += 10;
	return a;
}

//毎年に食べ物の変換
int Dieroll2() {
	std::random_device engine;
	std::uniform_int_distribution<int>num(30, 70);
	return num(engine);
}

#endif