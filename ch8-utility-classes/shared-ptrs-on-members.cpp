#include <iostream>
#include <memory>
#include <string>

struct person
{
  std::string name;
  int age;

  person(std::string n, int a) : name(n), age(a)
  {
    std::cout << "CTOR: " << name << '\n';
  }

  ~person()
  {
    std::cout << "DTOR: " << name << '\n';
  }
};

int main()
{
  std::shared_ptr<std::string> shared_name;
  std::shared_ptr<int> shared_age;

  {
    auto shared_person = std::make_shared<person>("John Doe", 30);

    shared_name = std::shared_ptr<std::string>(shared_person, &shared_person->name);
    shared_age = std::shared_ptr<int>(shared_person, &shared_person->age);
  }

  std::cout << "name: " << *shared_name << ", age: " << *shared_age << '\n';
}
