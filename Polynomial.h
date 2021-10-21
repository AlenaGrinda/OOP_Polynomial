//
// Created by Алёна Гринда on 20.10.2021.
//

#ifndef LAB_2_POLYNOMIAL_H
#define LAB_2_POLYNOMIAL_H


#include <iostream>


class Polynomial {

public:
    Polynomial(); //инициализация без параметров, многочлен нулевой степени

    Polynomial(int d, const double* c); //инициализация с параметрами

    Polynomial(const Polynomial& obj); //конструктор копирования

    int getDegree() const; //Вывод степени многочлена

    double evaluate(double); // функция вычисления значения многочлена

    ~Polynomial(); //деструктор

    char* toString();

    friend Polynomial operator+(Polynomial &p1, Polynomial &p2);

    friend Polynomial operator-(Polynomial &p1, Polynomial &p2);

    Polynomial& operator++();

    Polynomial& operator--();

    double operator()(double);

    double operator[](int i);

    Polynomial& operator=(const Polynomial &obj);

private:
    int n; // степень многочлена
    double* coefficients; // коэффициенты многочлена
    static int Count(double *_coefficients, int _n);
};


#endif //LAB_2_POLYNOMIAL_H
