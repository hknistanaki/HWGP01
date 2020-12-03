#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

class Text : public Shape
{
public:
    Text(QPaintDevice * device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text} { }
    ~Text() override { }

    void set_point(const QPoint& point) {origin = point;}
    void set_str(const QString &newStr) {textStr = newStr;}
    void set_dimensions(const int &lIn, const int &wIn) {l = lIn; w = wIn;}

    void set_all_text(QString text, QColor color, Qt::AlignmentFlag alignment, int pointSize,
                       QString fontFamily, QFont::Style style, QFont::Weight weight);

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    QPoint id_pos() const override {return origin;}

private:
    QPoint origin;
    QString textStr;
    int l;
    int w;

    QColor color;
    Qt::AlignmentFlag alignment;
    int pointSize;
    QString family;
    QFont::Style fontStyle;
    QFont::Weight weight;

};

#endif // TEXT_H
