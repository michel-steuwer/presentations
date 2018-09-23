
# imperative programming
x = 41
x = x + 1
print(x)

# structured programming
array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
sum = 0
for x in array:
    sum += x
print(sum)

# object oriented programming
class Cat:
    def makeNoice(self):
        print("meow")

class Dog:
    def makeNoice(self):
        print("wuff wuff")

animal = Dog()
animal.makeNoice()

# functional programming
def fib(x, x_1 = 1, x_2 = 0):
    if x == 0:
        return x_2
    else:
        return fib(x-1, x_1 + x_2, x_1)
print(fib(6))