#include <iostream>
#include <string>

using namespace std;

class Book {

private:
    string author;
    string name;
    bool isAvailable;
    int borrowTime;
    string userName;


public:

    Book(string author, string name) : author(author), name(name), isAvailable(true), userName(""), borrowTime(0) {}

    void borrow(string userName, int borrowTime) {
        if (isAvailable) {
            this->userName = userName;
            this->borrowTime = borrowTime;
            isAvailable = false;
            cout << "Book \"" << name << "\" has been borrowed by " << userName << ".\n";
        }
        else {
            cout << "Sorry, the book \"" << name << "\" is not available.\n";
        }
    }

    void returnBook(int returnTime, bool isDamaged) {
        if (!isAvailable) {
            isAvailable = true;
            bool isLate = returnTime > borrowTime;
            int dailyFee = 30;
            int damageFee = 50;
            int difference = returnTime - borrowTime;
            int total;

            if (isDamaged && isLate) {
                total = dailyFee * difference + damageFee;
                cout << "Book \"" << name << "\" has returned late and damaged" << endl;
                cout << "You have to pay " << total << " Gel" << endl;
                cout << endl;
            }
            else if (!isDamaged && !isLate) {
                cout << "Book \"" << name << "\" has returned on time and undamaged" << endl;
            }
            else if (isDamaged && !isLate) {
                cout << "Book \"" << name << "\" has returned on time and damaged" << endl;
                cout << "You have to pay " << damageFee << " Gel" << endl;
                cout << endl;
            }
            else {
                cout << "Book \"" << name << "\" has returned late and undamaged" << endl;
                cout << "You have to pay " << dailyFee * difference << " Gel" << endl;
            }
        }
        else {
            cout << "The book \"" << name << "\" is already in the library.\n";
        }
    }

    void bookStatus() {
        cout << "Book \"" << name << "\" by " << author;
        if (isAvailable)
            cout << " is available.\n";
        else
            cout << " is borrowed by " << userName << ".\n";
    }
};

int main() {

    Book book1("Iakob Gogebashvili", "Dedaena");
    Book book2("Vaja-Fshavela", "Aluda Qetelauri");
    Book book3("Shota Rustaveli", "Vefxistyaosani");
    Book book4("Iakob Curtaveli", "Shushanikis Wameba");

    book1.borrow("Giorgi", 7);
    book2.borrow("Nino", 7);
    book3.borrow("Mate", 7);
    book4.borrow("Malxazi", 7);

    cout << endl;

    book1.bookStatus();
    book2.bookStatus();
    book3.bookStatus();
    book4.bookStatus();

    cout << endl;

    book1.returnBook(8, true);
    book2.returnBook(6, false);
    book3.returnBook(6, true);
    book4.returnBook(8, false);

    cout << endl;

    book1.bookStatus();
    book2.bookStatus();
    book3.bookStatus();
    book4.bookStatus();

    return 0;
}
