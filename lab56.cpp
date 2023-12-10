#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
	string proizvod;
	string model;
	int numCore;
	int memory;
	int price;
	static int ValueSmartphone;
public:
	//Конструкторы
	Smartphone() {
		numCore = 0;
		memory = 0;
		price = 0;
		ValueSmartphone++;
	};
	Smartphone(string Nameproizvod, string Namemodel, int ValuenumCore, int Valuememory, int Valueprice) {
		proizvod = Nameproizvod;
		model = Namemodel;
		numCore = ValuenumCore;
		memory = Valuememory;
		price = Valueprice;
		ValueSmartphone++;
	};
	Smartphone(const Smartphone& other) {
		proizvod = other.proizvod;
		model = other.model;
		numCore = other.numCore;
		memory = other.memory;
		price = other.price;
		ValueSmartphone++;
	};

	//Геттеры и Сеттеры
	string getProizvod() {
		return proizvod;
	};
	string getModel() {
		return model;
	};
	int getNumCore() {
		return numCore;
	};
	int getMemory() {
		return memory;
	};
	int getPrice() {
		return price;
	};

	void setProizvod(string Nameproizvod) {
		proizvod = Nameproizvod;
	};
	void setModel(string Namemodel) {
		model = Namemodel;
	};
	void setNumCore(int ValueNumCore) {
		numCore = ValueNumCore;
	};
	void setMemory(int ValueMemory) {
		memory = ValueMemory;
	};
	void setPrice(int ValuePrice) {
		price = ValuePrice;
	};

	//Функции
	void information() {

		cout << "Производитель -" << proizvod << endl;
		cout << "Модель -" << model << endl;
		cout << "Кол-во ядер -" << numCore << endl;
		cout << "Память -" << memory << endl;
		cout << "Цена -" << price << endl;
		cout << "..................." << endl;
	}
	static void checkProizvod(Smartphone smartphones[], int t, const string& constProizvod) {
		cout << "Смартфоны от производителя " << constProizvod << endl;
		for (int i = 0; i < t; i++) {
			if (smartphones[i].getProizvod() == constProizvod) {
				smartphones[i].information();
			}
		}
	}
	static void sredPrice(Smartphone smartphones[], int phones) {
		int totalPrices = 0;
		for (int i = 0; i < phones; i++) {
			totalPrices += smartphones[i].getPrice();
		}
		cout << "Средняя стоимость: " << totalPrices / phones << endl;
	}
	static void AllMoreCore(Smartphone smartphones[], int phones, int n) {
		for (int i = 0; i < phones; i++) {
			if (smartphones[i].getNumCore() > n) {
				smartphones[i].information();
			}
		}
	}
};

int Smartphone::ValueSmartphone = 0;
int main() {
	setlocale(LC_ALL, "ru");
	Smartphone smartphones[3] = {
		Smartphone("Sasung", "Iman X", 2, 200, 10000),
		Smartphone("Epple", "Galuxy 100", 3, 300, 5000),
		Smartphone("Siomi", "China9", 4, 400, 2500),
	};

	Smartphone::AllMoreCore(smartphones, 2, 1);

	return 0;
};