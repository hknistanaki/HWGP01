#include "Shape.h"
#include "Text.h"

void Text::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);
    paint->drawText(temp.x(), temp.y(), nameTag("Text"));

    QFont font{family, pointSize};

    font.setStyle(fontStyle);
    font.setWeight(weight);

    paint->setFont(font);
    paint->setPen(get_pen());

    paint->drawText(origin.x(), origin.y(), l, w, alignment, textStr);

    paint->save();
    paint->translate(translate_x, translate_y);

    paint->restore();
}

void Text::set_all_text(QString text, QColor colorIn, Qt::AlignmentFlag alignmentIn, int sizePtIn,
                    QString fontFamilyIn, QFont::Style styleIn, QFont::Weight fontWeightIn)
{
    textStr = text;
    color = colorIn;
    alignment = alignmentIn;
    pointSize = sizePtIn;
    family = fontFamilyIn;
    fontStyle = styleIn;
    weight = fontWeightIn;

}
