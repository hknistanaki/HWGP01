// parser.h by Paul Jo

#ifndef PARSER_H
#define PARSER_H

//#include <iostream>
#include <fstream>
#include "vector.h"
#include "Shape.h"

#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QColor>
#include <QMessageBox>
#include <QTextStream>

// Remove comments below once Shape, Line, Circle... etc is done (Shortcut is Ctrl + /).
#include "Line.h"
#include "circle.h"
#include "Polygon.h"
#include "polyline.h"
#include "Rectangle.h"
#include "square.h"
#include "Ellipse.h"
#include "Text.h"

using namespace std;

gp::vector<Shape*> ParseFile();
Shape* readLine(ifstream &in, int id);
Shape* readPolyLine(ifstream &in, int id);
Shape* readPolygon(ifstream &in, int id);
Shape* readRectangle(ifstream &in, int id);
Shape* readSquare(ifstream &in, int id);
Shape* readEllipse(ifstream &in, int id);
Shape* readCircle(ifstream &in, int id);
Shape* readText(ifstream& in,int id);
QColor getColor(string color);
PenStyle getPenStyle(string style);
BrushStyle getBrushStyle(string brush);
PenJoinStyle getPJStyle(string join);
PenCapStyle getPCStyle(string cap);
Qt::AlignmentFlag getAlignmentFlag(string flag);
QFont::Weight getWeight(string weight);

#endif // PARSER_H
