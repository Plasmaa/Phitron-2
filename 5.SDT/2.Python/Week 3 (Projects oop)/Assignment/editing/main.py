from restaurant import Restaurant
from admin import Admin
from customer import Customer

# restaurant = Restaurant("Kodom Ali's Restaurant")
# admin = Admin("Admin")

# while True:
#     print("\n--- Restaurant Management System ---")
#     print("1. Admin Login")
#     print("2. Customer Login")
#     print("3. Exit")
#     choice = input("Select an option: ")

#     if choice == '1':
#         admin_name = input("Enter Admin Name: ")
#         if admin_name == admin.name:
#             print(f"\nWelcome Admin {admin_name}")
#             admin.admin_menu(restaurant)
#         else:
#             print("Invalid Admin Name.")

#     elif choice == '2':
#         email = input("Enter Customer Email: ")
#         if email in restaurant.customers:
#             customer = restaurant.customers[email]
#             while True:
#                 print(f"\n--- {customer.name}'s Menu ---")
#                 print("1. View Restaurant Menu")
#                 print("2. View Balance")
#                 print("3. Add Balance")
#                 print("4. Place Order")
#                 print("5. View Past Orders")
#                 print("6. Exit")
#                 c_choice = input("Select an option: ")

#                 if c_choice == '1':
#                     restaurant.show_menu()
#                 elif c_choice == '2':
#                     customer.view_balance()
#                 elif c_choice == '3':
#                     amount = float(input("Enter amount to add: "))
#                     customer.add_balance(amount)
#                 elif c_choice == '4':
#                     customer.place_order(restaurant)
#                 elif c_choice == '5':
#                     customer.view_past_orders()
#                 elif c_choice == '6':
#                     print("Exiting Customer Menu.")
#                     break
#                 else:
#                     print("Invalid choice. Try again.")
#         else:
#             print("Customer not found. Please contact Admin to create an account.")

#     elif choice == '3':
#         print("Exiting the system. Goodbye!")
#         break
#     else:
#         print("Invalid choice. Try again.")
