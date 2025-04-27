#include <iostream>
#include <iomanip>

using namespace std;

bool nm3(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int nm4(int n)
{
    if (n <= 0) return 1;
    return n * nm4(n - 1);
}

int nm5(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nm10(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void nm11(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

double nm14(int a, int b) {
    double array = (a + b) / 2;

    return static_cast<double>(array);
}

int nm15(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return nm15(n - 1) + nm15(n - 2);
    }
}

double nm16(int* arr, int size) {
    if (size <= 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

bool Vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

bool Consonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && !Vowel(c));
}




int main()
{
    setlocale(LC_ALL, "Russian");
    int nm_all{};
    cout << "Введите номер задачи\n";
    cin >> nm_all;

    switch (nm_all)
    {
    case 1:
    {
        double numders{};
        cout << "Введите число с плавающей запятой\n";
        cin >> numders;

        cout << scientific << setprecision(6) << numders << endl;
    }   break;

    case 2:
    {
        int a{};
        cout << "Введите число для проверки на чётность\n";
        cin >> a;

        if (a % 2 == 0) cout << "перед нами чётное число" << endl;
        else cout << "перед нами не чётное число" << endl;
        break;
    }

    case 3:
    {
        int a{};
        cout << "Введите число для проверки на простое число \n";
        cin >> a;

        if (nm3(a)) {
            cout << a << " является простым числом" << endl;
        }
        else {
            cout << a << " не является простым числом" << endl;
        }

    }   break;

    case 4:
    {
        int a{};
        cout << "Введите число для вычисления факториала\n";
        cin >> a;
        cout << "Факториал числа: " << nm4(a);


    }   break;

    case 5:
    {
        int a{}, x{}, rez{};
        cout << "Введите первое \n" << endl;
        cin >> a;
        cout << "Введите второе \n" << endl;
        cin >> x;

        rez = nm5(a, x);
        cout << "НОД чисел " << a << " и " << x << " равен " << rez << endl;
    }   break;

    case 6:
    {
        cout << "Таблица умножения \n";
        cout << "---------------------------------------------------------------------------\n";

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                cout << i * j << "\t";
            }
            cout << endl;
        }
    }   break;

    case 7:
    {
        int a{}, sum{};
        cout << "Введите N" << endl;
        cin >> a;

        for (int i = 1; i <= a; i++) {
            sum += i;
            ++i;
        }

        cout << "Cумма чисел от 1 до N: " << sum;
    }   break;

    case 8:
    {
        int a{}, x{};
        char oper{};
        cout << "Введите первое число" << endl;
        cin >> a;
        cout << "Введите оператор (+,-,*,/)" << endl;
        cin >> oper;
        cout << "Введите второе число" << endl;
        cin >> x;


        switch (oper) {
        case '+':
            cout << "Результат: " << (a + x) << endl;
            break;
        case '-':
            cout << "Результат: " << (a - x) << endl;
            break;
        case '*':
            cout << "Результат: " << (a * x) << endl;
            break;
        case '/':
            if (x != 0) {
                cout << "Результат: " << (a / x) << endl;
            }
            else {
                cout << "Ошибка: Деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Неверный оператор!" << endl;
        }

    }   break;

    case 9:
    {
        int a{};
        cout << "Введите число дня недели" << endl;
        cin >> a;

        switch (a) {
        case 1:
            cout << "День недели - Понидельник" << endl;
            break;
        case 2:
            cout << "День недели - Вторник" << endl;
            break;
        case 3:
            cout << "День недели - Среда" << endl;
            break;
        case 4:
            cout << "День недели - Четверг" << endl;
            break;
        case 5:
            cout << "День недели - Пятница" << endl;
            break;
        case 6:
            cout << "День недели - Суббота" << endl;
            break;
        case 7:
            cout << "День недели - Воскресенье" << endl;
            break;
        default:
            cout << "Неверный ввод значения дня недели" << endl;
        }

    }   break;

    case 10:
    {
        int size;
        cout << "Введите размер массива" << endl;
        cin >> size;

        int* arr = new int[size];

        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        cout << "Ваш массив: " << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        int totalSum = nm10(arr, size);
        cout << "\n" << "Сумма всех элементов массива:\n" << totalSum << endl;

    }   break;

    case 11:
    {
        int size;
        cout << "Введите размер массива" << endl;
        cin >> size;

        int* arr = new int[size];

        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        cout << "Ваш массив: " << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        nm11(arr, size);

        cout << "Массив после реверсирования:" << std::endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

    }   break;

    case 12:
    {
        int size;
        cout << "Введите размер массива" << endl;
        cin >> size;

        int* arr = new int[size];

        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        cout << "Ваш массив: " << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int min = arr[0];
        int max = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        cout << "Минимальное значение: " << min << endl;
        cout << "Максимальное значение: " << max << endl;

    }   break;

    case 13:
    {
        int size;

        cout << "Введите количество строк: ";
        cin >> size;

        cin.ignore();
        char** arr = new char* [size];

        cout << "Введите строки:" << endl;
        for (int i = 0; i < size; i++) {
            arr[i] = new char[100];
            cin.get(arr[i], 100);
            cin.ignore();
        }


        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (strcmp(arr[j], arr[j + 1]) > 0) {
                    char* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "Отсортированные строки:" << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }

    }   break;


    case 14:
    {
        int a{}, x{};
        double rez{};
        cout << "Введите первое" << endl;
        cin >> a;
        cout << "Введите второе" << endl;
        cin >> x;

        rez = nm14(a, x);

        cout << "Средннее значение " << rez << endl;

    }   break;

    case 15:
    {
        int n;

        cout << "Введите номер числа Фибоначчи:";
        cin >> n;

        if (n < 0) {
            cout << "Пожалуйста, введите неотрицательное число" << endl;
        }
        else {
            cout << "Число Фибоначчи под номером " << n << " равно " << nm15(n) << endl;
        }
    }   break;

    case 16:
    {
        int size;

        cout << "Введите размер массива: " << endl;
        cin >> size;

        if (size <= 0) {
            cout << "Размер массива должен быть положительным" << endl;
            return 1;
        }

        int* arr = new int[size];

        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        double average = nm16(arr, size);
        cout << "Среднее значение массива: " << average << endl;
    }   break;

    case 17:
    {
        const int MAX_LENGTH = 100;
        char str[MAX_LENGTH];

        cin.ignore();

        cout << "Введите строку: ";
        cin.getline(str, MAX_LENGTH);

        int vowelCount = 0;
        int consonantCount = 0;

        for (int i = 0; str[i] != '\0'; ++i) {
            char c = str[i];
            if (Vowel(c)) {
                vowelCount++;
            }
            else if (Consonant(c)) {
                consonantCount++;
            }
        }

        cout << "Количество гласных букв: " << vowelCount << endl;
        cout << "Количество согласных букв: " << consonantCount << endl;

    }   break;
    default: break;

    }
}