class Calculator:
    brand = 'Casio MS990'
    
    def add(self, num1, num2):
        return num1 + num2
    
    def deduct(self, num1, num2):
        return num1 - num2
    
    def multiply(self, num1, num2):
        return num1 * num2
    
    def divide(self, num1, num2):
        if num2 != 0:
            return num1 / num2
        else:
            return "Error: Division by zero is not allowed"
