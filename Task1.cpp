#include <iostream>
#include <string>

class Toy {
private:
	std::string name;
public:
	Toy(const std::string& _name) : name(_name) {}
	std::string get_name() {
		return name;
	}
	~Toy() {
		std::cout << "Toy " << name << " was dropped" << std::endl;
	}
};

class Dog {
private:
	std::shared_ptr<Toy> currentToy;
	std::string name;
public:
	Dog(std::string _name) : name(_name), currentToy(nullptr) {}
	void get_toy(std::shared_ptr<Toy> t) {
		if (t == nullptr) {
			std::cout << "No toys to get" << std::endl;
			return;
		}
		if (currentToy == t)
			std::cout << this->name << " is already playing with this toy!" << std::endl;
		else if (currentToy)
			std::cout << this->name << " is already playing with another toy!" << std::endl;
		else if (t.use_count() > 2)
			std::cout << "Another dog is already playing with this toy! That's why " << this->name  << " can't get it." << std::endl;
		else {
			currentToy = t;
			std::cout << this->name << " got the toy: " << currentToy->get_name() << std::endl;
		}
	}
	void drop_toy() {
		if (currentToy) {
			std::cout << this->name << " drops " << currentToy->get_name() << std::endl;
			currentToy.reset();
		}
		else std::cout << "Nothing to drop." << std::endl;
	}
};

int main() {
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
	std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");
	std::shared_ptr<Toy> nothing;

	Dog tuzik("Tuzik");
	Dog sharik("Sharik");

	sharik.get_toy(ball);
	tuzik.get_toy(ball);
	sharik.drop_toy();
	tuzik.get_toy(ball);
	tuzik.get_toy(bone);
}