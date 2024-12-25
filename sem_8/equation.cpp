#include <iostream>
#include <variant>
#include <cmath>
#include <utility>
// ax^2 + bx + c


std::variant<std::monostate, double, std::pair<double, double>> SolveEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        return std::make_pair(x1, x2);
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        return x;
    }
    else {
        return std::monostate{};
    }
}
int main() {
    double a, b, c;
    std::cout << "Insert a, b, c: ";
    std::cin >> a >> b >> c;
    std::variant<std::monostate, double, std::pair<double, double>> res = SolveEquation(a, b, c);
    if (std::holds_alternative<std::monostate>(res)) {
        std::cout << "No rational roots." << std::endl;
    }
    else if (std::holds_alternative<double>(res)) {
        std::cout << "One root: " << std::get<double>(res) << std::endl;
    }
    else if (std::holds_alternative<std::pair<double, double>>(res)) {
        std::cout << "First root: " << std::get<0>(std::get<std::pair<double, double>>(res)) << std::endl;
        std::cout << "Second root: " << std::get<1>(std::get<std::pair<double, double>>(res)) << std::endl;
    }
    return 0;
}