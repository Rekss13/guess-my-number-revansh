#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_CTYPE,"rus");
    cout << "\tДобро пожаловать в Угадай Число: Реванш\n\n";
    int secretNumber;
    int min = 1;
    int max = 100;
    cout << "Введите число, которое угадывает компьютер (от " << min << " до " << max << "): ";
    cin >> secretNumber;

    while (secretNumber < 1 || secretNumber > 100) {
        cout << "\n\n! Введенный номер не соответствует запрошенному диапазону.\n\n";
        cout << "Попробуй еще раз: ";
        cin >> secretNumber;
    }

    cout << "\n--------------------------------------------------\n\n";

    int guess;
    int tries = 0;
    srand(static_cast<unsigned int>(time(0)));
    do {
        if (min == max) {
            cout << "Компьютер ввел номер: " << guess << endl;
            guess = min;
        }
        else {
            cout << "Генерация числа (от " << min << " до " << max <<")\n\n";
            guess = rand() % max + min;
            if (guess > max) guess = max;
            cout << "Компьютер ввел номер: " << guess << endl;
            if (guess > secretNumber) {
                cout << "\nСлишком много!\n\n";
                if (guess <= max) max = guess - 1;
            }
            else if (guess < secretNumber) {
                cout << "\nСлишком мало!\n\n";
                if (guess >= min) min = guess + 1;
            }
        }
        ++tries;
    } while (guess != secretNumber);

    cout << "\n--------------------------------------------------\n";
    cout << "\nКомпьютер подобрал номер за " << tries << " попыток.\n\n";
    cout << "\tИГРА ОКОНЧЕНА\n";

    return 0;
}