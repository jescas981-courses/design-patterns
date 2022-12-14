#pragma once
#include <vector>
#include <iterator>
#include <boost/functional/hash.hpp>
#include <map>
#include <memory>
#include <iostream>

struct Point {
    int x, y;
    friend std::size_t hash_value(const Point& obj) {
        std::size_t seed = 0x1E44943F;
        boost::hash_combine(seed, obj.x);
        boost::hash_combine(seed, obj.y);
        return seed;
    }
};

struct Line {
    Point start, end;
    friend std::size_t hash_value(const Line& obj) {
        std::size_t seed = 0x4D274623;
        boost::hash_combine(seed, obj.start);
        boost::hash_combine(seed, obj.end);
        return seed;
    }
};

struct VectorObject {
    virtual std::vector<Line>::iterator begin() = 0;
    virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject {
    VectorRectangle(int x, int y, int width, int height) {
        lines.emplace_back(Line{Point{x, y}, Point{x + width, y}});
        lines.emplace_back(
            Line{Point{x + width, y}, Point{x + width, y + height}});
        lines.emplace_back(Line{Point{x, y}, Point{x, y + height}});
        lines.emplace_back(
            Line{Point{x, y + height}, Point{x + width, y + height}});
    }

    std::vector<Line>::iterator begin() override { return lines.begin(); }
    std::vector<Line>::iterator end() override { return lines.end(); }

   private:
    std::vector<Line> lines;
};

struct LineToPointAdapter {
    typedef std::vector<Point> Points;

    LineToPointAdapter(Line& line) {
        static int count = 0;
        std::cout << "Computing rectangle line number " << ++count << std::endl;

        // no interpolation
        int left = std::min(line.start.x, line.end.x);
        int right = std::max(line.start.x, line.end.x);
        int top = std::min(line.start.y, line.end.y);
        int bottom = std::max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;

        // only vertical or horizontal lines
        if (dx == 0) {
            // vertical
            for (int y = top; y <= bottom; ++y) {
                points.emplace_back(Point{left, y});
            }
        } else if (dy == 0) {
            for (int x = left; x <= right; ++x) {
                points.emplace_back(Point{x, top});
            }
        }
    }

    virtual Points::iterator begin() { return points.begin(); }
    virtual Points::iterator end() { return points.end(); }

   private:
    Points points;
};

struct LineToPointCachingAdapter {
    typedef std::vector<Point> Points;

    LineToPointCachingAdapter(Line& line) {
        boost::hash<Line> hash;
        line_hash = hash(line);
        if (cache.find(line_hash) != cache.end()) return;

        static int count = 0;
        std::cout << "Computing rectangle line number " << ++count << std::endl;

        // no interpolation
        Points points;

        int left = std::min(line.start.x, line.end.x);
        int right = std::max(line.start.x, line.end.x);
        int top = std::min(line.start.y, line.end.y);
        int bottom = std::max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;

        // only vertical or horizontal lines
        if (dx == 0) {
            // vertical
            for (int y = top; y <= bottom; ++y) {
                points.emplace_back(Point{left, y});
            }
        } else if (dy == 0) {
            for (int x = left; x <= right; ++x) {
                points.emplace_back(Point{x, top});
            }
        }

        cache[line_hash] = points;
    }

    virtual Points::iterator begin() { return cache[line_hash].begin(); }
    virtual Points::iterator end() { return cache[line_hash].end(); }

   private:
    size_t line_hash;
    static std::map<size_t, Points> cache;
};

std::map<size_t, std::vector<Point>> LineToPointCachingAdapter::cache;
