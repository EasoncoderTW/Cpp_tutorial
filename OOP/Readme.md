# C++ Object-Oriented Programming Tutorial

In this tutorial, we will explore the fundamental concepts of object-oriented programming (OOP) in C++. We will cover classes, objects, inheritance, polymorphism, encapsulation, and abstraction. Each section includes examples and exercises to help you understand and apply these concepts.

## Introduction to Object-Oriented Programming

Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects," which can contain data and methods. The key principles of OOP are encapsulation, inheritance, and polymorphism.

## Classes and Objects

### Classes

A class is a blueprint for creating objects. It defines attributes (data members) and methods (member functions).

#### Example: Defining a Class
```cpp
#include <iostream>
#include <string>

class Car {
public:
    std::string brand;
    std::string model;
    int year;

    void displayInfo() {
        std::cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << std::endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;
    car1.displayInfo();
    return 0;
}
```

### Objects

Objects are instances of a class. They hold specific values for the attributes defined in the class.

#### Example: Creating and Using Objects
```cpp
#include <iostream>
#include <string>

class Car {
public:
    std::string brand;
    std::string model;
    int year;

    void displayInfo() {
        std::cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << std::endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;

    Car car2;
    car2.brand = "Honda";
    car2.model = "Civic";
    car2.year = 2019;

    car1.displayInfo();
    car2.displayInfo();

    return 0;
}
```

## Inheritance

Inheritance allows a class (derived class) to inherit attributes and methods from another class (base class).

#### Example: Inheritance
```cpp
#include <iostream>
#include <string>

class Vehicle {
public:
    std::string brand;
    void honk() {
        std::cout << "Honk! Honk!" << std::endl;
    }
};

class Car : public Vehicle {
public:
    std::string model;
    int year;

    void displayInfo() {
        std::cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << std::endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;
    car1.honk();
    car1.displayInfo();
    return 0;
}
```

## Polymorphism

Polymorphism allows methods to do different things based on the object it is acting upon. It can be achieved through function overloading and overriding.

#### Example: Polymorphism
```cpp
#include <iostream>
#include <string>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;

    return 0;
}
```

## Encapsulation

Encapsulation is the concept of wrapping data and methods into a single unit (class). It restricts direct access to some of the object's components.

#### Example: Encapsulation
```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(){
        age = 0;
    }
    void setName(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }

    void setAge(int a) {
        if (a > 0) {
            age = a;
        }
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person person;
    person.setName("John");
    person.setAge(25);

    std::cout << "Name: " << person.getName() << "\nAge: " << person.getAge() << std::endl;
    return 0;
}
```

## Abstraction

Abstraction means hiding complex implementation details and showing only the necessary features of an object.

#### Example: Abstraction
```cpp
#include <iostream>
#include <string>

class AbstractDevice {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class Printer : public AbstractDevice {
public:
    void start() override {
        std::cout << "Printer starting..." << std::endl;
    }

    void stop() override {
        std::cout << "Printer stopping..." << std::endl;
    }
};

int main() {
    Printer printer;
    printer.start();
    printer.stop();

    return 0;
}
```

## Exercises

### Exercise 1: Classes and Objects
Create a `Book` class with attributes `title`, `author`, and `year`. Add a method to display the book information. Create two `Book` objects and display their information.

#### Solution
```cpp
#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int year;

    void displayInfo() {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year << std::endl;
    }
};

int main() {
    Book book1;
    book1.title = "1984";
    book1.author = "George Orwell";
    book1.year = 1949;

    Book book2;
    book2.title = "To Kill a Mockingbird";
    book2.author = "Harper Lee";
    book2.year = 1960;

    book1.displayInfo();
    book2.displayInfo();

    return 0;
}
```

### Exercise 2: Inheritance
Create a base class `Shape` with a method `area()`. Create a derived class `Rectangle` that overrides the `area()` method. Create a `Rectangle` object and calculate its area.

#### Solution
```cpp
#include <iostream>

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "Area of rectangle: " << rect.area() << std::endl;
    return 0;
}
```

### Exercise 3: Polymorphism
Create a base class `Animal` with a method `makeSound()`. Create derived classes `Dog` and `Cat` that override `makeSound()`. Create objects of `Dog` and `Cat` and call `makeSound()`.

#### Solution
```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;

    return 0;
}
```

### Exercise 4: Encapsulation
Create a `BankAccount` class with private attributes `accountNumber` and `balance`. Add methods to deposit, withdraw, and check the balance. Ensure that the balance cannot be negative.

#### Solution
```cpp
#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(123456, 500.0);
    account.deposit(150.0);
    account.withdraw(200.0);
    std::cout << "Current balance: $" << account.getBalance() << std::endl;
    return 0;
}
```

### Exercise 5: Abstraction
Create an abstract class `Appliance` with pure virtual methods `turnOn()` and `turnOff()`. Create a derived class `WashingMachine` that implements the `turnOn()` and `turnOff()` methods. Create an object of `WashingMachine` and call these methods.

#### Solution
```cpp
#include <iostream>

class Appliance {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class WashingMachine : public Appliance {
public:
    void turnOn() override {
        std::cout << "Washing Machine is now ON." << std::endl;
    }

    void turnOff() override {
        std::cout << "Washing Machine is now OFF." << std::endl;
    }
};

int main() {
    WashingMachine wm;
    wm.turnOn();
    wm.turnOff();
    return 0;
}
```

By completing these examples and exercises, you will gain a solid understanding of the core principles of object-oriented programming in C++. This will enable you to create robust and reusable code for a variety of applications.


