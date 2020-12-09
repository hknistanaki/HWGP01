#include "serializer.h"

//vector<int> v;
//v.push_back(3);
//v[0]

gp::vector<Shape*> SerializerFile(){
	const QString FILE_NAME = "oshapes.txt";
	bool done = false;

    QString shapePath = qApp->applicationDirPath();
    shapePath.append('/' + FILE_NAME);
    qDebug() << "path to oshapes.txt: " << shapePath;
    QFile shapeFile(shapePath);

    if(!shapeFile.exists()){
        QMessageBox fileNotFoundError;
        fileNotFoundError.setText("ERR: \"" + FILE_NAME +"\" not found!");
        fileNotFoundError.exec();
        exit(-1);
    }

    // file exists at this point
    ofstream out(shapePath.toStdString());

    gp::vector<Shape*> wShapes;

    for (auto it = wShapes.begin(); it != wShapes.end(); ++it)
    {
//    	int id = wShapes.get_shapeID();
//    	ShapeType *shapeType = wShapes.get_shape();
//    	Qcolor color = wShapes.get_pen();
//    	int penWidth = wShapes.get_pen();
//    	PenStyle penStyle = wShapes.get_pen();
//    	PenCapStyle penCapStyle = wShapes.get_pen();
//    	PenJoinStyle penJoinStyle = wShapes.get_pen();
//    	BrushColor brushColor = wShapes.get_brush();
//    	BrushStyle brushStyle = wShapes.get_brush();
//    	wShapes.get_text();

        int id = (*it)->get_shapeID();
        QPen qPen = (*it)->get_pen();
        QBrush qBrush = (*it)->get_brush();

    	// We need to add the qPen class. Class not added yet.
    	qPen.get_penColor();
    	qPen.get_penWidth();
    	qPen.get_penStyle();
    	qPen.get_penCapStyle();
    	qPen.get_penJoinStyle();

    	switch(id){
        case 1:
            wShapes.push_back(writeLine(out, id));
            qDebug() << "parsed line";
            break;
        case 2:
            wShapes.push_back(writePolyLine(out, id));
            qDebug() << "parsed polyline";
            break;
        case 3:
            wShapes.push_back(writePolygon(out, id));
            qDebug() << "parsed polygon";
            break;
        case 4:
            wShapes.push_back(writeRectangle(out, id));
            qDebug() << "parsed rectangle";
            break;
        case 5:
            wShapes.push_back(writeSquare(out, id));
            qDebug() << "parsed square";
            break;
        case 6:
            wShapes.push_back(writeEllipse(out, id));
            qDebug() << "parsed ellipse";
            break;
        case 7:
            wShapes.push_back(writeCircle(out, id));
            qDebug() << "parsed circle";
            break;
        case 8:
            wShapes.push_back(writeText(out, id));
            qDebug() << "parsed text";
            break;
    	}
    }

    out.close();

    return wShapes;
}

Shape* writeLine(ofstream &out, int id)
{

    int x, y, x2, y2, width = 0;
    string color, style, cap, join;
    QColor qtColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    //BrushStyle qtBrush = NoBrush; // not applicable

    out << ":" << x;
    out << "," << y;
    out << "," << x2;
    out << "," << y2 << endl;

    QPoint front(x, y);
    QPoint end(x2, y2);

    qtColor = setColor(color);
    out << ":" << color << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << style << endl;

    qtCap = setPCStyle(cap);
    out << ":" << cap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << join << endl;

    // create a pen obj to add to line
    QPen temp;
    temp.setColor(qtColor);
    temp.setWidth(width);
    temp.setStyle(qtStyle);
    temp.setCapStyle(qtCap);
    temp.setJoinStyle(qtJoin);

    Line* line = new Line(front, end, temp, id);

    return line;
}

Shape* writePolyLine(ofstream &out, int id)
{
    int width = 0;
    string color, style, cap, join;
    QColor qtColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    //BrushStyle qtBrush = NoBrush;

    gp::vector<QPoint> points;

    out << ":" << endl;

    do{
        int x, y;
        QPoint add;
        out << x << y << endl;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(out.peek() == ",");

     qtColor = setColor(color);
     out << ":" << qtColor << endl;
     out << ":" << width << endl;

     qtStyle = setPenStyle(style);
     out << ":" << qtStyle << endl;

     qtCap = setPCStyle(cap);
     out << ":" << qtCap << endl;

     qtJoin = setPJStyle(join);
     out << ":" << qtJoin << endl;

     Polyline *polyline = new Polyline(nullptr, id);
     polyline->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
     // brush is not applicable here

     // push back all points in points vector into polyline's point vector
     for(auto point: points) {
         polyline->set_point(point);
     }

    return polyline;
}

Shape* writePolygon(ofstream &out, int id)
{
    int width = 0;
    string color, style, cap, join, bStyle, bColor;
    gp::vector<QPoint> points;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    out << ":" << endl;
    do{
        int x, y;
        QPoint add;
        out << x << y << endl;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(out.peek() == ",");

    qtColor = setColor(color);
    out << ":" << qtColor << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << qtStyle << endl;

    qtCap = setPCStyle(cap);
    out << ":" << qtCap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << qtJoin << endl;

    qtBColor = setColor(bColor);
    out << ":" << qtBColor << endl;

    qtBrush = setBrushStyle(bStyle);
    out << ":" << qtBrush << endl;

    auto polygon = new Polygon(nullptr, id);
    polygon->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    polygon->set_brush(qtBColor, qtBrush);

    // push back all points in points vector into polyline's point vector
    for(int i = 0; i < points.size(); ++i) {
        polygon->set_point(points[i]);
    }

    return polygon;
}

Shape* writeRectangle(ofstream& out, int id)
{
    int x, y, width;
    int l, w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    out << ":" << x << "," << y;
    out << "," << l << "," << w << endl;

    QPoint point(x, y);

    qtColor = setColor(color);
    out << ":" << qtColor << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << qtStyle << endl;

    qtCap = setPCStyle(cap);
    out << ":" << qtCap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << qtJoin << endl;

    qtBColor = setColor(brushColor);
    out << ":" << qtBColor << endl;

    qtBrush = setBrushStyle(brushStyle);
    out << ":" << qtBrush << endl;

    auto rectangle = new Rectangle(nullptr, id);
    rectangle->set_point(point);
    rectangle->set_dimensions(l, w);

    rectangle->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    rectangle->set_brush(qtBColor, qtBrush);

    return rectangle;
}

Shape* writeSquare(ofstream& out, int id)
{
    int x, y, width;
    int w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    out << ":" << x << "," << y;
    out << "," << w << endl;

    QPoint point(x, y);

    qtColor = setColor(color);
    out << ":" << qtColor << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << qtStyle << endl;

    qtCap = setPCStyle(cap);
    out << ":" << qtCap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << qtJoin << endl;

    qtBColor = setColor(brushColor);
    out << ":" << qtBColor << endl;

    qtBrush = setBrushStyle(brushStyle);
    out << ":" << qtBrush << endl;

    auto square = new Square(nullptr, id);
    square->set_point(point);
    square->set_dimension(w);

    square->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    square->set_brush(qtBColor, qtBrush);

    return square;
}

Shape* writeEllipse(ofstream& out, int id)
{
    int x, y, width;
    int a, b;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    out << ":" << x << "," << y;
    out << "," << a << "," << b << endl;

    QPoint point(x, y);

    qtColor = setColor(color);
    out << ":" << qtColor << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << qtStyle << endl;

    qtCap = setPCStyle(cap);
    out << ":" << qtCap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << qtJoin << endl;

    qtBColor = setColor(brushColor);
    out << ":" << qtBColor << endl;

    qtBrush = setBrushStyle(brushStyle);
    out << ":" << qtBrush << endl;

    auto ellipse = new Ellipse(nullptr, id);
    ellipse->set_point(point);
    ellipse->set_dimensions(a, b);

    ellipse->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    ellipse->set_brush(qtBColor, qtBrush);

    return ellipse;
}

Shape* writeCircle(ofstream& out, int id)
{
    int x, y, width;
    int r;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    out << ":" << x << "," << y;
    out << "," << r << endl;

    QPoint point(x, y);

    qtColor = setColor(color);
    out << ":" << qtColor << endl;
    out << ":" << width << endl;

    qtStyle = setPenStyle(style);
    out << ":" << qtStyle << endl;

    qtCap = setPCStyle(cap);
    out << ":" << qtCap << endl;

    qtJoin = setPJStyle(join);
    out << ":" << qtJoin << endl;

    qtBColor = setColor(brushColor);
    out << ":" << qtBColor << endl;

    qtBrush = setBrushStyle(brushStyle);
    out << ":" << qtBrush << endl;

    auto circle = new Circle(nullptr, id);
    circle->set_point(point);
    circle->set_radius(r);

    circle->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    circle->set_brush(qtBColor, qtBrush);

    return circle;
}

Shape* writeText(ofstream& out, int id)
{
    int x , y, fontPoint, length, width;

    string color, textLine, align, fontFamily, fontStyle, fontWeight;
    QColor qtColor;

    out << ":" << x << "," << y;

    QPoint point{x, y};

    out << "," << length << "," << width << endl;

    QString qTextLine = QString::fromStdString(textLine);
    out << ":" << qTextLine << endl;

    qtColor = setColor(color);
    out << ":" << qtColor << endl;

    Qt::AlignmentFlag qtAlign = setAlignmentFlag(align);
    out << ":" << qtAlign << endl;

    out << ":" << fontPoint << endl;

    QString qtFamily = QString::fromStdString(fontFamily);
    out << ":" << qtFamily << endl;

    fontStyle = "StyleNormal";
    out << ":" << fontStyle << endl;

    QFont::Weight qtWeight = setWeight(fontWeight);
    out << ":" << qtWeight << endl;

    auto text = new Text(nullptr, id);

    text->set_point(point);
    text->set_dimensions(length, width);
    text->set_all_text(qTextLine, qtColor, qtAlign, fontPoint, qtFamily, QFont::Style::StyleNormal, qtWeight);
    text->set_pen(qtColor);

    // qDebug() << "Family:" << qtFamily;

    return text;
}

QColor setColor(string color)
{
    if(color == " white"){
        return white;
    }
    else if(color == " black"){
        return black;
    }
    else if(color == " red"){
        return red;
    }
    else if(color == " green"){
        return green;
    }
    else if(color == " blue"){
        return blue;
    }
    else if(color == " cyan"){
        return cyan;
    }
    else if(color == " magenta"){
        return magenta;
    }
    else if(color == " yellow"){
        return yellow;
    }
    else if(color == " gray"){
        return gray;
    } else {
        return black;
    }
}

PenStyle setPenStyle(string style)
{
    if(style == " NoPen"){
        return NoPen;
    }
    else if(style == " SolidLine"){
        return SolidLine;
    }
    else if(style == " DashLine"){
        return DashLine;
    }
    else if(style == " DotLine"){
        return DotLine;
    }
    else if(style == " DashDotLine"){
        return DashDotLine;
    }
    else if(style == " DashDotDotLine"){
        return DashDotDotLine;
    }else {
        return NoPen;
    }
}

PenCapStyle setPCStyle(string cap)
{
    if(cap == " FlatCap"){
        return FlatCap;
    }
    else if(cap == " SquareCap"){
        return SquareCap;
    }
    else if(cap == " RoundCap"){
        return RoundCap;
    }else {
        return FlatCap;
    }
}

PenJoinStyle setPJStyle(string join)
{
    if(join == " MiterJoin"){
        return MiterJoin;
    }
    else if(join == " BevelJoin"){
        return BevelJoin;
    }
    else if(join == " RoundJoin"){
        return RoundJoin;
    } else {
        return MiterJoin;
    }
}

BrushStyle setBrushStyle(string brush)
{
    if(brush == " SolidPattern"){
        return SolidPattern;
    }
    else if(brush == " HorPattern"){
        return HorPattern;
    }
    else if(brush == " VerPattern"){
        return VerPattern;
    }
    else if(brush == " NoBrush"){
        return NoBrush;
    } else {
        return SolidPattern;
    }
}

Qt::AlignmentFlag setAlignmentFlag(string flag)
{
    if(flag == "AlignLeft"){
        return Qt::AlignmentFlag::AlignLeft;
    } else if(flag == "AlignRight"){
        return Qt::AlignmentFlag::AlignRight;
    }else if(flag == "AlignTop"){
        return Qt::AlignmentFlag::AlignTop;
    }else if(flag == "AlignBottom"){
        return Qt::AlignmentFlag::AlignBottom;
    } else if(flag == "AlignCenter"){
        return Qt::AlignmentFlag::AlignCenter;
    } else {
        return Qt::AlignmentFlag::AlignLeft;
    }
}

QFont::Weight setWeight(string weight)
{
    if(weight == "Thin"){
        return QFont::Thin;
    } else if(weight == "Light"){
        return QFont::Light;
    }else if(weight == "Normal"){
        return QFont::Normal;
    }else if(weight == "Bold"){
        return QFont::Bold;
    } else {
        return QFont::Normal;
    }
}
