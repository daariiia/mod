#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual double area() const = 0;
    virtual void print_coordinates() const = 0;
};

class Quadrilateral : public Shape
{
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}

    double area() const override
    {
        return 0.5 * std::abs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
    }

    void print_coordinates() const override
    {
        std::cout << "Coordinates of quadrilateral: ";
        std::cout << "(" << x1 << ", " << y1 << "), ";
        std::cout << "(" << x2 << ", " << y2 << "), ";
        std::cout << "(" << x3 << ", " << y3 << "), ";
        std::cout << "(" << x4 << ", " << y4 << ")\n";
    }
};

class Triangle : public Shape
{
private:
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    double area() const override
    {
        return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }

    void print_coordinates() const override
    {
        std::cout << "Coordinates of triangle: ";
        std::cout << "(" << x1 << ", " << y1 << "), ";
        std::cout << "(" << x2 << ", " << y2 << "), ";
        std::cout << "(" << x3 << ", " << y3 << ")\n";
    }
};

int main()
{
    Quadrilateral quad(5, 0, 4, 1, 10, 3, 2, 3);
    quad.print_coordinates();
    std::cout << "The area of a quadrilateral: " << quad.area() << std::endl;

    Triangle tri(9, 7, 4, 0, 2, 3);
    tri.print_coordinates();
    std::cout << "The area of a triangle: " << tri.area() << std::endl;
}
