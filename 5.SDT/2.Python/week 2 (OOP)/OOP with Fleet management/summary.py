class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

class Physics(Book):
    def __init__(self, title, author, price, lab):
        super().__init__(title, author, price)
        self.lab = lab

    def read(self):
        print(f"Reading {self.title} by {self.author}")

topon  = Physics('True', 'Topon', 5000, 'lab')
print(issubclass(Physics, Book))

topon.read()
