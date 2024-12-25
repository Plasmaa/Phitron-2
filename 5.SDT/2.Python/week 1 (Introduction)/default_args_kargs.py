# function of python is written by def

# def sum(num1, num2):
#     result = num1+num2
#     print(result)
#     return sum

# sum(1,2)

# def sum2(num1, num2, num3 = 0):
#     result = num1 + num2 + num3
#     print(result)
#     return sum

# sum2(5,2)

# args
def print_num(*numbers): # tuple
    print(numbers)
print_num(10,20,30,40)

def all_sum(num1, num2, *numbers):
    print(numbers)
    sum = 0
    for num in numbers:
        print(num)
        sum = sum + num
    return sum

total = all_sum(45, 46, 89, 11, 81, 5, 2, 77)
print('all sum: ', total)

def do_a_lot(*args):
    print(args)

do_a_lot('Doing a lot: ' , 1,2,3,4,5)