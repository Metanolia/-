#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

const double pi = 3.14159265358979;

void showMenu() {
    std::cout << "Выберите фигуру для расчета:\n";
    std::cout << "1. Круг\n";
    std::cout << "2. Прямоугольник\n";
    std::cout << "3. Треугольник\n";
    std::cout << "4. Квадрат\n";
    std::cout << "5. Параллелограмм\n";
    std::cout << "6. Трапеция\n";
    std::cout << "7. Выход\n";
}

int readChoice() {
    int value;
    while (true) {
        std::cout << "Ваш выбор: ";
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Введите число от 1 до 7." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

double readPositiveDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Введите положительное число." << std::endl;
        } else if (value <= 0) {
            std::cout << "Значение должно быть больше нуля." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

double areaCircle(double radius) {
    return pi * radius * radius;
}

double circumferenceCircle(double radius) {
    return 2.0 * pi * radius;
}

double areaRectangle(double length, double width) {
    return length * width;
}

double perimeterRectangle(double length, double width) {
    return 2.0 * (length + width);
}

double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

double areaSquare(double side) {
    return side * side;
}

double perimeterSquare(double side) {
    return 4.0 * side;
}

double areaParallelogram(double base, double height) {
    return base * height;
}

double perimeterParallelogram(double base, double side) {
    return 2.0 * (base + side);
}

double areaTrapezoid(double base1, double base2, double height) {
    return 0.5 * (base1 + base2) * height;
}

double perimeterTrapezoid(double base1, double base2, double side1, double side2) {
    return base1 + base2 + side1 + side2;
}

int main() {
    while (true) {
        showMenu();
        int choice = readChoice();

        if (choice == 1) {
            double radius = readPositiveDouble("Введите радиус круга: ");
            double area = areaCircle(radius);
            double circumference = circumferenceCircle(radius);
            std::cout << "Площадь круга: " << std::fixed << std::setprecision(2) << area << std::endl;
            std::cout << "Длина окружности: " << std::fixed << std::setprecision(2) << circumference << std::endl;
        } else if (choice == 2) {
            double length = readPositiveDouble("Введите длину прямоугольника: ");
            double width = readPositiveDouble("Введите ширину прямоугольника: ");
            double area = areaRectangle(length, width);
            double perimeter = perimeterRectangle(length, width);
            std::cout << "Площадь прямоугольника: " << std::fixed << std::setprecision(2) << area << std::endl;
            std::cout << "Периметр прямоугольника: " << std::fixed << std::setprecision(2) << perimeter << std::endl;
        } else if (choice == 3) {
            double base = readPositiveDouble("Введите основание треугольника: ");
            double height = readPositiveDouble("Введите высоту треугольника: ");
            double area = areaTriangle(base, height);
            std::cout << "Площадь треугольника: " << std::fixed << std::setprecision(2) << area << std::endl;
        } else if (choice == 4) {
            double side = readPositiveDouble("Введите сторону квадрата: ");
            double area = areaSquare(side);
            double perimeter = perimeterSquare(side);
            std::cout << "Площадь квадрата: " << std::fixed << std::setprecision(2) << area << std::endl;
            std::cout << "Периметр квадрата: " << std::fixed << std::setprecision(2) << perimeter << std::endl;
        } else if (choice == 5) {
            double base = readPositiveDouble("Введите основание параллелограмма: ");
            double height = readPositiveDouble("Введите высоту параллелограмма: ");
            double side = readPositiveDouble("Введите боковую сторону параллелограмма: ");
            double area = areaParallelogram(base, height);
            double perimeter = perimeterParallelogram(base, side);
            std::cout << "Площадь параллелограмма: " << std::fixed << std::setprecision(2) << area << std::endl;
            std::cout << "Периметр параллелограмма: " << std::fixed << std::setprecision(2) << perimeter << std::endl;
        } else if (choice == 6) {
            double base1 = readPositiveDouble("Введите первое основание трапеции: ");
            double base2 = readPositiveDouble("Введите второе основание трапеции: ");
            double height = readPositiveDouble("Введите высоту трапеции: ");
            double side1 = readPositiveDouble("Введите первую боковую сторону трапеции: ");
            double side2 = readPositiveDouble("Введите вторую боковую сторону трапеции: ");
            double area = areaTrapezoid(base1, base2, height);
            double perimeter = perimeterTrapezoid(base1, base2, side1, side2);
            std::cout << "Площадь трапеции: " << std::fixed << std::setprecision(2) << area << std::endl;
            std::cout << "Периметр трапеции: " << std::fixed << std::setprecision(2) << perimeter << std::endl;
        } else if (choice == 7) {
            std::cout << "Выход. До свидания!" << std::endl;
            break;
        } else {
            std::cout << "Неверный выбор. Пожалуйста, выберите число от 1 до 7." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}