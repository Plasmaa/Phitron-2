## File: customer.py
# class Customer:
#     def __init__(self, name, email, address):
#         self.name = name
#         self.email = email
#         self.address = address
#         self.balance = 0
#         self.order_history = []

#     def add_balance(self, amount):
#         if amount > 0:
#             self.balance += amount
#             print(f"${amount} added to balance. Current Balance: ${self.balance}")
#         else:
#             print("Invalid amount.")

#     def view_balance(self):
#         print(f"Current Balance: ${self.balance}")

#     def place_order(self, restaurant):
#         print("\n--- Place an Order ---")
#         restaurant.show_menu()
#         order_item = input("Enter the item you want to order: ")
#         if order_item in restaurant.menu:
#             price = restaurant.menu[order_item]
#             if self.balance >= price:
#                 self.balance -= price
#                 self.order_history.append((order_item, price))
#                 print(f"Order placed: {order_item} for ${price}. Remaining Balance: ${self.balance}")
#             else:
#                 print("Insufficient balance. Please add funds.")
#         else:
#             print("Invalid item selection.")

#     def view_past_orders(self):
#         print("\n--- Past Orders ---")
#         if self.order_history:
#             idx = 1
#             for item, price in self.order_history:
#                 print(f"{idx}. {item} - ${price}")
#                 idx += 1
#         else:
#             print("No past orders.")