#include <iostream>
#include <string>
using namespace std;

int k;

struct Time {
	int h;
	int m;
};

enum Train_Type{Пассажирский, Товарный, Ремонтный};

struct Train {

	string route_name;
	string depatrute_point;
	string arrival_point;
	Time departure_time;
	Time arrival_time;
	int number_of_cars;
	Train_Type type;

};

Train trains[20];
Train tourist[20];

// Функция для отбора поезка по его типу 
void reassigned(const Train orig[], Train nowel[], Train_Type type) {
	for (int i = 0; i < 20; i++) {
		if (orig[i].type == type) {
			nowel[k] = orig[i];
			k++;
		}
	}
}

// Функция для сортировки поездов по пункту отправления
void sort_name(Train name[]) {
	for (int i = 0; i < k - 1; i++) {
		for (int n = k - 1; n > i; n--) {
			if (name[n - 1].depatrute_point > name[n].depatrute_point) {
				Train a = name[n - 1];
				name[n - 1] = name[n];
				name[n] = a;
			}
		}
	}
}

// Фуекция для вывода 3-х самых коротких пассажирских поездов
void short_number(Train name[]) {
	for (int i = 0; i < k - 1; i++) {
		for (int n = k - 1; n > i; n--) {
			if (name[n - 1].number_of_cars > name[n].number_of_cars) {
				Train a = name[n - 1];
				name[n - 1] = name[n];
				name[n] = a;
			}
		}
	}
	cout << "\n3 самых коротких поезда:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << tourist[i].route_name << ": " << tourist[i].number_of_cars << " Вагонов" << endl;
	}
}

// Функция для опредения типа поезда
void tip(Train which[], int i) {
	switch (i) {
		case Train_Type::Пассажирский: cout << "Пассажирский"; break;
		case Train_Type::Товарный: cout << "Товарный"; break;
		case Train_Type::Ремонтный: cout << "Ремонтный"; break;
	}
}

// Функция для вывода определённого поезда
void recap(Train name[]) {

	int t;
	cout << "\nВведите номер поезда:" << endl;
	cin >> t;
	t--;

	cout << "\nНазвание маршрута: " << name[t].route_name << endl;
	cout << "Пункт Отправления: " << name[t].depatrute_point << endl;
	cout << "Пункт прибытия: " << name[t].arrival_point << endl;
	cout << "Время отправления: " << name[t].departure_time.h << ":" << name[t].departure_time.m << endl;
	cout << "Время прибытия: " << name[t].arrival_time.h << ":" << name[t].arrival_time.m << endl;
	cout << "Количестов вагонов: " << name[t].number_of_cars << endl;
	cout << "Тип поезда: ";  tip(name, name[t].type); cout << endl;
}

// Функция для изменения маршрута
void change_point(Train cha[]) {
	int l;
	string dep, arr;

	cout << "\nКакой номер маршрута изменить?" << endl;
	cout << "Введите номер маршрута от 1 до 20" << endl;
	cin >> l;
	cout << "\nВведите пункт отправления:" << endl;
	cin >> dep;
	cout << "Введите пункт назначения:" << endl;
	cin >> arr;

	l--;
	cout << "\nПоезд номер " << l + 1 << endl;
	cout << "Маршрут " << cha[l].depatrute_point << " - " << cha[l].arrival_point;
	cha[l].depatrute_point = dep;
	cha[l].arrival_point = arr;
	cout << " изменён на " << cha[l].depatrute_point << " - " << cha[l].arrival_point << endl;
}

// Функция для вывода 
void outpute_of_name(Train output[]) {
	for (int i = 0; i < k; i++) {
		cout << output[i].depatrute_point << endl;
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	trains[0] = { "Южный_экспресс", "Челябинск", "Екатеринбург", {6, 30}, {9, 15}, 10, Train_Type::Пассажирский};
	trains[1] = {"Северный_груз", "Екатеринбург", "Тюмень", {4, 50}, {10, 40}, 45, Train_Type::Товарный};
	trains[2] = {"Башкирский_маршрут", "Уфа", "Челябинск", {12, 10}, {16, 00}, 8, Train_Type::Пассажирский};
	trains[3] = {"Степной_груз", "Оренбург", "Самара", {2, 20}, {6, 45}, 38, Train_Type::Товарный};
	trains[4] = {"Уральский_экспресс", "Пермь", "Екатеринбург", {7, 00}, {10, 10}, 12, Train_Type::Пассажирский};
	trains[5] = {"Восточный_ремонт", "Курган", "Челябинск", {22, 30}, {3, 15}, 6, Train_Type::Ремонтный};
	trains[6] = {"Магнитный_путь", "Магнитогорск", "Уфа", {5, 40}, {10, 20}, 10, Train_Type::Пассажирский};
	trains[7] = {"ТрансУрал_груз", "Екатеринбург", "Челябинск", {0, 10}, {5, 35}, 50, Train_Type::Товарный};
	trains[8] = {"Пригородный_рейс-1", "Челябинск", "Миасс", {8, 00}, {9, 40}, 6, Train_Type::Пассажирский};
	trains[9] = {"Пригородный_рейс-2", "Миасс", "Златоуст", {10, 00}, {11, 00}, 5, Train_Type::Пассажирский};
	trains[10] = {"Ремонтный_состав-5", "Самара", "Саратов", {21, 15}, {1, 45}, 4, Train_Type::Ремонтный};
	trains[11] = {"Транспорт_угля", "Кемерово", "Новосибирск", {3, 50}, {8, 55}, 60, Train_Type::Товарный};
	trains[12] = {"Туристический_маршрут-Урал", "Екатеринбург", "Чусовой", {9, 00}, {12, 00}, 7, Train_Type::Пассажирский};
	trains[13] = {"Северный_экспресс", "Тюмень", "Омск", {7, 20}, {12, 30}, 10, Train_Type::Пассажирский};
	trains[14] = {"Грузметалл", "Магнитогорск", "НижнийТагил", {15, 00}, {22, 00}, 55, Train_Type::Товарный};
	trains[15] = {"Сервисный_маршрут", "Пермь", "Березники", {23, 10}, {1, 00}, 3, Train_Type::Ремонтный};
	trains[16] = {"Горный_экспресс", "Златоуст", "Усть-Катав", {14, 00}, {16, 15}, 8, Train_Type::Пассажирский};
	trains[17] = {"Сибирский_груз", "Новосибирск", "Красноярск", {2, 40}, {9, 20}, 48, Train_Type::Товарный};
	trains[18] = {"Тестовая_проверка-3", "Екатеринбург", "Пермь", {11, 30}, {15, 10}, 5, Train_Type::Ремонтный};
	trains[19] = {"Южноуральский_путь", "Челябинск", "Оренбург", {18, 20}, {23, 10}, 9, Train_Type::Пассажирский};

	// Указываем сначало старую структуру, потом новую, затем по какому типу вагона из старого добавить в новый
	reassigned (trains, tourist, Train_Type::Пассажирский);

	cout << "До сортировки:" << endl;
	outpute_of_name(tourist);

	// Указываем стуктуру, которую хотим отсортировать, она будет отсортирована по пункту отправления вагонов
	sort_name(tourist);

	cout << "\nПосле сортировки:" << endl;
	outpute_of_name(tourist);

	// Указываем какой тип поезда вывести
	recap(tourist);

	// Указываем какие 3 самых коротких поезда вывести
	short_number(tourist);

	// Указываем для какого типа поезда изменить маршрут
	change_point(trains);
}
