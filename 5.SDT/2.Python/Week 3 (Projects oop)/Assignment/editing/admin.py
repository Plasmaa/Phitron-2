# ## File: admin.py
# from customer import Customer

class Admin:
    def __init__(self, name):
        self.name = name

    def admin_menu(self, restaurant):
        while True:
            print("\n--- Admin Menu ---")
            print("1. Create Customer Account")
            print("2. Remove Customer Account")
            print("3. View All Customers")
            print("4. Manage Restaurant Menu")
            print("5. Exit")
            choice = input("Select an option: ")

            if choice == '1':
                name = input("Enter name: ")
                email = input("Enter email: ")
                address = input("Enter address: ")
                customer = Customer(name, email, address)
                restaurant.add_customer(customer)
                print(f"Customer {name} added.")

            elif choice == '2':
                email = input("Enter customer email to remove: ")
                restaurant.remove_customer(email)
                print("Customer removed (if email existed).")

            elif choice == '3':
                restaurant.view_customers()

            elif choice == '4':
                self.manage_menu(restaurant)

            elif choice == '5':
                print("Exiting Admin Menu.")
                break
            else:
                print("Invalid choice. Try again.")

    def manage_menu(self, restaurant):
        while True:
            print("\n--- Manage Menu ---")
            print("1. Add Item")
            print("2. Remove Item")
            print("3. Update Item Price")
            print("4. Show Menu")
            print("5. Exit")
            choice = input("Select an option: ")

            if choice == '1':
                item = input("Enter item name: ")
                price = float(input("Enter item price: "))
                restaurant.add_menu_item(item, price)
                print(f"{item} added to menu.")

            elif choice == '2':
                item = input("Enter item name to remove: ")
                restaurant.remove_menu_item(item)
                print(f"{item} removed from menu (if it existed).")

            elif choice == '3':
                item = input("Enter item name to update: ")
                price = float(input("Enter new price: "))
                restaurant.update_menu_item(item, price)
                print(f"{item} price updated to ${price}.")

            elif choice == '4':
                restaurant.show_menu()

            elif choice == '5':
                print("Exiting Menu Management.")
                break
            else:
                print("Invalid choice. Try again.")
                
                
                
class Customer:
    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
        self.balance = 0
        self.order_history = []

    def add_balance(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"${amount} added to balance. Current Balance: ${self.balance}")
        else:
            print("Invalid amount.")

    def view_balance(self):
        print(f"Current Balance: ${self.balance}")

    def place_order(self, restaurant):
        print("\n--- Place an Order ---")
        restaurant.show_menu()
        order_item = input("Enter the item you want to order: ")
        if order_item in restaurant.menu:
            price = restaurant.menu[order_item]
            if self.balance >= price:
                self.balance -= price
                self.order_history.append((order_item, price))
                print(f"Order placed: {order_item} for ${price}. Remaining Balance: ${self.balance}")
            else:
                print("Insufficient balance. Please add funds.")
        else:
            print("Invalid item selection.")

    def view_past_orders(self):
        print("\n--- Past Orders ---")
        if self.order_history:
            idx = 1
            for item, price in self.order_history:
                print(f"{idx}. {item} - ${price}")
                idx += 1
        else:
            print("No past orders.")
            
            
            
class Restaurant:
    def __init__(self, name):
        self.name = name
        self.menu = {}
        self.customers = {}

    # Menu Management
    def add_menu_item(self, item_name, price):
        self.menu[item_name] = price

    def remove_menu_item(self, item_name):
        if item_name in self.menu:
            del self.menu[item_name]

    def update_menu_item(self, item_name, price):
        if item_name in self.menu:
            self.menu[item_name] = price

    def show_menu(self):
        print("\n--- Restaurant Menu ---")
        for item, price in self.menu.items():
            print(f"{item}: ${price}")

    def add_customer(self, customer):
        self.customers[customer.email] = customer

    def remove_customer(self, email):
        if email in self.customers:
            del self.customers[email]

    def view_customers(self):
        print("\n--- Registered Customers ---")
        for customer in self.customers.values():
            print(f"Name: {customer.name}, Email: {customer.email}, Address: {customer.address}")
            
            
            
restaurant = Restaurant("Kodom Ali's Restaurant")
admin = Admin("Admin")

while True:
    print("\n--- Restaurant Management System ---")
    print("1. Admin Login")
    print("2. Customer Login")
    print("3. Exit")
    choice = input("Select an option: ")

    if choice == '1':
        admin_name = input("Enter Admin Name: ")
        if admin_name == admin.name:
            print(f"\nWelcome Admin {admin_name}")
            admin.admin_menu(restaurant)
        else:
            print("Invalid Admin Name.")

    elif choice == '2':
        email = input("Enter Customer Email: ")
        if email in restaurant.customers:
            customer = restaurant.customers[email]
            while True:
                print(f"\n--- {customer.name}'s Menu ---")
                print("1. View Restaurant Menu")
                print("2. View Balance")
                print("3. Add Balance")
                print("4. Place Order")
                print("5. View Past Orders")
                print("6. Exit")
                c_choice = input("Select an option: ")

                if c_choice == '1':
                    restaurant.show_menu()
                elif c_choice == '2':
                    customer.view_balance()
                elif c_choice == '3':
                    amount = float(input("Enter amount to add: "))
                    customer.add_balance(amount)
                elif c_choice == '4':
                    customer.place_order(restaurant)
                elif c_choice == '5':
                    customer.view_past_orders()
                elif c_choice == '6':
                    print("Exiting Customer Menu.")
                    break
                else:
                    print("Invalid choice. Try again.")
        else:
            print("Customer not found. Please contact Admin to create an account.")

    elif choice == '3':
        print("Exiting the system. Goodbye!")
        break
    else:
        print("Invalid choice. Try again.")