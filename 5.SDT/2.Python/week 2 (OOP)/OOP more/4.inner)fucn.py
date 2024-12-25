# function is a first class object

def double_decker():
    print('starting the double decker')

    def inner_fun():
        print('inside the inner')
        return 3000
    return inner_fun

print(double_decker())
print(double_decker()())

def do_something(work):
    print('work started')
    # print(work)
    work()
    print('work finished')

do_something(double_decker)
do_something(double_decker())

def coding():
    print('coding started')

do_something(coding)

def sleeping():
    print('sleeping started')

do_something(sleeping)
