// #include <math.h>
// #include <iostream>
// using namespace std;

// class Point {
//    private:
//     double x, y;

//    public:
//     Point(double _x, double _y) : x(_x), y(_y) {}
//     double getX() { return x; }
//     double getY() { return y; }
// };

class Segment {
   private:
    Point p1, p2;

   public:
    Segment(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
    double length() {
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return sqrt(dx * dx + dy * dy);
    }
    Point getEnd(int endPoint) {
        if (endPoint == 0)
            return p1;
        else
            return p2;
    }
};

// int main() {
//     Point point1(0, 0);
//     Point point2(3, 4);

//     Segment segment(point1, point2);

//     cout << "Length of the segment: " << segment.length() << endl;

//     Point endPoint = segment.getEnd(0);
//     cout << "End point 1: (" << endPoint.getX() << ", " << endPoint.getY()
//          << ")" << endl;

//     endPoint = segment.getEnd(1);
//     cout << "End point 2: (" << endPoint.getX() << ", " << endPoint.getY()
//          << ")" << endl;

//     return 0;
// }