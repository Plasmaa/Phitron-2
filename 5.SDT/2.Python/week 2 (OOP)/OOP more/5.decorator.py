def timer():
    def inner(func):
        def wrapper(*args, **kargs):
            print('starting the timer')
            result = func(*args, **kargs)
            print('timer ended')
            return result
        return wrapper
    return inner

@timer()
def get_factorial(n):
    import math
    print('factorial starting')
    result = math.factorial(n)
    print(f'factorial of {n} is: {result}')

get_factorial(5)

timer(get_factorial)()


