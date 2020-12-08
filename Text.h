#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

class Text : public Shape
{
public:
    /*!
     * \brief Text
     * \param device QPaintDevice
     * \param id id to assign to Text
     */
    Text(QPaintDevice * device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text} { }

    ~Text() override { }

    /*!
     * \brief set_point
     * \param point top left point of text bounding box
     */
    void set_point(const QPoint& point) {origin = point;}

    /*!
     * \brief set_str
     * \param newStr string value of Text object
     */
    void set_str(const QString &newStr) {textStr = newStr;}

    /*!
     * \brief set_dimensions sets bounding box of text
     * \param lIn length
     * \param wIn width
     */
    void set_dimensions(const int &lIn, const int &wIn) {l = lIn; w = wIn;}

    /*!
     * \brief set_all_text sets text parameters
     * \param text string to display
     * \param color color of text
     * \param alignment alignment flag
     * \param pointSize point size of font
     * \param fontFamily font family
     * \param style font style
     * \param weight font weight
     */
    void set_all_text(QString text, QColor color, Qt::AlignmentFlag alignment, int pointSize,
                       QString fontFamily, QFont::Style style, QFont::Weight weight);

    /*!
     * \brief draw draws Text
     * \param device QPaintDevice
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief id_pos
     * \return position to draw nametag
     */
    QPoint id_pos() const override {return origin;}

    /*!
     * \brief perimeter
     * \return perimeter of bounding box
     */
    double perimeter() const override {return (2*l)+(2*w);}

    /*!
     * \brief area
     * \return area of bounding box
     */
    double area() const override {return l*w;}

    /*!
     * \brief get_point
     * \return top left point of boundin gbox
     */
    QPoint get_point() const override {return origin;}

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
