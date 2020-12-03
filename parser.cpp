// parser.cpp by Paul Jo

#include "parser.h"


gp::vector<Shape*> ParseFile(int size){
    ifstream in("shapes.txt"); // change location for needs

    const QString FILE_NAME = "shapes.txt";

    if(!in){
        QMessageBox fileNotFoundError;
        fileNotFoundError.setText("ERR: \"" + FILE_NAME +"\" not found!");
        fileNotFoundError.exec();
        exit(-1);
    }
    else
    {
        // find path to shapes.txt
        QString shapePath = qApp->applicationDirPath();
        shapePath.append('/' + FILE_NAME);
        qDebug() << "path to shapes.txt: " << shapePath;
        QTextStream in(&shapePath);
    }




    gp::vector<Shape*> rShapes(size);

    while (in){
        string temp;
        int id;

        in.ignore('\n');

        in.ignore(numeric_limits<streamsize>::max(), ':');
        in >> id;
        in.ignore(numeric_limits<streamsize>::max(), ':');
        getline(in, temp);

	if (in.eof()) break;
	    
        switch(id){
        case 1:
            rShapes.push_back(readLine(in, id));
            break;
        case 2:
            rShapes.push_back(readPolyLine(in, id));
            break;
        case 3:
            rShapes.push_back(readPolygon(in, id));
            break;
        case 4:
            rShapes.push_back(readRectangle(in, id));
            break;
        case 5:
            rShapes.push_back(readSquare(in, id));
            break;
        case 6:
            rShapes.push_back(readEllipse(in, id));
            break;
        case 7:
            rShapes.push_back(readCircle(in, id));
            break;
        case 8:
            rShapes.push_back(readText(in, id));
            break;
        default:
            qDebug() << "Parser.cpp: invalid shape detected.";
            break;
        }
    }

    in.close();
    return rShapes;
}

Shape* readLine(ifstream &in, int id)
{
	
    int x, y, x2, y2, width;
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
    Polyline *polyline = new Polyline(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);
	
    int width;
    string color, style, cap, join;
    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush = NoBrush;

    vector<QPoint> points;


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

    return polyline;
}

Shape* readPolygon(ifstream &in, int id)
{
    Polygon *polygon = new Polygon(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);
    
    int width;
    string color, style, cap, join, bStyle, bColor;
    vector<QPoint> points;

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

    return polygon;
}


Shape* readRectangle(ifstream& in, int id)
{
	
    Rectangle *rectangle = new Rectangle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, l, w, x, y);
    
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
	
	
    return rectangle;
}

Shape* readSquare(ifstream& in, int id)
{
    Square *square = new Square(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, w, x, y);
    
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
	
    return square;
}

Shape* readEllipse(ifstream& in, int id)
{
    Ellipse *ellipse = new Ellipse(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, a, b, x, y); 

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
	
    return ellipse;
}

Shape* readCircle(ifstream& in, int id)
{
    Circle *circle = new Circle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, r, x, y);
	
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

    //QPoint point(x + r, y + r); idk yet

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
	
    return circle;
}


Shape* readText(ifstream& in, int id)
{
    Text *text = new Text(black, qtColor, SolidLine, FlatCap, MiterJoin, SolidPattern, fontPoint, id, align, fontFamily, fontStyle, fontWeight, textLine, x, y, length, width);
	
    int x , y, fontPoint, length, width;

    string color, textLine, align, fontFamily, fontStyle, fontWeight;
    QColor qtColor;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> x;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> y;

    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> length;
    in.ignore(numeric_limits<streamsize>::max(), ',');
    in >> width;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, textLine);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, color);
    qtColor = getColor(color);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, align);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    in >> fontPoint;

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, fontFamily);

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, fontStyle);
    fontStyle = " StyleNormal";

    in.ignore(numeric_limits<streamsize>::max(), ':');
    getline(in, fontWeight);

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
    }
}
