#include "logger.h"
#include "sstream"

using namespace std;

struct Tree {
private:
	string _name;
	int _age;
	float _height;
	bool _is_fruit_bearing;

	string _get_object_as_string() const {
		stringstream ss;
		ss << "<" << (void**)this << ">";
		return ss.str();
	}

	void set_default_values() {
		_name = "unnamed";
		_age = 0;
		_height = 0.0f;
		_is_fruit_bearing = false;
	}

public:
	Tree() { // Constructor
		Logger::log("Object created " + _get_object_as_string(), Colors::GREEN);
		set_default_values();
	}
	Tree(string name) : Tree() {
		Logger::log("Object created with parram <NAME> " + _get_object_as_string(), Colors::GREEN);
		set_name(name);
	}
	Tree(string name, int age) : Tree(name) {
		Logger::log("Object created with parram <NAME, AGE> " + _get_object_as_string(), Colors::GREEN);
		set_age(age);
	}
	Tree(string name, int age, float height) : Tree(name, age) {
		Logger::log("Object created with parram <NAME, AGE, HEIGHT> " + _get_object_as_string(), Colors::GREEN);
		set_height(height);
	}
	Tree(string name, int age, float height, bool is_fruit_bearing) : Tree(name, age, height) {
		Logger::log("Object created with parram <NAME, AGE, HEIGHT, IS_FRUIT_BEARING> " + _get_object_as_string(), Colors::GREEN);
		set_is_fruit_bearing(is_fruit_bearing);
	}

	// Setters
	void set_name(string name) { _name = name; }
	void set_age(int age) { _age = age; }
	void set_height(float height) { _height = height; }
	void set_is_fruit_bearing(bool is_fruit_bearing) { _is_fruit_bearing = is_fruit_bearing; }

	// Getters
	string get_name()const { return _name; }
	int get_age()const { return _age; }
	float get_height()const { return _height; }
	bool get_is_fruit_bearing()const { return _is_fruit_bearing; }

	// Fucntions
	void grow() {
		Logger::log("Tree is growing...", Colors::BLUE);
		_age++;
		_height += 0.5f;
	}

	void about() {
		Logger::log("Name:\t\t" + _name, Colors::YELLOW);
		Logger::log("Age:\t\t" + to_string(_age), Colors::YELLOW);
		Logger::log("Height:\t\t" + to_string(_height), Colors::YELLOW);
		Logger::log("Is fruit bearing:\t" + string(_is_fruit_bearing ? "Yes" : "No"), Colors::YELLOW);

	}

	~Tree() { // Destructor
		Logger::log("Object destroyed " + _get_object_as_string(), Colors::RED);
	}
};

bool Logger::is_print_logs = true;

int main()
{
	Tree* tree = new Tree("Oak", 64, 302.5, false);

	cout << endl;
	tree->about();
	cout << endl;
	tree->grow();
	cout << endl;

	delete tree;
	return 0;
}