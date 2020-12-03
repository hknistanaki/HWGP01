// parser.h by Paul Jo

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include "vector.h"
#include "Shape.h"

// Remove comments below once Shape, Line, Circle... etc is done (Shortcut is Ctrl + /).
#include "Line.h"
//#include "Circle.h"
#include "Polygon.h"
#include "polyline.h"
#include "Rectangle.h"
//#include "Square.h"
#include "Ellipse.h"
#include "Text.h"

using namespace std;

gp::vector<Shape*> ParseFile(int size);
Shape* readLine(ifstream &in, int id);
Shape* readPolyLine(ifstream &in, int id);
Shape* readPolygon(ifstream &in, int id);
Shape* readRectangle(ifstream &in, int id);
Shape* readSquare(ifstream &in, int id);
Shape* readEllipse(ifstream &in, int id);
Shape* readCircle(ifstream &in, int id);
Shape* readText(ifstream& in,int id);
// QColor getColor(string color);
// PenStyle getPenStyle(string style);
// BrushStyle getBrushStyle(string brush);
// PenJoinStyle getPJStyle(string join);
// PenCapStyle getPCStyle(string cap);

#endif // PARSER_H
