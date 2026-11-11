
import math

class Shape:
    def area(self):
        pass


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius


class Rectangle(Shape):
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self):
        return self.length * self.breadth


class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base
        self.height = height

    def area(self):
        return 0.5 * self.base * self.height


while True:
    print("\n--- Shape Area Calculator ---")
    print("1. Circle")
    print("2. Rectangle")
    print("3. Triangle")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        radius = float(input("Enter radius: "))
        if radius <= 0:
            print("Enter a positive radius!")
            continue
        shape = Circle(radius)

    elif choice == "2":
        length = float(input("Enter length: "))
        breadth = float(input("Enter breadth: "))
        if length <= 0 or breadth <= 0:
            print("Dimensions must be positive!")
            continue
        shape = Rectangle(length, breadth)

    elif choice == "3":
        base = float(input("Enter base: "))
        height = float(input("Enter height: "))
        if base <= 0 or height <= 0:
            print("Dimensions must be positive!")
            continue
        shape = Triangle(base, height)

    elif choice == "4":
        print("Program ended.")
        break

    else:
        print("Invalid choice!")
        continue

    print("Area:", round(shape.area(), 2))
