#ifndef SHAPE_H
#define SHAPE_H

/// Shape.h, by Ethan Lew and Eric Nakayama

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QFont>

// i'm not sure these are necessary - Ethan
using namespace Qt;
using namespace std;

class Shape
{
public:
    /*!
     * \brief The ShapeType enum
     */
    enum class ShapeType {
        NoShape, ///< default value
        Line, ///< Line object
        Polyline, ///< PolyLine object
        Polygon, ///< Polygon object
        Square, ///< Square object
        Rectangle, ///< Rectangle object
        Circle, ///< Circle object
        Ellipse, ///< Ellipse object
        Text ///< Text object
    };

    /*!
     * \brief Shape (default constructor)
     * \param shapeID Id of shape to add, -1 default value for errors
     * \param shape ShapeType enum value, default ShapeType::NoShape
     */
    Shape(QPaintDevice* device = nullptr, int shapeID = -1, ShapeType shape = ShapeType::NoShape);

    /*!
     * \brief ~Shape
     * Virtual Shape Destructor
     */
    virtual ~Shape() {}

    /*!
     * \brief getPainter
     * \param device
     * \return unique_ptr of QPainter
     */
    std::unique_ptr<QPainter> getPainter(QPaintDevice* device) const;

    /*!
     * \brief get_shape
     * \return shapeType, ShapeType enum value
     */
    ShapeType get_shape() const {return shapeType;}

    /*!
     * \brief get_pen
     * \return pen, const QPen reference
     */
    const QPen& get_pen() const {return pen;}

    /*!
     * \brief get_brush
     * \return brush, const QBrush reference
     */
    const QBrush& get_brush() const {return brush;}

    /*!
     * \brief get_point
     * \return origin of shape. Pure virtual
     */
    virtual QPoint get_point() const = 0;

    /*!
     * \brief get_shapeID
     * \return id
     */
    int get_shapeID() const {return id;}

    /*!
     * \brief set_shapeID sets shape's id
     * \param newId id to assign to shape
     */
    void set_shapeID(const int &newId) {id = newId;}

    /*!
     * \brief set_shape sets shape's ShapeType value
     * \param shape ShapeType enum value
     */
    void set_shape(ShapeType shape) {shapeType = shape;}

    /*!
     * \brief set_pen sets pen's properties
     * \param color
     * \param penWidth
     * \param penStyle
     * \param penCapStyle
     * \param penJoinStyle
     */
    void set_pen(QColor color, int penWidth, Qt::PenStyle penStyle, Qt::PenCapStyle penCapStyle, Qt::PenJoinStyle penJoinStyle);

    /*!
     * \brief set_pen only changes pen's color
     * \param color color to change pen to
     */
    void set_pen(QColor color) {pen.setColor(color);}

    /*!
     * \brief set_brush sets brush's properties
     * \param color Qt::GlobalColor
     * \param brushStyle Qt::BrushStyle
     */
    void set_brush(QColor color, Qt::BrushStyle brushStyle);

    /*!
     * \brief default_style sets the shape to a default style
     */
    void default_style() {pen = Qt::SolidLine;
                          brush = Qt::NoBrush;
                          qpainter.setPen(pen);
                          qpainter.setBrush(brush);}

    /*!
     * \brief draw draw event, interface only
     */
    virtual void draw(QPaintDevice* device, const int translate_x, const int translate_y) const = 0;

    /*!
     * \brief nameTag
     * \return nametag (example "Lin e ID: 1")
     */
    QString nameTag(const QString &shapename =  "NoShape") const;

    /*!
     * \brief id_pos (interface only)
     * \return position to draw nametag
     */
    virtual QPoint id_pos() const = 0;

    /*!
     * \brief perimeter
     * \return integer value perimeter, or 0 if not applicable
     */
    virtual double perimeter() const = 0;

    /*!
     * \brief area
     * \return integer value area, or 0 if not applicable
     */
    virtual double area() const = 0;


protected:
    /*!
     * \brief get_qpainter
     * \return qpainter, const QPainter reference
     */
    const QPainter& get_qpainter() const {return qpainter;}

private:
    /*!
     * \brief qpainter QPainter object
     */
    QPainter qpainter;

    /*!
     * \brief id shape's unique ID
     */
    int id;

    /*!
     * \brief shapeType ShapeType enum value
     */
    ShapeType shapeType;

    /*!
     * \brief pen QPen object
     */
    QPen pen;

    /*!
     * \brief brush QBrush object
     */
    QBrush brush;


};

#endif

