

// lesson_05_loops.cpp

#include <iostream>

int main()
{
    int limit{};

    std::cout << "Enter a positive integer: ";

    if (!(std::cin >> limit))
    {
        std::cerr << "Error: input must be an integer.\n";
        return 1;
    }

    if (limit <= 0)
    {
        std::cerr << "Error: number must be positive.\n";
        return 1;
    }

    /*
    Цикл for состоит из трёх частей:

        for (инициализация; условие; изменение)

    1. Инициализация выполняется один раз.
    2. Проверяется условие.
    3. Выполняется тело цикла.
    4. Выполняется изменение.
    5. Процесс повторяется с пункта 2.
    */

    std::cout << "Numbers from 1 to " << limit << ":\n";

    for (int number{1}; number <= limit; ++number)
    {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    // Переменная для накопления результата называется аккумулятором.
    int sum{0};

    for (int number{1}; number <= limit; ++number)
    {
        sum += number; // То же самое, что sum = sum + number.
    }

    std::cout << "Sum: " << sum << '\n';

    /*
    Цикл while используется, когда количество повторений
    заранее может быть неизвестно.

    Условие проверяется ДО каждой итерации.
    Поэтому while может не выполниться ни разу.
    */

    int countdown{limit};

    std::cout << "Countdown:\n";

    while (countdown > 0)
    {
        std::cout << countdown << ' ';
        --countdown;
    }

    std::cout << "0\n";

    /*
    ++number увеличивает значение на единицу.
    --number уменьшает значение на единицу.

    В данном контексте также работали бы number++ и number--,
    но для простых счётчиков в C++ обычно предпочитают префиксную
    форму ++number.
    */

    /*
    ---------------- КАК ДЕЛАТЬ НЕЛЬЗЯ ----------------

    int number{1};

    while (number <= 10)
    {
        std::cout << number << '\n';
    }

    number не изменяется, поэтому условие всегда остаётся true.
    Получается бесконечный цикл.


    Опасная лишняя точка с запятой:

    for (int number{1}; number <= 10; ++number);
    {
        std::cout << "Hello\n";
    }

    Точка с запятой становится пустым телом цикла.
    Блок ниже выполняется отдельно только один раз.


    ---------------- КАК ДЕЛАТЬ ПРАВИЛЬНО -------------

    for (int number{1}; number <= 10; ++number)
    {
        std::cout << number << '\n';
    }
    */

    /*
    Домашнее задание

    1. Запроси положительное целое число N.

       С помощью цикла for выведи таблицу умножения для N
       от 1 до 10.

       Пример для N = 5:

           5 * 1 = 5
           5 * 2 = 10
           ...
           5 * 10 = 50

       Обработай ввод текста и число, которое не является
       положительным.

    2. Запроси положительное целое число N.

       С помощью цикла while найди сумму только чётных чисел
       от 1 до N включительно.

       Пример:

           N = 10
           Сумма: 2 + 4 + 6 + 8 + 10 = 30
    */

    // Здесь напиши решение домашнего задания.

    int number{};
    std::cout << "Enter positive number: ";
    if (!(std::cin >> number))
    {
        std::cerr << "Number must be integer!\n";
        return 1;
    }
    else if (number <= 0) {
        std::cerr << "Number must be positive!\n";
        return 1;
    }
    for (int i{1}; i <= 10;  ++i)
    {
        std::cout << number << " * " << i << " = " << number * i << '\n';
    }

    int n{};
    std::cout << "Enter positive integer number: ";
    if(!(std::cin >> n))
    {
        std::cerr << "Number must be integer!\n";
        return 1;
    }
    else if (n <= 0)
    {
        std::cerr << "Number must be positive!\n";
        return 1;
    }
    int even_sum{};
    int current_number{2};
    std::cout << "Сумма: ";
    while (current_number <= n)
    {
        if (current_number > 2)
        {
            std::cout << " + ";
        }
        std::cout << current_number;
        even_sum += current_number;
        current_number += 2;
    }
    if (n < 2)
    {
        std::cout << 0;
    }
    std::cout << " = " << even_sum << '\n';

    return 0;
}

/*
Что происходит под капотом:

Цикл не означает, что компилятор копирует тело много раз.
Обычно машинный код содержит:

    1. Проверку условия.
    2. Инструкции тела цикла.
    3. Изменение счётчика.
    4. Переход обратно к проверке.

Оптимизатор может развернуть цикл, вычислить результат заранее
или полностью удалить ненужные итерации, если поведение программы
при этом не изменится.

Важная граница:

    number < limit

не включает limit.

    number <= limit

включает limit.

Ошибки на единицу — off-by-one errors — одни из наиболее частых
ошибок даже в промышленном коде.
*/

