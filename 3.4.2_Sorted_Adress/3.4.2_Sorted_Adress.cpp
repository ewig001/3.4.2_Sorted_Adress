#include <iostream>
#include <string>
#include <fstream>
//#include <windows.h> 

class Adress {
public:
	std::string city = "";
	std::string street = "";
	int house = 1;
	int appartment = 1;
	Adress() {
		city = "1";
		street = "1";
		house = 1;
		appartment = 1;
	}
	Adress(std::string city, std::string street, int house, int appartment) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->appartment = appartment;
	};
	void print_adress() {
		std::cout << city << " " << street << " " << house << " " << appartment << std::endl;
	}

	std::string output_adress(Adress* arr, int i) {

		std::string str = "";

		str += arr[i].city + ", ";
		str += arr[i].street + ", ";
		str += std::to_string(arr[i].house) + ", ";
		str += std::to_string(arr[i].appartment) + "\n";
		return str;
	}
};

void sort(Adress* arr, int size) {
	Adress temp("1", "1", 1, 1);
	bool swapped = false;
	do {
		swapped = false;
		for (int i = size - 1; i > 0; i--) {
			if (arr[i - 1].city > arr[i].city) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251); // для проверки решения в ОС Windows
	//SetConsoleOutputCP(1251); // для проверки решения в ОС Windows

	int size = 0;
	std::string str;
	std::ifstream fin("in.txt");

	if (fin.is_open()) {
		fin >> size;

		Adress* arr = new Adress[size]{};

		while (!fin.eof()) {

			for (int i = 0; i < size; i++) {
				fin >> arr[i].city;
				fin >> arr[i].street;
				fin >> arr[i].house;
				fin >> arr[i].appartment;
			}
		}
		sort(arr, size);
		std::ofstream fout("out.txt");
		if (fout.is_open()) {
			str = std::to_string(size) + "\n";
			for (int i = 0; i < size; i++) {
				str += arr[i].output_adress(arr, i);
			}
			fout << str;
		}
		else {
			std::cout << "Не получилось открыть файл!" << std::endl;
		}
		fout.close();
	}
	else {
		std::cout << "Не получилось открыть файл!" << std::endl;
	}

	fin.close();

	return 0;
}