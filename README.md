# Fireworks2D
Задание
Реализовать систему частиц, имитирующую эффект фейерверка в 2D.
Детали
• Внизу сцены расположена пушка, выстреливающая вверх снаряды под случайным углом относительно вертикали.
• Каждый снаряд имеет случайную начальную скорость и случайное время жизни.
• По истечении времени жизни снаряда он детонирует.
• При детонации снаряд разрывается случайным образом на:
◦ несколько десятков осколков (искр).
◦ пару малых снарядов.
• Время жизни каждого малого снаряда или искры примерно в два раза меньше времени
жизни сдетанировавшего снаряда.
• Начальный вектор направления искры выбирается случайным образом.
• Скорость движения искры пропорционально зависит от времени жизни
сдетанировавшего снаряда: чем больше время жизни снаряда – тем больше скорость
движения искры.
• Начальный вектор движения каждого малого снаряда с некоторой погрешностью
совпадает с вектором движения сдетанировавшего снаряда.
• Скорость движения каждого малого снаряда примерно в два раза больше скорости
движения сдетанировавшего снаряда.
• Малый снаряд всегда разрывается на несколько десятков искр.
• На все объекты сцены (снаряды, малые снаряды, искры) действует сила тяжести.
Реализация
• C++ (C++11) / STL
• Наибольшее внимание предлагается уделить архитектурной стороне задачи.
• Отрисовку сцены можно реализовать любым удобным способом. Вполне подойдет
схематичная отрисовка точками.
• Не стоит использовать какие либо сторонние библиотеки без явной на то необходимости.
• Все моменты не означенные в тестовом задании реализовывать на свое усмотрение.