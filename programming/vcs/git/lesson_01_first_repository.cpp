// Урок 1: Первый репозиторий и автор
//
// Git — распределённая система контроля версий.
// GitHub и другие хостинги могут хранить Git-репозитории,
// но для локальной работы Git интернет не нужен.
//
// Команды первого урока:
//
//   git --version
//   git init --initial-branch=main
//   git status
//   git config --show-origin --get user.name
//   git config --show-origin --get user.email
//   cat .git/HEAD
//
// git init создаёт скрытую директорию .git. В ней находятся
// конфигурация, ссылки, история и база объектов репозитория.
//
// HEAD содержит символическую ссылку:
//
//   ref: refs/heads/main
//
// До первого коммита файл refs/heads/main может отсутствовать:
// ветке пока не на какой коммит указывать.
//
// Git прочитал user.name и user.email из /home/x/.gitconfig,
// то есть с глобального уровня конфигурации.

#include <iostream>

int main()
{
    std::cout << "Git lesson 1 complete\n";
    return 0;
}

/*
Как собрать и запустить:

    g++ -std=c++23 -Wall -Wextra -Wpedantic \
        lesson_01_first_repository.cpp -o /tmp/git-lesson-01

    /tmp/git-lesson-01

Почему результат сборки находится в /tmp?

Исполняемый файл — производный артефакт. Его можно заново получить
из исходного кода, поэтому сейчас мы не добавляем его в репозиторий.

Главный вывод урока:

    Git хранит историю проекта в .git.
    HEAD указывает на текущую ветку.
    Автор будущих коммитов задаётся через user.name и user.email.
*/
