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
            cerr << "������: ���������� ��������� ������� �� ����� ��������� ����� ���������� ����." << endl;
        }
    }

    double calculateUnsoldTicket() const {
        int unsold_tickets = total_seats - sold_tickets;
        return unsold_tickets * ticket_price;
    }

    void displayInfo() const {
        cout << "�������: " << station_name << endl;
        cout << "��������� ������: " << ticket_price << endl;
        cout << "����� ����: " << total_seats << endl;
        cout << "������� �������: " << sold_tickets << endl;
        cout << "����������� ������: " << (total_seats - sold_tickets) << endl;
        cout << "����� ��������� ����������� �������: " << calculateUnsoldTicket() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string station_name;
    double ticket_price;
    int total_seats;

    cout << "������� �������� �������: ";
    getline(cin, station_name);

    do {
        cout << "������� ��������� ������: ";
        cin >> ticket_price;

        if (ticket_price < 0) {
            cout << "������: ��������� ������ �� ����� ���� �������������. ���������� �����." << endl;
        }
    } while (ticket_price < 0); 

    do {
        cout << "������� ����� ���������� ����: ";
        cin >> total_seats;

        if (total_seats < 0) {
            cout << "������: ���������� ���� �� ����� ���� �������������. ���������� �����." << endl;
        }
    } while (total_seats < 0);

    Station station(station_name, ticket_price, total_seats);

    int sold_tickets;
    do {
        cout << "������� ���������� ��������� �������: ";
        cin >> sold_tickets;

        if (sold_tickets < 0) {
            cout << "������: ���������� ��������� ������� �� ����� ���� �������������. ���������� �����." << endl;
        }
        else if (sold_tickets > total_seats) {
            cout << "������: ���������� ��������� ������� �� ����� ��������� ����� ���������� ����. ���������� �����." << endl;
        }
    } while (sold_tickets < 0 || sold_tickets > total_seats);

    station.setSoldTickets(sold_tickets);

    station.displayInfo();

    return 0;
}