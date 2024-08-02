#include"number.h"
using namespace std;


struct Data {
	string name;
	int type;
	int pop; //population
	int adap;//Adaptiveness
	float food;
	int T;//Temperature
	int W;//Wateriness
};

int main() {
	int num = 0;
	int num2 = 0;
	int rounds = 0;
	int animaltype = 0;
	int sb = 0;//specialist-browsersの数
	int sg = 0;//specialist-grazersの数
	vector <int> v{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
	auto begin = v.cbegin();
	auto end = v.cend();
	vector <Data> vec;

	//ゲームルールの説明と特徴表の出力
	cout << "Welcome to the evolution game!" << endl;
	cout << "Press 1 to see game rules, press 2 to see traits table, press 3 to start the game" << endl;
	cin >> num2;
	check4(num2);

	//プレイヤーの人数を確認
	cout << "Please enter the number of players." << endl;
	cin >> num;
	num = check1(num);


	//プレイヤーの名前と初期の設定
	for (int i = 0; i < num; i++) {
		cout << "Please enter the name of player" << i+1 << endl;
		vec.emplace_back();
		cin >> vec[i].name;
		vec[i].pop = 5;
		vec[i].T = 25;
		vec[i].W = 25;
	}
	
	//ゲームの回数を設定する
	cout << "Please set the number of game rounds." << endl;
	cin >> rounds;
	rounds = check2(rounds);

	//プレイヤーはそれぞれ動物の種類（食性）を選択する
	for (int i = 0; i < num; i++) {
		cout << "Please enter animal type of " << vec[i].name << endl;
		if (i == 0) cout << "Enter 1 for generalist, enter 2 for specialist-browsers, enter 3 for specialist-grazers" << endl;
		cin >> animaltype;
		vec[i].type = check3(animaltype);
		if (animaltype == 2)sb += 1;//specialist-browsersの数
		if (animaltype == 3)sg += 1;//specialist-grazersの数
	}

	//環境初期条件の設定
	int Temperature = 25;
	int Wateriness = 25;
	int grazing = 50;
	int browsing = 50;
	int Food = num * 10;
	float totalg = 0;//grazing
	float totalb = 0;//browsing
	int trait = 0;

	//ゲーム本体 
	for (int j = 1; j <= rounds; j++) {
			cout << endl << "Year "<< j << endl;
			cout << "In this year, the Temperture is " << Temperature << ", the wateriness is " << Wateriness <<
				".The environment of this year is " << grazing << "% grazing and " << browsing << "% browsing." << endl;
			cout << "A total of " << Food << " food is available." << endl;

			for (int i = 0; i < num; i++) {//比例の計算
				vec[i].adap = adaptivenesscalculate(vec[i].T, Temperature, vec[i].W, Wateriness);
				//cout << vec[i].name << "  " << vec[i].adap <<vec[i].pop << endl;検査用
				if (vec[i].type == 1) {
					totalg += (float)vec[i].adap * vec[i].pop / 2;
					//cout <<"1   " << totalg;検査用
					totalb += (float)vec[i].adap * vec[i].pop / 2;
					//cout << "   1   " << totalb;検査用
				}
				if (vec[i].type == 2)totalb += vec[i].adap * vec[i].pop;
				else if (vec[i].type == 3)totalg += vec[i].adap * vec[i].pop;
			}

			//cout << "totalb" << totalb << "    totalg" << totalg << endl;検査用

			for (int i = 0; i < num; i++) {
				vec[i].food = foodcalculate(vec[i].type, vec[i].adap, vec[i].pop, sg, sb, Food, totalg, totalb, grazing, browsing);
				cout << vec[i].name << " have a population of " << vec[i].pop << ", gets " << vec[i].food << " food. ";
				cout << "Your best temperature is " << vec[i].T << ", best wateriness is " << vec[i].W << ". " << endl;
			}

			cout << endl << "Eating..." << endl << endl;

			for (int i = 0; i < num; i++) {
				vec[i].food = vec[i].food - vec[i].pop;
				if (vec[i].food < 0) {//食べ物が足りない場合、動物が死ぬ。
					cout << endl << vec[i].name << endl << endl;
					vec[i].pop = vec[i].pop + vec[i].food;

					if (vec[i].pop == 0) {//絶滅したら、game over
						cout << vec[i].name << " extincet.Game over. " << endl;
						num = 0;
						rounds = 0;
					}
					else {
						cout << "OH NO! " << vec[i].name << "don't have enough food for all individuals! The population of " << vec[i].name << " become " << vec[i].pop << endl;
						vec[i].food = 0;
					}
				}
				else if (vec[i].food == 0) {
					cout << endl << vec[i].name << endl << endl;
					cout << vec[i].name << " have just enough food for this year." << vec[i].name << " don’t have any left-over food for adaptation." << endl;
				}
				else {
					cout << endl << vec[i].name << endl << endl;
					cout << "Congratulations! " << vec[i].name << " have " << vec[i].food << " left-over to spend on the adaptation." << endl;
					cout << "Please enter the number of the trait that you want to add to your animal." << endl;
					cout << "Enter 0 to see the traits table again, 20 to produce a new organism, enter 21 to sacrifice 1 individual, 22 to end the adaptation." << endl;
					Adaptation(&vec[i].T, &vec[i].W, &vec[i].food, &vec[i].pop);
					if (vec[i].pop == 0) {//絶滅したら、game over 新改的内容，当一方为零时宣布灭绝，游戏结束。
						cout << vec[i].name << " extincet.Game over. " << endl;
						num = 0;
						rounds = 0;
					}
				}
			}
			//環境条件の変換
			Temperature = Dieroll1(Temperature);
		    Wateriness = Dieroll1(Wateriness);

			grazing = Dieroll2();
			browsing = 100 - grazing;
			totalg = 0;//grazing
			totalb = 0;//browsing
			
		}
	
	while(num != 0)
	{
		//勝敗の判断
		int max = 0;
		int count = 0;
		vector<int> win;
		vector<int> pop;

		for (int k = 0; k < num; k++) pop.push_back(vec[k].pop);
		auto maxIter = max_element(pop.cbegin(), pop.cend());
		max = *maxIter;//最大値を探す


		for (int l = 0; l < num; l++) {
			if (max == vec[l].pop) count += 1;
		}//最大値と同じ数値を探す

		if (count == num) cout << endl << "The game ended in a draw." << endl;//すべての値と最大値と同じなら、ドローである。
		else {
			for (int m = 0; m < num; m++) {
				if (max == vec[m].pop) cout << vec[m].name << " have a population of "<< vec[m].pop ;
			}
			cout << ", win this game. Congratulations!" << endl;
		}
		break;
	}
}