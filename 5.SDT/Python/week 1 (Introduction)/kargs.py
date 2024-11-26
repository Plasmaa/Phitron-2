def full_name(first,last):
    name = f'full name is {first} {last}'
    return name

name = full_name('alu' , 'kodu')
print(name)

# not maintaing serial 
def full_name2(first,last):
    name = f'full name is {first} {last}'
    return name

name = full_name2(last = 'alu' ,first = 'kodu')
print(name)

# return multiple things from an array
def a_lot(num1, num2):
    sum = num1 + num2
    mult = num1 * num2
    remain = num1 - num2
    # return [sum, mult, remain]
    return sum, mult, remain


everything = a_lot(55, 21)
print(everything)
