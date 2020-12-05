// parser.cpp by Paul Jo

#include "parser.h"


gp::vector<Shape*> ParseFile(){
    const QString FILE_NAME = "shapes.txt";
    bool done = false;

    QString shapePath = qApp->applicationDirPath();
    shapePath.append('/' + FILE_NAME);
    qDebug() << "path to shapes.txt: " << shapePath;
    QFile shapeFile(shapePath);

    if(!shapeFile.exists()){
        QMessageBox fileNotFoundError;
        fileNotFoundError.setText("ERR: \"" + FILE_NAME +"\" not found!");
        fileNotFoundError.exec();
        exit(-1);
    }

    // file exists at this point
    ifstream in(shapePath.toStdString());

    gp::vector<Shape*> rShapes;

    while (!done){
        string temp;
        string idStr;
        int id;
        string dummy;

        getline(in, dummy);

        in.ignore(9);
        in >> idStr;
        in.ignore(11);
        getline(in, temp);

        //qDebug() << QString::fromStdString(idStr);

        if (in.peek() == EOF) {
            done = true;
            //qDebug() << "Reached EOF";
        }

        if(!done) {
            id = std::stoi(idStr);

            switch(id){
            case 1:
                rShapes.push_back(readLine(in, id));
                //qDebug() << "parsed line";
                break;
            case 2:
                rShapes.push_back(readPolyLine(in, id));
                //qDebug() << "parsed polyline";
                break;
            case 3:
                rShapes.push_back(readPolygon(in, id));
                //qDebug() << "parsed polygon";
                break;
            case 4:
                rShapes.push_back(readRectangle(in, id));
                //qDebug() << "parsed rectangle";
                break;
            case 5:
                rShapes.push_back(readSquare(in, id));
                //qDebug() << "parsed square";
                break;
            case 6:
                rShapes.push_back(readEllipse(in, id));
                //qDebug() << "parsed ellipse";
                break;
            case 7:
                rShapes.push_back(readCircle(in, id));
                //qDebug() << "parsed circle";
                break;
            case 8:
                rShapes.push_back(readText(in, id));
                //qDebug() << "parsed text";
                break;
            default:
                //qDebug() << "Parser.cpp: invalid shape detected.";
                break;
            }
        }
    }

    in.close();

    return rShapes;
}

Shape* readLine(ifstream &in, int id)
{
	
    int x, y, x2, y2, width = 0;
    string color, style, cap, join;
    QColor qtColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    //BrushStyle qtBrush = NoBrush; // not applicable

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> x2;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y2;

    QPoint front(x, y);
    QPoint end(x2, y2);

    in.ignore(numeric_limits<streamsize>::max(), ':'); // get color
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':'); // get width
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':'); // get style
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':'); // get cap
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':'); // get join
    getline(in, join);
    qtJoin = getPJStyle(join);

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

Shape* readPolyLine(ifstream &in, int id)
{	
    int width = 0;
    string color, style, cap, join;
    QColor qtColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    //BrushStyle qtBrush = NoBrush;

    gp::vector<QPoint> points;


    in.ignore(numeric_limits<streamsize>::max(), ':');

    do{
        int x, y;
        QPoint add;
        in.get();
        in >> x;
        in.get();
        in >> y;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(in.peek() == ',');

     in.ignore(numeric_limits<streamsize>::max(), ':');
     getline(in, color);
     qtColor = getColor(color);

     in.ignore(numeric_limits<streamsize>::max(), ':');
     in >> width;

     in.ignore(numeric_limits<streamsize>::max(), ':');
     getline(in, style);
     qtStyle = getPenStyle(style);

     in.ignore(numeric_limits<streamsize>::max(), ':');
     getline(in, cap);
     qtCap = getPCStyle(cap);

     in.ignore(numeric_limits<streamsize>::max(), ':');
     getline(in, join);
     qtJoin = getPJStyle(join);

     Polyline *polyline = new Polyline(nullptr, id);
     polyline->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
     // brush is not applicable here

     // push back all points in points vector into polyline's point vector
     for(auto point: points) {
         polyline->set_point(point);
     }

    return polyline;
}

Shape* readPolygon(ifstream &in, int id)
{
    int width = 0;
    string color, style, cap, join, bStyle, bColor;
    gp::vector<QPoint> points;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    do{
        int x, y;
        QPoint add;
        in.get();
        in >> x;
        in.get();
        in >> y;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(in.peek() == ',');

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, join);
    qtJoin = getPJStyle(join);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, bColor);
    qtBColor = getColor(bColor);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, bStyle);
    qtBrush = getBrushStyle(bStyle);

    auto polygon = new Polygon(nullptr, id);
    polygon->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    polygon->set_brush(qtBColor, qtBrush);

    // push back all points in points vector into polyline's point vector
    for(int i = 0; i < points.size(); ++i) {
        polygon->set_point(points[i]);
    }

    return polygon;
}


Shape* readRectangle(ifstream& in, int id)
{   
    int x, y, width;
    int l, w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;


    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> l;
    in.ignore(numeric_limits<streamsize>::max(), ','); // right here
    in >> w;

    QPoint point(x, y);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, join);
    qtJoin = getPJStyle(join);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushColor);
    qtBColor = getColor(brushColor);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushStyle);
    qtBrush = getBrushStyle(brushStyle);
	
    auto rectangle = new Rectangle(nullptr, id);
    rectangle->set_point(point);
    rectangle->set_dimensions(l, w);

    rectangle->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    rectangle->set_brush(qtBColor, qtBrush);

    return rectangle;
}

Shape* readSquare(ifstream& in, int id)
{   
    int x, y, width;
    int w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;


    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in>> y;

    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> w;

    QPoint point(x, y);


    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, join);
    qtJoin = getPJStyle(join);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushColor);
    qtBColor = getColor(brushColor);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushStyle);
    qtBrush = getBrushStyle(brushStyle);
	
    auto square = new Square(nullptr, id);
    square->set_point(point);
    square->set_dimension(w);

    square->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    square->set_brush(qtBColor, qtBrush);

    return square;
}

Shape* readEllipse(ifstream& in, int id)
{
    int x, y, width;
    int a, b;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;

    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> a;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> b;

    QPoint point(x, y);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, join);
    qtJoin = getPJStyle(join);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushColor);
    qtBColor = getColor(brushColor);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushStyle);
    qtBrush = getBrushStyle(brushStyle);
	
    auto ellipse = new Ellipse(nullptr, id);
    ellipse->set_point(point);
    ellipse->set_dimensions(a, b);

    ellipse->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    ellipse->set_brush(qtBColor, qtBrush);

    return ellipse;
}

Shape* readCircle(ifstream& in, int id)
{	
    int x, y, width;
    int r;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;

    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> r;

    QPoint point(x, y);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, style);
    qtStyle = getPenStyle(style);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, cap);
    qtCap = getPCStyle(cap);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, join);
    qtJoin = getPJStyle(join);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushColor);
    qtBColor = getColor(brushColor);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, brushStyle);
    qtBrush = getBrushStyle(brushStyle);
	
    auto circle = new Circle(nullptr, id);
    circle->set_point(point);
    circle->set_radius(r);

    circle->set_pen(qtColor, width, qtStyle, qtCap, qtJoin);
    circle->set_brush(qtBColor, qtBrush);


    return circle;
}


Shape* readText(ifstream& in, int id)
{	
    int x , y, fontPoint, length, width;

    string color, textLine, align, fontFamily, fontStyle, fontWeight;
    QColor qtColor;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;

    QPoint point{x, y};

    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> length;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, textLine);
    QString qTextLine = QString::fromStdString(textLine);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    //in.ignore(1);
    getline(in, color);
    //qDebug() << QString::fromStdString(color);
    qtColor = getColor(color);
    //qDebug() << qtColor;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, align);
    Qt::AlignmentFlag qtAlign = getAlignmentFlag(align);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> fontPoint;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in.ignore(1);
    getline(in, fontFamily);
    QString qtFamily = QString::fromStdString(fontFamily);

    in.ignore(numeric_limits<streamsize>::max(), ':'); // Not given?
    getline(in, fontStyle);
    fontStyle = "StyleNormal";

    in.ignore(numeric_limits<streamsize>::max(), ':'); // TODO
    getline(in, fontWeight);
    QFont::Weight qtWeight = getWeight(fontWeight);

    auto text = new Text(nullptr, id);

    text->set_point(point);
    text->set_dimensions(length, width);
    text->set_all_text(qTextLine, qtColor, qtAlign, fontPoint, qtFamily, QFont::Style::StyleNormal, qtWeight);
    text->set_pen(qtColor);

    // qDebug() << "Family:" << qtFamily;

    return text;
}

QColor getColor(string color)
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

PenStyle getPenStyle(string style)
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

PenCapStyle getPCStyle(string cap)
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

PenJoinStyle getPJStyle(string join)
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

BrushStyle getBrushStyle(string brush)
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

Qt::AlignmentFlag getAlignmentFlag(string flag)
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

QFont::Weight getWeight(string weight)
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
