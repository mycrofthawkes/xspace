// lesson_03_input_and_arithmetic.cpp

// Урок 3: Ввод данных и арифметические операции.cpp

#include <iostream>

int main()
{
    // {} инициализирует числовую переменную нулём.
    double length{};
    double width{};

    std::cout << "Enter rectangle length and width: ";

    // std::cin читает текст из стандартного потока ввода
    // и преобразует его в тип соответствующей переменной.
    //
    // Например, ввод:
    // 5.5 3
    //
    // преобразуется в два значения типа double.
    std::cin >> length >> width;

    const double area{length * width};
    const double perimeter{2.0 * (length + width)};

    std::cout << "Area: " << area << '\n';
    std::cout << "Perimeter: " << perimeter << '\n';

    // Основные арифметические операторы:
    //
    // +  сложение
    // -  вычитание
    // *  умножение
    // /  деление
    // %  остаток от целочисленного деления

    int total_seconds{};

    std::cout << "Enter total number of seconds: ";
    std::cin >> total_seconds;

    constexpr int seconds_per_minute{60};

    // При делении двух int получается int.
    // Дробная часть не округляется, а отбрасывается.
    const int minutes{total_seconds / seconds_per_minute};

    // % возвращает остаток от целочисленного деления.
    const int remaining_seconds{total_seconds % seconds_per_minute};

    std::cout << total_seconds << " seconds = "
              << minutes << " minute(s) and "
              << remaining_seconds << " second(s)\n";

    /*
    Пример:

        total_seconds = 135

        135 / 60 = 2
        135 % 60 = 15

        Результат: 2 минуты и 15 секунд.


    ---------------- КАК ДЕЛАТЬ НЕ НАДО ----------------

    int first{5};
    int second{2};

    double result{first / second};

    Сначала выполняется целочисленное деление:

        5 / 2 = 2

    И только затем число 2 превращается в double:

        result = 2.0

    Потерянная дробная часть уже не восстановится.


    ---------------- КАК ДЕЛАТЬ ЛУЧШЕ ------------------

    int first{5};
    int second{2};

    double result{static_cast<double>(first) / second};

    static_cast<double> создаёт вещественное представление first.
    Теперь выполняется вещественное деление:

        5.0 / 2 = 2.5


    ---------------- ПРИОРИТЕТ ОПЕРАЦИЙ ----------------

    double wrong_average{first + second / 2.0};

    Деление имеет более высокий приоритет:

        first + (second / 2.0)

    Правильно:

    double average{(first + second) / 2.0};

    Скобки не только меняют порядок вычислений, но и явно
    показывают намерение программиста.
    */

/*
Домашнее задание

1. Напиши программу, которая запрашивает три значения типа double, 
вычисляет их среднее арифметическое и выводит результат.
Не забудь скобки и деление на 3.0.

2. Запроси у пользователя общее количество минут типа int. 
Преобразуй его в часы и оставшиеся минуты с помощью / и %.
*/

    double first_value{};
    double second_value{};
    double third_value{};

    std::cout << "Enter three values: ";
    std::cin >> first_value >> second_value >> third_value;

    const double average{
        (first_value + second_value + third_value) / 3.0
    };
    
    std::cout << "Average: " << average << '\n';

    int total_minutes{};
    constexpr int minutes_per_hour{60};

    std::cout << "Enter total minutes: ";
    std::cin >> total_minutes;

    const int hours{total_minutes / minutes_per_hour};
    const int remaining_minutes{total_minutes % minutes_per_hour};
    
    std::cout << total_minutes << " minutes = " 
              << hours << " hour(s) and " 
              << remaining_minutes << " minute(s).\n";  

    return 0;
}

/*
Что происходит «под капотом»:

Когда пользователь вводит:

    5.5 3

терминал передаёт программе последовательность символов:

    '5' '.' '5' ' ' '3'

std::cin анализирует эти символы и преобразует их в двоичные
значения типа double.

Если вместо числа ввести слово, преобразование завершится неудачей,
а поток перейдёт в состояние ошибки. Пока вводи корректные данные:
обработку ошибок изучим после условных конструкций.

constexpr и const:

    const double area{length * width};

Значение вычисляется во время выполнения, потому что length и width
вводит пользователь.

    constexpr int seconds_per_minute{60};

Значение известно уже во время компиляции. constexpr выражает более
сильное требование: объект должен иметь константное выражение.
*/

