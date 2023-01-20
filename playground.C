    
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <array>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>
#include <tuple>
#include <memory>

#define FOR(i,n) for(int i = 0; i < (int)n; i++)
using IntVec = std::vector< int >;
using StrVec = std::vector< std::string >;



struct Point {
    int x, y;
};

struct MinMaxResult {
    std::array< Point, 2 > minPts;
    std::array< Point, 2 > maxPts;
};

bool operator ==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator !=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

bool operator ==(const MinMaxResult& p1, const MinMaxResult& p2) {

    bool ok = false;
    for(int i = 0; i < 2; i++) {
        ok |= ((p1.minPts[i] == p2.minPts[i] && p1.minPts[1-i] == p2.minPts[1-i]) &&
               (p1.maxPts[i] == p2.maxPts[i] && p1.maxPts[1-i] == p2.maxPts[1-i]));
    }
    return ok;
}

std::ostream& operator << (std::ostream& ofs, const Point& pt) {
    ofs << pt.x << "," << pt.y;
    return ofs;
}

using PointVec = std::vector< Point >;

MinMaxResult computeDistance(const PointVec& points) {

    size_t n = points.size();
    if(n <= 1)
        throw std::runtime_error("Point vector is too small!");

    struct Idx {
        size_t i = -1u, j = -1u;
    };

    Idx imin, imax;
    double distMin = std::numeric_limits< double >::max(),
           distMax = 0;

    for(size_t i = 0; i < n - 1; i++) {

        const auto& pt = points[i];
        for(size_t j = i + 1; j < n; j++) {
            int dx = pt.x - points[j].x,
                dy = pt.y - points[j].y;

            double dist = (double)dx*dx + (double)dy*dy;
            if(dist < distMin) {
                distMin = dist;
                imin = {i, j};
            }
            if(dist > distMax) {
                distMax = dist;
                imax = {i, j};
            }
        }
    }

    return { {points[imin.i], points[imin.j]}, {points[imax.i], points[imax.j]} };
}

// testing: 0 or 1 points
// all points same coordinates..
// a big set of random points
// points with very large integer coordiantes
// points on a rect grid

void invalidPointsTest() {

    try {
        computeDistance({});
        assert(false);
    }
    catch(std::exception&) {
    }

    try {
        PointVec v;
        computeDistance(std::move(v));
        assert(false);
    }
    catch(std::exception&) {
    }
}

//void equalPointsTest() {

//    PointVec pt(100, {3, 4});
//    auto res = computeDistance(pt);

//    assert(res[0] == res[1] && res[2] == res[3]);
//}

void randomPointsTest() {

    // 4,4, 3,2; maxPt: 1,4, 5,1
    MinMaxResult reference = { { Point{4,4}, Point{5,1}},
                               { Point{1,4}, Point{5,1}} };

    PointVec pt = { { 1, 4 }, { 4, 4 }, { 3, 2 }, { 5, 1 } };
    auto res = computeDistance(pt);

    assert(res == reference);
}

int main(int nargs, char **vargs)
{
    PointVec points = { { 1, 4 }, { 4, 4 }, { 3, 2 }, { 5, 1 } };

    try {
        auto res = computeDistance(points);

        std::cout << "minPt: " << res.minPts[0] << ", " << res.minPts[1] <<
                     "; maxPt: " << res.maxPts[0] << ", " << res.maxPts[1] << std::endl;

        randomPointsTest();
    }
    catch(std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}

