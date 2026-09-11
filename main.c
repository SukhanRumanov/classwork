#include <stdio.h>  // то же самое что и import в питончике
// без неё у нас нет даже put, get, printf и даже +/-/*
// скачиваем базовый функционал из стандартной библиотеки
void my_function();

// языки программирования делятся на 2 типа: компилируемые и интерпретируемые
// компилируемые - это те, которые сначала компилируются в машинный код, а потом уже выполняются (язык C)
// интерпретируемые - это те, которые сразу же выполняются (язык Python)


// комплятору необходима функция main, с которой он начинает выполнение программы
// основыне типы данных в языке C: int(число целое), char(1 символ), float(дробное число), void(ничего)

// в начале каждой функции указывается тип возвращаемого значения, если функция ничего не возвращает, то пишется void
int main() {
	puts("Hello, World!");  // put - выводит текст в консоль
	my_function();  // вызываем функцию my_function
	return 0;  // возвращаем 0, что означает успешное завершение программы
}

void my_function() {
	// это функция, которая ничего не возвращает(ничего не выплевывает, а просто пишет текст)
	puts("This is my function!");
	puts("It does not return anything.");
}


// гайд по гитхабу
// 0. скачиваем гит https://git-scm.com/install/windows (должен появиться git Bash)
// 1. Создаём репозиторий на гитхабе
// 2. переходим в папку с проектом
// cd путь_к_проекту
// cd C:/Users/Romochka/source/repos/test_c_code/test_c_code
// 3. git init (инициализация репозитория)
// 3.1. если первый раз работает с гитхабом, то нужно настроить имя и почту
//git config --global user.name "Ваше Имя"
//git config --global user.email "your@email.com"

// приступаем к работе с гитом
// 4. git checkout -b main (создаём ветку main)
// 5. git add . (скачиваем все файл в наш гит на компьютере)
// 6. git commit -m "Первая установка гитхаба" 
// 7. git remote add origin "ссылка"
// 8. git push origin main (отправляем на гитхаб наш код)



// загружаем изменения!!!!
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~
//$ cd C : \Users\Romochka\source\repos\test_c_code\test_c_code\main.c
//bash : cd: C:UsersRomochkasourcerepostest_c_codetest_c_codemain.c : No such file or directory
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~
//$ cd C : / Users / Romochka / source / repos / test_c_code / test_c_code
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code
//$ ^ C
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code
//$ git init
//Initialized empty Git repository in C : / Users / Romochka / source / repos / test_c_code / test_c_code / .git /
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(master)
//$ git checkout - b main
//Switched to a new branch 'main'
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(main)
//$ git add .
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(main)
//$ git commit - m "Первая установка гитхаба"
//[main(root - commit) f66b100] Первая установка гитхаба
//26 files changed, 232 insertions(+)
//create mode 100644 main.c
//create mode 100644 test_c_code.vcxproj
//create mode 100644 test_c_code.vcxproj.filters
//create mode 100644 test_c_code.vcxproj.user
//create mode 100644 x64 / Debug / main.obj
//create mode 100644 x64 / Debug / test_c_code.exe.recipe
//create mode 100644 x64 / Debug / test_c_code.log
//create mode 100644 x64 / Debug / test_c_code.tlog / CL.command.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / CL.read.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / CL.write.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / Cl.items.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112 - cvtres.read.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112 - cvtres.write.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112 - rc.read.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112 - rc.write.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112.read.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112.read.2.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.2112.write.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.command.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.read.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.secondary.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / link.write.1.tlog
//create mode 100644 x64 / Debug / test_c_code.tlog / test_c_code.lastbuildstate
//create mode 100644 x64 / Debug / test_c_code.tlog / unsuccessfulbuild
//create mode 100644 x64 / Debug / vc143.idb
//create mode 100644 x64 / Debug / vc143.pdb
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(main)
//$ git remote add origin https ://github.com/SukhanRumanov/classwork
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(main)
//$ git push origin main
//Enumerating objects : 22, done.
//Counting objects : 100 % (22 / 22), done.
//Delta compression using up to 12 threads
//Compressing objects : 100 % (19 / 19), done.
//Writing objects : 100 % (22 / 22), 12.10 KiB | 3.02 MiB / s, done.
//Total 22 (delta 2), reused 0 (delta 0), pack - reused 0 (from 0)
//remote : Resolving deltas : 100 % (2 / 2), done.
//To https ://github.com/SukhanRumanov/classwork
//*[new branch]      main->main
//
//Romochka@DESKTOP - ASU2DQ5 MINGW64 ~/ source / repos / test_c_code / test_c_code(main)
//$


// 1. git add . - добавляет все файлы в репозиторий(включая изменения)
// 2. git commit -m "новые изменения" - сохраняет изменения в репозитории
// 3. git push origin main - отправляет изменения на гитхаб

// новая кодировка в гите
