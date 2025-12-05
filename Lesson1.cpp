#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main()
{
	int x;
	std::vector<int> data = { 1,2,3,4,5 };
	int a = data[0];
	int b = data[4];
	data[2] = -3;
	std::cout << data.size() << "\n";

	std::cout << data.front() << "\n";
	std::cout << data.back() << "\n";

	

	std::vector <int>data1 = {1,2};
	std::cout << data1.size() << "\t" << data1.capacity() << "\n";

	data1.push_back(3);
	std::cout << data1.size() << "\t" << data1.capacity() << "\n";

	data1.push_back(4);
	std::cout << data1.size() << "\t" << data1.capacity() << "\n";

	data1.push_back(5);
	std::cout << data1.size() << "\t" << data1.capacity()<<"\n";

	std::vector<std::string> words;

	size_t words_count;
	std::cin >> words_count;

	words.reserve(words_count);

	for (size_t i = 0; i != words_count; ++i) {
		std::string word;
		std::cin >> word;

		words.push_back(word);
	}
	// Многомерный векторы
	size_t m, n;
	std::cin >> m >> n;

	std::vector<std::vector<int>>matrix(m, std::vector<int>(n));

	for (size_t i = 0; i != m; ++i) {
		for (size_t j = 0; j != n; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	for (size_t i = 0; i != m; ++i) 
	{
		for (size_t j = 0; j != n; ++j) 
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::vector<int> data2 = { 3,1,4,1,5,9,2,6 };
	//Сортировка диапазона вектора от начала до конца
	std::sort(data2.begin(), data2.end());
	// Обратная сортировка 
	std::sort(data2.rbegin(), data2.rend());
	// Элегантная сортровка c++20
	//std::ranges::sort(data2);
	std::string s = "Some string";

	s += ' ';
	s += "functions";
	std::cout << s << "\n";
	//выделение подстроки
	// подстрока "string" из 6 символов начиная с 5-й позиций
	std::string sub1 = s.substr(5, 6);
	//подстрока "functions" с 12-й позиций и до конца 
	std::string sub2 = s.substr(12);

	// поиск символов или подстроки
	size_t pos1 = s.find(' ');
	size_t pos2 = s.find(' ', pos1 + 1);
	size_t pos3 = s.find("str");
	size_t pos4 = s.find("#");

	std::string s1 = "Some string functions";
	// вставка подстроки
	s1.insert(5, "std::");
	std::cout << s << "\n";
	// замена указанного диапазона на новую подстроку
	s1.replace(0, 4, "Special");
	std::cout << s << "\n";
	// удаление подстроки 
	s1.erase(8, 5);

	std::string s2;
	std::getline(std::cin, s2);
	// Проверка префикса и суффикса строк
	/*
	* if (s2.starts_with("hello")) {
		std::cout << "Greeting\n";
	}

	if (s2.ends_with("bye")) {
		std::cout << "Farewell\n";
	}
	*/
	
}
