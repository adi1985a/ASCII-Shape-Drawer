#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
private:
    int sideA;
    int sideB;
    string color;
    float area;

public:
    Rectangle() // Konstruktor domyślny
    {
        sideA = 0;
        sideB = 0;
        color = "black";
        area = 0.0f;
    }

    Rectangle(int a, int b, string c) // Przeciążony konstruktor
    {
        sideA = a;
        sideB = b;
        color = c;
        area = calculateArea();
    }

    Rectangle(int a, int b) // Przeciążony konstruktor
    {
        sideA = a;
        sideB = b;
        color = "yellow";
        area = calculateArea();
    }

    void show()
    {
        cout << "Side lengths: " << sideA << ", " << sideB << endl;
        cout << "Color: " << color << endl;
        cout << "Area: " << area << endl;
    }

private:
    float calculateArea()
    {
        return static_cast<float>(sideA * sideB);
    }
};

int main()
{
    Rectangle rectangles[4];

    rectangles[0] = Rectangle();
    rectangles[1] = Rectangle(5, 7, "blue");
    rectangles[2] = Rectangle(3, 10, "green");
    rectangles[3] = Rectangle(8, 8);

    for (int i = 0; i < 4; i++)
    {
        rectangles[i].show();
        cout << endl;
    }

    return 0;
}
