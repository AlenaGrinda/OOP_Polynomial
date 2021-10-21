//
// Created by Алёна Гринда on 20.10.2021.
//


#include "Polynomial.h"
#include <cmath>

using namespace std;

//здесь определения:

Polynomial::Polynomial() {
    //count++;
    this->n = 0;
    coefficients = nullptr;
}

Polynomial::Polynomial(int d, const double* c) {
    //count++;
    this->n = d;
    this->coefficients = new double[d + 1];
    for (int i = 0; i < n+1; i++)
        this->coefficients[i] = c[i];
}

//конструктор копирования
Polynomial::Polynomial(const Polynomial& obj) {
    //count++;
    this->n = obj.n;
    this->coefficients = new double[obj.n+1];
    for (int i = 0; i < obj.n+1; i++)
        this->coefficients[i] = obj.coefficients[i];
}


//деструктор
Polynomial::~Polynomial() {
    delete[] this->coefficients;
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
    if (this->coefficients == nullptr) return nullptr;
    l = Count(this->coefficients, this->n);
    char *buf = new char[l + 6*n];
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
    return this->n;
}

int Polynomial::Count(double *_coefficients, int _n) {
    Polynomial other(_n, _coefficients);
    for (int i = 0; i < _n+1; i++) {
        other.coefficients[i] = _coefficients[i];
    }
    int len;
    len = 0;
    for (int i = 0; i < _n+1; i++) {
        for (int j = 0; j < _n+1; j++) {
            while (other.coefficients[i] > 0) {
                len++;
                other.coefficients[i] = other.coefficients[i] / 10;
            }
        }
    }
    return len;
}

