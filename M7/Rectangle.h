//rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        double width, length;
    public:
        double getWidth() const;
        double getLength() const;
        double getArea() const;
        void setWidth(double w);
        void setLength(double l);
};

#endif