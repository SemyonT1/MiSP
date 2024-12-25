#pragma once
#include <iostream>
#include <memory>

class TimeMeter {
public:
    TimeMeter(unsigned count);

    // Установка временной метки
    double setTimeStamp(unsigned num);

    // Получение времени метки
    double getSTimeStamp(unsigned num);
    int64_t getMSTimeStamp(unsigned num);

    // Разница между метками
    double getSDiff(unsigned first, unsigned second);
    int64_t getMSDiff(unsigned first, unsigned second);

    // Проверка на превышение заданного интервала
    bool isLess(unsigned first, unsigned second, int64_t expected);
    bool isLess(unsigned num, int64_t expected);

private:
    // PIMPL: указатель на реализацию
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

