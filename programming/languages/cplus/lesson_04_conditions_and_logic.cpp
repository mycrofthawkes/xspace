// lesson_04_conditions_and_logic.cpp

// Урок 4: Условные конструкции и логика.cpp

#include <iostream>

int main()
{
    int age{};

    std::cout << "Enter your age: ";

    // Если вместо целого числа введён текст,
    // std::cin перейдёт в состояние ошибки.
    if (!(std::cin >> age))
    {
        std::cerr << "Error: age must be an integer.\n";
        return 1;
    }

    if (age < 0)
    {
        std::cerr << "Error: age cannot be negative.\n";
        return 1;
    }

    // Выполняется только первая подходящая ветвь.
    if (age < 13)
    {
        std::cout << "Category: child\n";
    }
    else if (age < 18)
    {
        std::cout << "Category: teenager\n";
    }
    else
    {
        std::cout << "Category: adult\n";
    }

    /*
    Операторы сравнения:

        ==    равно
        !=    не равно
        <     меньше
        >     больше
        <=    меньше или равно
        >=    больше или равно

    Логические операторы:

        &&    И
        ||    ИЛИ
        !     НЕ
    */

    const bool has_working_age{age >= 18 && age <= 65};
    const bool has_discount{age < 13 || age >= 65};
    const bool is_minor{!(age >= 18)};

    std::cout << std::boolalpha;
    std::cout << "Working age: " << has_working_age << '\n';
    std::cout << "Discount available: " << has_discount << '\n';
    std::cout << "Minor: " << is_minor << '\n';

    /*
    ---------------- КАК ДЕЛАТЬ НЕЛЬЗЯ ----------------

    if (age = 18)
    {
        std::cout << "Adult\n";
    }

    =  означает присваивание.
    == означает сравнение.


    Неправильная проверка диапазона:

    if (13 <= age < 18)

    C++ не понимает математические цепочки сравнений так,
    как их понимает человек.


    ---------------- КАК ДЕЛАТЬ ПРАВИЛЬНО -------------

    if (age >= 13 && age < 18)
    {
        std::cout << "Teenager\n";
    }


    ---------------- ВСЕГДА ИСПОЛЬЗУЙ СКОБКИ ----------

    Плохо:

    if (age >= 18)
        std::cout << "Adult\n";

    Хорошо:

    if (age >= 18)
    {
        std::cout << "Adult\n";
    }
    */

/*
Домашнее задание

1. Запроси целое число и выведи:
   - положительное оно, отрицательное или равно нулю;
   - чётное оно или нечётное через % 2.

2. Запроси оценку от 0 до 100 и выведи:
   - 90–100: A
   - 75–89:  B
   - 60–74:  C
   - 0–59:   D

Обработай значение вне диапазона и ввод текста вместо числа.
*/
    int number{};
    std::cout << "Enter integer: ";
    if (!(std::cin >> number)) {
        std::cerr << "Error: number must be an integer.\n";
        return -1;
    } else {
        if (number > 0) {
            std::cout << "Number is positive.\n";
        }
        else if (number == 0) {
            std::cout << "Number is equal to zero.\n";
        }
        else {
            std::cout << "Number is negative.\n";
        }
    }
    if (number % 2 == 0)
    {
        std::cout << "Number is even.\n";
    }
    else 
    {
        std::cout << "Number is odd.\n";
    }

    int grade{};
    std::cout << "Enter grade [0-100]: ";
    if (!(std::cin >> grade))
    {
        std::cerr << "Error: grade must be an integer.\n";
        return 1;
    }
    else if (grade < 0 || grade > 100)
    { 
        std::cerr << "Error: grade must be between 0 and 100.\n";
        return 1;
    }
    else
    {
        if (grade >= 90) 
        {
            std::cout << "Grade: A.\n";
        }
        else if (grade >= 75) 
        {
            std::cout << "Grade: B.\n";
        }
        else if (grade >= 60 )
        {
            std::cout << "Grade: C.\n";
        }
        else
        {
            std::cout << "Grade: D.\n";
        }
    }

    return 0;
}

/*
Короткое замыкание:

    left && right

Если left равно false, выражение right уже не вычисляется.

    left || right

Если left равно true, выражение right уже не вычисляется.

Поэтому безопасна следующая проверка:

    divisor != 0 && value / divisor > 10

Деление произойдёт только при ненулевом divisor.


Что происходит под капотом:

Условное выражение вычисляется до значения bool:

    true  — ветвь выполняется;
    false — ветвь пропускается.

На машинном уровне это часто превращается в сравнение и условный
переход к другому участку инструкций. Однако оптимизатор вправе
устроить код иначе, если наблюдаемое поведение не изменится.
*/