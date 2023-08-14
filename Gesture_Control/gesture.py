import serial 
import time
import pyautogui

Arduino_Serial = serial.Serial('com6',9600) #Creating Serial port object called arduinoSerialData
time.sleep(2) #waiting for the communication to get established

while 1:
    incoming = str (Arduino_Serial.readline()) #readiing the serial data and print it as line

    if 'stop' not in incoming:
        print (incoming)
    
    if 'Play/Pause' in incoming:    
        pyautogui.typewrite(['space'], 0.2)
        
    if 'previous' in incoming:                
        pyautogui.hotkey('ctrl','fn', 'pgdn')

    if 'Rewind' in incoming:
        pyautogui.hotkey('left')  

    if 'Forward' in incoming:
        pyautogui.hotkey('right') 

    if 'Vup' in incoming:
        pyautogui.hotkey('down')
        
    if 'Vdown' in incoming:
        pyautogui.hotkey('up')

    if 'switch' in incoming:
         pyautogui.keyDown('alt')
         pyautogui.press('tab')
         
    if 'stop' in incoming:
        pyautogui.keyUp('alt')
    
    incoming = "";             
    
