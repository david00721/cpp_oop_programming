#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor
    Rectangle(int w, int h) {
        setWidth(w);
        setHeight(h);
    }

    // Getters
    int getWidth() const
    {
        return width;
    }

    int getHeight() const
    {
        return height;
    }

    // Setters with validation
    Rectangle& setWidth(const int w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Error: Value must be positive" << endl;
        }
        return *this;
    }

    Rectangle& setHeight(const int h) {
        if (h > 0) {
            height = h;
        } else {
            cout << "Error: Value must be positive" << endl;
        }
        return *this;
    }

    // Calculate area
    int getArea() const {
        return width * height;
    }

    // Calculate perimeter
    int getPerimeter() const {
        return 2 * (width + height);
    }

    // Destructor
    ~Rectangle() {
        cout << "Rectangle deleted." << endl;
    }
};

int main() {
    // Create rectangle with valid data
    Rectangle rect(5, 10);

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;

    // Try to set invalid value
    rect.setWidth(-3);

    // Set new valid values
    rect.setWidth(7).setHeight(14);

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;

    // Output final perimeter and area
    cout << "Area: " << rect.getArea() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;

    return 0;
}