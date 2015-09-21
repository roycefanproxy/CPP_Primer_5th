#ifndef _15_21_h_
#define _15_21_h_
#include <string>
#include <iostream>
#include <cmath>

class Shape;
void print(std::ostream&, const Shape&);
inline double sqr(const double& val) { return val * val; }

class Shape
{
	friend void print(std::ostream&, const Shape&);
public:
	Shape() = default;
	Shape(const std::string& s, const double& b, const double& w, const double& h)
		: name_obj(s), length(b), width(w), height(h) {}
	~Shape() = default;
	virtual double surf_area() const = 0;
	virtual double volume() const = 0;
	std::string name() const { return name_obj; }
protected:
	double length = 0.0, width = 0.0, height = 0.0;
	std::string name_obj = "unknown";
};

class Cube : public Shape
{
public:
	Cube() = default;
	Cube(const std::string& s, const double& b)
		: Shape(s, b, b, b) {}
	double surf_area() const override { return length * width * 6; }
	double volume() const override { return length * width * height; }
};

class Pyramid : public Shape
{
public:
	Pyramid() = default;
	Pyramid(const std::string& s, const double& b, const double& w, const double& h)
		: Shape(s, b, w, h) {}
	double surf_area() const override
	{
		auto half_l = length / 2, half_w = width / 2;
		auto area_a = sqrt((sqr(half_l / 2) + sqr(height))) * width;
		auto area_b = sqrt((sqr(half_w / 2) + sqr(height))) * length;
		return length * width + area_a + area_b;
	}

	double volume() const override
	{
		return length * width * height / 3;
	}
};

class Cone : public Shape
{
public:
	Cone() = default;
	Cone(const std::string& s, const double& r, const double& h)
		: Shape(s, r, r, h) {}
	double surf_area() const override
	{
		auto r_x_r = sqr(width / 2);
		auto circle = M_PI * r_x_r;
		auto sector_a = M_PI * width / 2 * sqrt(sqr(height) + sqr(width / 2));
		return sector_a + circle;	
	}

	double volume() const override
	{
		auto r_x_r = sqr(width / 2);
		return r_x_r * M_PI * height / 3;
	}
};

class Box : public Shape
{
public:
	Box() = default;
	Box(const std::string& s, const double& b, const double& w, const double& h)
		: Shape(s, b, w, h) {}
	double surf_area() const override
	{
		auto side_a = width * height;
		auto side_b = width * length;
		auto side_c = length * height;
		return side_a * 2 + side_b * 2 + side_c * 2;
	}

	double volume() const override
	{
		return length * width * height;
	}
};

inline void print(std::ostream& os, const Shape& s)
{
	os << s.name() << ' ' << "surface area : " << s.surf_area() << " volume : " << s.volume() << std::endl;
}

#endif // _15_21_h_
