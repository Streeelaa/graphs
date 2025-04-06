#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>


class IFuncSolver{
public:
    virtual double operator()(double x) = 0;
};

class SquareFunc : public IFuncSolver {
private:
    double a, b, c;
public:
    SquareFunc(double a, double b, double c) { this->a = a; this->b = b; this->c = c; }
    double operator()(double x) override {
        return a * x * x + b * x + c;
    }
};

class Sqrt : public IFuncSolver {
private:
    double a, b;
public:
    Sqrt(double a, double b) { this->a = a; this->b = b; }
    double operator()(double x) override {
        return sqrt(x + a) + b;
    }
    double getA() const { return a; }
    double getB() const { return b; }
};

class LinearFunc : public IFuncSolver {
private: 
    double a, b;
public:
    LinearFunc(double a, double b) { this->a = a; this->b = b; }
    double operator()(double x) override {
        return a * x + b;
    }
};
class Visualisator {
private:
    std::vector<double> coorX;
    std::vector<double> coorY;
public:
    void Show(IFuncSolver& lf) {
        coorX.clear();
        coorY.clear();

        double startX = -100.0;
        const double endX = 100.0;

        Sqrt* sqrtFunc = dynamic_cast<Sqrt*>(&lf);
        if (sqrtFunc) {
            double minX = -sqrtFunc->getA(); // x ≥ -a
            startX = max(minX, -100.0);
        }

        for (double x = startX; x <= endX; x += 0.1) {
            coorX.push_back(x);
            coorY.push_back(lf(x));
        }
    }
    const std::vector<double>& getCoorX() { return coorX; }
    const std::vector<double>& getCoorY() { return coorY; }
};
