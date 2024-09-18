#include <iostream>
#include <string>

using namespace std;
  
class Station {
private:
    string station_name;
    double ticket_price;
    int total_seats;
    int sold_tickets;

public:

    Station(const string& name, double price, int seats)
        : station_name(name), ticket_price(price), total_seats(seats), sold_tickets(0) {}

    void setSoldTickets(int sold) {
        if (sold <= total_seats) {
            sold_tickets = sold;
        }
        else {
            cerr << "Ошибка: количество проданных билетов не может превышать общее количество мест." << endl;
        }
    }

    double calculateUnsoldTicket() const {
        int unsold_tickets = total_seats - sold_tickets;
        return unsold_tickets * ticket_price;
    }

    void displayInfo() const {
        cout << "Станция: " << station_name << endl;
        cout << "Стоимость билета: " << ticket_price << endl;
        cout << "Всего мест: " << total_seats << endl;
        cout << "Продано билетов: " << sold_tickets << endl;
        cout << "Непроданные билеты: " << (total_seats - sold_tickets) << endl;
        cout << "Общая стоимость непроданных билетов: " << calculateUnsoldTicket() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string station_name;
    double ticket_price;
    int total_seats;

    cout << "Введите название станции: ";
    getline(cin, station_name);

    do {
        cout << "Введите стоимость билета: ";
        cin >> ticket_price;

        if (ticket_price < 0) {
            cout << "Ошибка: стоимость билета не может быть отрицательной. Попробуйте снова." << endl;
        }
    } while (ticket_price < 0); 

    do {
        cout << "Введите общее количество мест: ";
        cin >> total_seats;

        if (total_seats < 0) {
            cout << "Ошибка: количество мест не может быть отрицательным. Попробуйте снова." << endl;
        }
    } while (total_seats < 0);

    Station station(station_name, ticket_price, total_seats);

    int sold_tickets;
    do {
        cout << "Введите количество проданных билетов: ";
        cin >> sold_tickets;

        if (sold_tickets < 0) {
            cout << "Ошибка: количество проданных билетов не может быть отрицательным. Попробуйте снова." << endl;
        }
        else if (sold_tickets > total_seats) {
            cout << "Ошибка: количество проданных билетов не может превышать общее количество мест. Попробуйте снова." << endl;
        }
    } while (sold_tickets < 0 || sold_tickets > total_seats);

    station.setSoldTickets(sold_tickets);

    station.displayInfo();

    return 0;
}