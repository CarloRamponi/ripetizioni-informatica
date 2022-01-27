#include <iostream>

using namespace std;

struct Date {
    unsigned short int day;
    unsigned short int month;
    unsigned int year;

    void print() const {
        cout << day << "/" << month << "/" << year;
    }

    void sum(int days) {
        int tmpDays = day + days;
        int tmpMonth = month;
        
        while(tmpDays > 30) {
            tmpMonth += 1;
            tmpDays -= 30;
        }

        while(tmpDays <= 0) {
            tmpMonth -= 1;
            tmpDays += 30;
        }

        while(tmpMonth > 12) {
            year += 1;
            tmpMonth -= 12;
        }

        while(tmpMonth <= 0) {
            year -= 1;
            tmpMonth += 12;
        }

        day = tmpDays;
        month = tmpMonth;
    }

    int difference(const Date &other) const {
        int res = 0;
        res += (year - other.year) * 360;
        res += (month - other.month) * 30;
        res += day - other.day;

        return res;
    }

    bool equals(const Date &other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool isAfter(const Date &other) const {
        return difference(other) > 0;
    }
};

int main() {
    Date date {20, 3, 1999};
    Date today {27, 01, 2022};

    cout << "Date1: ";
    date.print();
    cout << endl;

    cout << "Today: ";
    today.print();
    cout << endl;


    int days = today.difference(date);
    cout << "Number of day elapsed from Date1 to today: " << days << endl;
    cout << "Adding " << days << " days to Date1..." << endl;

    date.sum(days);
    cout << "Updated date1: ";
    date.print();
    cout << endl;

    cout << "Are the two dates equal? ";
    if(date.equals(today)) {
        cout << "Yes." << endl;
    } else {
        cout << "No." << endl;
    }

    cout << "Substracting " << days << " days to Date1..." << endl;
    date.sum(-days);

    cout << "Updated Date1: ";
    date.print();
    cout << endl;

    return 0;
}