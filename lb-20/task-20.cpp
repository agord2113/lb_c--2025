#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;
    string city; // Added city member
};

void print(Person person)
{
    cout << person.name << " is " << person.age << " years old and lives in " << person.city << endl;
}

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.city = "New York"; // Assign a city
    cout << "Meet " << person.name << ". "; // Corrected output
    print(person);

    return 0;
}
