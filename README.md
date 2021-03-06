# Иерархия классов, наследованных от класса Parallelogramm
Лабораторная работа №2

Используя класс, созданный в результате выполнения предыдущего пункта работы, разработать базовый/производный класс. Геометрическую фигуру необходимо передвинуть, повернуть.
Добавить в производный класс следующие новые возможности:
•	запоминание первоначального расположения объекта (линии или фигуры) при ее создании;
•	функцию-член, выполняющую перенос центра координат в новую точку (сХ, cY) и/или на заданное смещение (x, y);
•	функцию-член, выполняющую сброс измерений, т.е. возврат объекта (линии или фигуры) в первоначальное положение.
В функции main организовать ввод конкретных параметров объекта с клавиатуры, создание объекта (экземпляра класса), тестирование всех его методов (как старых, так и новых) в текстовом режиме с выдачей соответствующих сообщений.
Организовать исходный текст в виде пяти исходных файлов:
•	заголовочный с описанием класса (*.h) из предыдущей части задания;
•	с реализацией методов (функций-членов) класса (*.cpp) из предыдущей части задания;
•	заголовочный с описанием нового базового/производного класса (*.h);
•	с реализацией методов (функций-членов) нового базового/производного класса (*.cpp);
•	с функцией main (*.cpp).
Для тестирования необходимо подготовить тестовые данные с заранее известными правильными результатами.
Предлагается определить классы и их иерархию, а также продемонстрировать использование введенных конструкций при работе.

Примеры иерархий наследования:
1) фигура: выпуклый четырехугольник: трапеция;
2) фигура: треугольник;
3) фигура: квадрат: прямоугольник: ромб: параллелограмм;
4) точка: окружность: окружность с текстом внутри.
5) меню: горизонтальное, вертикальное, иерархическое;
6) точка: окружность: эллипс;
7) прямоугольный объект на экране: текстовая строка, окно.
8) фигура: треугольник: треугольная пирамида.
