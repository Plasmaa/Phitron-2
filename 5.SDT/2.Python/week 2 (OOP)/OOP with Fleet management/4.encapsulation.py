class Bank:
    def __init__(self,holder, initial_deposit, balance):
        self.holder = holder
        self.initial_deposit = initial_deposit
        self.__balance = balance

    def deposit(self, amount):
        self.__balance += amount

    def get_balance(self):  
        return self.__balance
    
    def withdraw(self, amount):
        if amount < self.__balance: # incapsulating the balance by using __ keyword
            self.__balance = self.__balance - amount
            return amount
        else:
            return f'Forkia taka nai'
        
    

rafsun = Bank('Choooto bro', 10000, 0)
print(rafsun.get_balance())
try:
    rafsun.balance = 5000
    print(rafsun.get_balance())
    rafsun.balance = 60000
    print(rafsun.get_balance())
except AttributeError:
    print("You can't do that")

rafsun.deposit(40000)
print(rafsun.get_balance())




