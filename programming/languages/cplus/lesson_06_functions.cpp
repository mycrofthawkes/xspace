// lesson_06_functions.cpp

// Урок 6: Функции, параметры и возвращаемые значения.cpp

#include <iostream>

// Объявления функций сообщают компилятору:
// имя, тип результата и типы параметров.
//
// Реализации этих функций находятся после main.
int add(int left, int right);
bool is_even(int value);
void print_number_report(int value);
int larger_of(int first, int second);
void print_multiplication_table(int number);

int main()
{
    int first{};
    int second{};

    std::cout << "Enter two integers: ";

    if (!(std::cin >> first >> second))
    {
        std::cerr << "Error: input must contain two integers.\n";
        return 1;
    }

    // first и second называются аргументами.
    // left и right в функции add называются параметрами.
    const int sum{add(first, second)};

    std::cout << first << " + " << second << " = " << sum << '\n';

    // Результат функции можно использовать прямо в условии.
    if (is_even(sum))
    {
        std::cout << "The sum is even.\n";
    }
    else
    {
        std::cout << "The sum is odd.\n";
    }

    // Функция типа void выполняет действие,
    // но не возвращает значение.
    print_number_report(sum);

    /*
    Домашнее задание

    1. Напиши функцию:

           int larger_of(int first, int second);

       Она должна вернуть большее из двух целых чисел.

       Добавь объявление функции над main, реализацию после main,
       а вызов — здесь, перед return 0.

       Запроси у пользователя два целых числа и выведи результат.

    2. Напиши функцию:

           void print_multiplication_table(int number);

       Она должна с помощью цикла for вывести таблицу умножения
       переданного числа от 1 до 10.

       Функция самостоятельно ничего не считывает через std::cin:
       число получает main и передаёт его через параметр.
    */

    // Здесь размести ввод данных и вызовы домашних функций.
    int current_first{};
    int current_second{};

    std::cout << "Enter two integers: ";

    if (!(std::cin >> current_first >> current_second))
    {
        std::cerr << "Error: input must contain two integers.\n";
        return 1;
    }

    std::cout << "larger number is: " << larger_of(current_first, current_second) << '\n'; 

    print_multiplication_table(current_first);

    return 0;
}

// Определение функции.
//
// int перед именем означает, что функция возвращает int.
int add(int left, int right)
{
    return left + right;
}

bool is_even(int value)
{
    return value % 2 == 0;
}

// void означает отсутствие возвращаемого значения.
void print_number_report(int value)
{
    std::cout << "Number report:\n";
    std::cout << "Value: " << value << '\n';

    if (value > 0)
    {
        std::cout << "Sign: positive\n";
    }
    else if (value < 0)
    {
        std::cout << "Sign: negative\n";
    }
    else
    {
        std::cout << "Sign: zero\n";
    }
}

int larger_of(int first, int second)
{
    if (first >= second)
    {
        return first;
    }
    return second;
}

void print_multiplication_table(int number)
{
    for (int i{1}; i <= 10; ++i)
    {
        std::cout << number << " * " << i << " = " << number * i << '\n';
    }
}   

/*
Общий вид функции:

    return_type function_name(parameter_type parameter_name)
    {
        // Тело функции
        return result;
    }

Например:

    int square(int value)
    {
        return value * value;
    }


Передача по значению:

В функции:

    int add(int left, int right)

параметры left и right являются отдельными объектами. При вызове
в них копируются значения аргументов.

Изменение left внутри add не изменит first внутри main.


Область видимости:

Переменная, созданная внутри функции, доступна только в этой
функции. Переменная sum из main недоступна внутри add.

Это изолирует части программы и уменьшает количество случайных
взаимодействий между ними.


---------------- КАК ДЕЛАТЬ НЕЛЬЗЯ ----------------

int result;

void calculate()
{
    result = 10 + 20;
}

Глобальная переменная result может изменяться из разных мест.
По коду трудно понять, кто и когда изменил её значение.


---------------- КАК ДЕЛАТЬ ПРАВИЛЬНО -------------

int calculate()
{
    return 10 + 20;
}

Результат явно возвращается вызывающему коду.


Функция с ненулевым типом должна вернуть значение:

int broken_function()
{
    // Нет return — использование результата приведёт
    // к неопределённому поведению.
}


Что происходит под капотом:

При обычном вызове функции программа временно сохраняет информацию
о месте возврата и создаёт область для параметров и локальных
переменных. Это связано с понятием стека вызовов.

После return выполнение продолжается в месте вызова.

Однако компилятор может встроить тело небольшой функции прямо
в вызывающий код. Такая оптимизация называется inlining. Это не
изменяет смысл программы и не отменяет пользу разделения на функции.
*/