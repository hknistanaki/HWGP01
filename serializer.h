#ifndef SERIALIZER_H
#define SERIALIZER_H

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
#include <QPen>
#include <QBrush>

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
Shape* writeLine(ifstream &in, int id);
Shape* writePolyLine(ifstream &in, int id);
Shape* writePolygon(ifstream &in, int id);
Shape* writeRectangle(ifstream &in, int id);
Shape* writeSquare(ifstream &in, int id);
Shape* writeEllipse(ifstream &in, int id);
Shape* writeCircle(ifstream &in, int id);
Shape* writeText(ifstream& in,int id);
QColor setColor(string color);
PenStyle setPenStyle(string style);
BrushStyle setBrushStyle(string brush);
PenJoinStyle setPJStyle(string join);
PenCapStyle setPCStyle(string cap);
Qt::AlignmentFlag setAlignmentFlag(string flag);
QFont::Weight setWeight(string weight);

#endif /* SERIALIZER_H_ */
