//
// Created by Алёна Гринда on 20.10.2021.
//

#include "Polynomial.h"
#include <cmath>

using namespace std;

//здесь определения:

Polynomial::Polynomial() {
    //count++;
    n = 0;
    coefficients = nullptr;
}

Polynomial::Polynomial(int d, const double *c) {
    //count++;
    n = d;
    coefficients = new double[d + 1];
    for (int i = 0; i < n + 1; i++)
        coefficients[i] = c[i];
}

//конструктор копирования
Polynomial::Polynomial(const Polynomial &obj) {
    //count++;
    n = obj.n;
    coefficients = new double[obj.n + 1];
    for (int i = 0; i < obj.n + 1; i++)
        coefficients[i] = obj.coefficients[i];
}


//деструктор
Polynomial::~Polynomial() {
    delete[] coefficients;
    //count--;
}

//функция вычисления значения многочлена
double Polynomial::evaluate(double x) {

    double evaluation = 0;
    int j = n;
    for (int i = 0; i <= n; i++) {
        evaluation += (coefficients[j] * pow(x, j));
        j--;
    }
    return evaluation;
}

char *Polynomial::toString() {
    int l, len;
    if (coefficients == nullptr) return nullptr;
    l = Count(coefficients, n);
    char *buf = new char[l + 6 * n];
    len = 0;
    for (int i = n; i >= 0; i--) {
        if (i != n) {
            if (coefficients[i] > 0)
                len += std::sprintf(buf + len * sizeof(char), "%s", " + ");
            else
                len += std::sprintf(buf + len * sizeof(char), "%s", " - ");
        } else {
            if (coefficients[i] < 0)
                len += std::sprintf(buf + len * sizeof(char), "%s", "-");
        }
        len += std::sprintf(buf + len * sizeof(char), "%g", abs(coefficients[i]));
        if (i != 0) {
            len += std::sprintf(buf + len * sizeof(char), "%s", "x^");
            len += std::sprintf(buf + len * sizeof(char), "%d", i);
        }
    }
    return buf;
}

//получение степени многочлена
int Polynomial::getDegree() const {
    return n;
}

int Polynomial::Count(double *_coefficients, int _n) {
    Polynomial other(_n, _coefficients);
    for (int i = 0; i < _n + 1; i++) {
        other.coefficients[i] = _coefficients[i];
    }
    int len;
    len = 0;
    for (int i = 0; i < _n + 1; i++) {
        for (int j = 0; j < _n + 1; j++) {
            while (other.coefficients[i] > 0) {
                len++;
                other.coefficients[i] = other.coefficients[i] / 10;
            }
        }
    }
    return len;
}

Polynomial operator+(Polynomial &p1, Polynomial &p2) {

    Polynomial temp;

    if (p2.n + 1 > p1.n + 1) {
        temp.coefficients = new double[p2.n + 1];
        temp.n = p2.n;

        for (int i = 0; i < p2.n + 1; i++) {

            temp.coefficients[i] = p2.coefficients[i];
            if (i < p1.n + 1)
                temp.coefficients[i] += p1.coefficients[i];

        }
    } else {
        temp.coefficients = new double[p1.n + 1];
        temp.n = p1.n;

        for (int i = 0; i < p1.n + 1; i++) {

            temp.coefficients[i] = p1.coefficients[i];
            if (i < p2.n + 1)
                temp.coefficients[i] += p2.coefficients[i];

        }
    }
    return temp;
}

//перегрузка оператора вычитания – дружественная функция вычитает коэффициенты многочленов
Polynomial operator-(Polynomial &p1, Polynomial &p2) {

    Polynomial temp;
    if (p2.n + 1 > p1.n + 1) {
        temp.coefficients = new double[p2.n + 1];
        temp.n = p2.n;

        for (int i = 0; i < p2.n + 1; i++) {

            temp.coefficients[i] = p2.coefficients[i];
            if (i < p1.n + 1)
                temp.coefficients[i] = p1.coefficients[i] - temp.coefficients[i];
        }
    } else {
        temp.coefficients = new double[p1.n + 1];
        temp.n = p1.n;

        for (int i = 0; i < p1.n + 1; i++) {

            temp.coefficients[i] = p1.coefficients[i];
            if (i < p2.n + 1)
                temp.coefficients[i] -= p2.coefficients[i];
        }
    }
    return temp;
}

//перегрузка оператора инкремента увеличивает степень многочлена (при этом коэффициент при нулевой степени равен 0)
Polynomial &Polynomial::operator++() {
    n++;
    for (int i = n; i > 0; i--) {
        coefficients[i] = coefficients[i - 1];
    }
    coefficients[0] = 0;
    return *this;
}

//перегрузка оператора декримента уменьшает степень многочлена (при этом коэффициент который был при нулевой степени убирается)
Polynomial &Polynomial::operator--() {
    n--;
    for (int i = 0; i < n + 1; i++) {
        coefficients[i] = coefficients[i + 1];

    }
    return *this;
}

// перегрузка операции вызова функции – вычисление многочлена для заданного х
double Polynomial::operator()(double x) {

    return evaluate(x);
}


//перегрузка индексирования, через [] обращение происходит напрямую к массиву коэффициентов
double Polynomial::operator[](int i) {

    return coefficients[i];
}

Polynomial &Polynomial::operator=(const Polynomial &obj) {
    if (this != &obj) {
        delete[] coefficients;
        coefficients = new double[obj.n + 1];
        n = obj.n;

        for (int i = 0; i < obj.n + 1; i++)
            coefficients[i] = obj.coefficients[i];
    }
    return *this;
}


