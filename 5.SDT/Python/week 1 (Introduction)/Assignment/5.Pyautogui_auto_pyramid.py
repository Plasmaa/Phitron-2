import pyautogui
from time import sleep

rows = int(input())

print()
sleep(5)

for i in range(1, rows + 1):
    pyautogui.write('#' * i)
    pyautogui.press('enter')


