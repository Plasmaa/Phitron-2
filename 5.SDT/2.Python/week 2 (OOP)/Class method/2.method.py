# def call():
#     print('calling bitches')
#     return 'call done'


class Phone:
    price = 1200000
    color = 'blue'
    brand = 'smasung'
    features = ['camera', 'speaker', 'gaming', 'hammer']

    def call(self):
        print('calling one person')

    def send_sms(self,phone, sms):
        text = f'sending sms to : {Phone} and message: {sms}'
        return text

my_phone = Phone() 
print(my_phone.features)
my_phone.call()
result = my_phone.send_sms(41234, 'i called you but you never picked')
print(result)


