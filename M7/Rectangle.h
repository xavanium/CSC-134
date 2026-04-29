//rectangle.h
#include <iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        double width, length;
    public:
        double getWidth() const {
            return width;
        }
        double getLength() const {
            return length;
        }
        double getArea() const {
            //always calculated fresh
            double area = length*width;
            return area;
        }
        void setWidth(double w) {
            width = w;
        }
        void setLength(double l) {
            length = l;
        }
        void drawRectangle(){
            std::string pixel = "&";
            for (int i=0; i<length; i++) {
                for (int j=0; j<width; j++) {
                    std::cout << pixel;
                }
                std::cout << std::endl;
            }
        }
};
//WEEEEEEEEE ADDED drawRectangle()

#endif