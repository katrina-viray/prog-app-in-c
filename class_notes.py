'''
Methods:
In classes, methods are anything you create with the "def" keyword within the class.
You have to call these with an object.

Attributes:
These are variables which belong to a certain object.
These are created with the "self" keyword. 

Self keyword: 
This stands for the instance that you're calling. For example, "kat" is an instance of type dog.
'''

# here, we're creating a new class called dog which inherits from object. 
class Dog(object):
    # contructor method
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def speak(self):
        print("Hi I am", self.name, 'and I am', self.age)

    def change_age(self, age):
        self.age = age

        
kat = Dog('Kat', 20) # when this is called, the constructor is called automatically
kat.speak()
kat.change_age(21)
kat.speak()