// parser.cpp by Paul Jo

#include "parser.h"
//#include <QColor>

gp::vector<Shape*> ParseFile(int size){
    ifstream in("shapes.txt"); // change location for needs

    if(!in){
        cout << "File didn't open.";
        exit(1);
    }
    else
    {
    	in.open("shapes.txt");
    }

    gp::vector<Shape*> rShapes(size);

    while (!in.eof())
    {
    	readShapes(in);
    }

    while (in){
        string temp;
        int id;

        in.ignore('\n');

        in.ignore(numeric_limits<streamsize>::max(), ':');
        in >> id;
        in.ignore(numeric_limits<streamsize>::max(), ':');
        getline(in, temp);

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
            cout << "Error parser.cpp" << endl;
            break;
        }
    }

    in.close();
    return rShapes;
}

void readShapes(ifstream &in)
{
	int AR_SIZE = 7;
	int index = 1;
	int dim_SIZE = 8;
	shapeAr shapeArray[];
	textAr textArray[];

	while (in && index <= AR_SIZE)
	{
		in >> shapeArray[index].id;
		getline(in, shapeArray[index].type);

		int dimIndex = 0;
		while (dimIndex < dim_SIZE)
		{
			in >> shapeArray[index].dimensionAr[dimIndex];
		}

		getline(in, shapeArray[index].qtColor);
		in >> shapeArray[index].width;
		getline(in, shapeArray[index].qtStyle);
		getline(in, shapeArray[index].qtCap);
		getline(in, shapeArray[index].qtJoin);
		getline(in, shapeArray[index].qtBColor);
		getline(in, shapeArray[index].qtBStyle);
		in.ignore(numeric_limits<streamsize>::max(), ':');

		index++;
	}

	in >> textArray[index].id;
	getline(in, textArray[index].type);

	int dimIndex = 0;
	index = 1;
	while (dimIndex < dim_SIZE)
	{
		in >> shapeArray[index].dimensionAr[dimIndex];
	}

	getline(in, textArray[index].textString);
	getline(in, textArray[index].textColor);
	getline(in, textArray[index].textAlignment);
	in >> textArray[index].textPointSize;
	getline(in, textArray[index].textFontFamily);
	getline(in, textArray[index].textFontStyle);
	getline(in, textArray[index].textFontWeight);
	in.ignore(numeric_limits<streamsize>::max(), ':');
}

// All of the functions below are skeleton works.

Shape* readLine(ifstream &in, int id)
{
	int index = 1;
	shapeAr shapeArray[];
	bool found;
	int dim_SIZE = 8;
	string str;

	Line *line = new Line(qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, front, end);

	while (in && found == false)
	{
		if (shapeArray[index].id == id)
		{
			in >> str;
			if (str == "ShapeType:")
				getline(in, line->ShapeType);

			in >> str;
			int dimIndex = 0;
			while(dimIndex < dim_SIZE)
				if (str == "ShapeDimensions:")
					in >> line->dimensionAr;
					in.ignore(numeric_limits<streamsize>::max(), '\n');

			in >> str;
			if (str == "PenColor:")
				getline(in, line->qtColor);

			in >> str;
			if (str == "PenWidth:")
				in >> line->width;
        		in.ignore(numeric_limits<streamsize>::max(), '\n');

			in >> str;
			if (str == "PenStyle:")
				getline(in, line->qtStyle);

			in >> str;
			if (str == "PenCapStyle:")
				getline(in, line->qtCap);

			in >> str;
			if (str == "PenJoinStyle:")
				getline(in, line->qtJoin);

			in >> str;
			if (str == "BrushColor:")
				getline(in, line->gtBColor);

			in >> str;
			if (str == "BrushStyle:")
				getline(in, line->gtBrush);

			in.ignore(numeric_limits<streamsize>::max(), ':');
			found = true;
		}
		else
		{
			index++;
		}
	}

    return line;
}

Shape* readPolyLine(ifstream &in, int id)
{
	int index = 1;
	shapeAr shapeArray[];
	bool found;
	int dim_SIZE = 8;
	string str;

    Polyline *polyline = new Polyline(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);

	while (in && found == false)
	{
		if (shapeArray[index].id == id)
		{
			in >> str;
			if (str == "ShapeType:")
				getline(in, line->ShapeType);

			in >> str;
			int dimIndex = 0;
			while(dimIndex < dim_SIZE)
				if (str == "ShapeDimensions:")
					in >> line->dimensionAr;
					in.ignore(numeric_limits<streamsize>::max(), '\n');

			in >> str;
			if (str == "PenColor:")
				getline(in, line->qtColor);

			in >> str;
			if (str == "PenWidth:")
				in >> line->width;
        		in.ignore(numeric_limits<streamsize>::max(), '\n');

			in >> str;
			if (str == "PenStyle:")
				getline(in, line->qtStyle);

			in >> str;
			if (str == "PenCapStyle:")
				getline(in, line->qtCap);

			in >> str;
			if (str == "PenJoinStyle:")
				getline(in, line->qtJoin);

			in >> str;
			if (str == "BrushColor:")
				getline(in, line->gtBColor);

			in >> str;
			if (str == "BrushStyle:")
				getline(in, line->gtBrush);

			in.ignore(numeric_limits<streamsize>::max(), ':');
			found = true;
		}
		else
		{
			index++;
		}
	}

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
    getline(in, polygon-qtColor);
    //qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, bColor);
    qtBColor = getColor(bColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, bStyle);
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


    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;

    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> w;

    QPoint point(x, y);


    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushColor);
    qtBColor = getColor(brushColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushStyle);
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
    inFile >> fontPoint;

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
