## File: restaurant.py
# class Restaurant:
#     def __init__(self, name):
#         self.name = name
#         self.menu = {}
#         self.customers = {}

#     # Menu Management
#     def add_menu_item(self, item_name, price):
#         self.menu[item_name] = price

#     def remove_menu_item(self, item_name):
#         if item_name in self.menu:
#             del self.menu[item_name]

#     def update_menu_item(self, item_name, price):
#         if item_name in self.menu:
#             self.menu[item_name] = price

#     def show_menu(self):
#         print("\n--- Restaurant Menu ---")
#         for item, price in self.menu.items():
#             print(f"{item}: ${price}")

#     def add_customer(self, customer):
#         self.customers[customer.email] = customer

#     def remove_customer(self, email):
#         if email in self.customers:
#             del self.customers[email]

#     def view_customers(self):
#         print("\n--- Registered Customers ---")
#         for customer in self.customers.values():
#             print(f"Name: {customer.name}, Email: {customer.email}, Address: {customer.address}")