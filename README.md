# IOT-Enhancing-Autistic-Communication


[Introduction:]

This project allows you to control your computer's keyboard using hand
gestures. It utilizes Arduino, ultrasonic sensors, and PyAutoGUI library
in Python to achieve gesture-based control. This README file provides an
overview of the project, the hardware setup instructions, and the
software setup instructions.



[Hardware Setup:]

To set up the hardware for gesture control, follow these steps:

1.  Materials Required:

    -   Arduino Uno

    -   Ultrasonic sensors (HC-SR04)

    -   Jumper wires

2.  Wiring Connections:

    -   Connect the VCC pins of the ultrasonic sensor to the 5V pin and
        3.3V pin on the Arduino.

    -   Connect the GND pins of the ultrasonic sensor to the GND pins on
        the Arduino.

    -   Connect the TRIG pins of the ultrasonic sensor to any digital
        pins (e.g., pin 11 and pin 6) on the Arduino.

    -   Connect the ECHO pins of the ultrasonic sensor to any digital
        pins (e.g., pin 10 and pin 5) on the Arduino.



[Software Setup:]

To set up the software for gesture control, follow these steps:

1.  Install Arduino IDE:

    -   Download and install the Arduino IDE from the official Arduino
        website (<https://www.arduino.cc/en/software>).

2.  Upload Arduino Sketch:

    -   Connect the Arduino board to computer using a USBcable.

    -   Open the Arduino IDE and create a new sketch.

    -   Copy and paste the Arduino code given in the zip file.(i.e Gesture_Control.ino).

    -   Verify and upload the sketch to the Arduino board.

3.  Install Python Dependencies:

    -   Make sure you have Python installed on your computer.

    -   Open a terminal or command prompt and install the required Python
        packages:

                 ->pip install pyautogui pyserial

4.  Python Script:

    -   Create a new Python script (e.g., gesture.py) and copy the code from
        zip file.

    -   Make sure to replace "COM6" with the correct serial port that
        your Arduino is connected to. You can find the port in the Arduino
        IDE (Tools -> Port).



[Usage:]

After setting up the hardware and software, you can use the gesture
control system as follows:

    1.  Ensure that the Arduino and ultrasonic sensors are properly
        connected and powered.

    2.  Run the Python script **gesture.py** using the Python interpreter.

    3.  Move your hand or an object within the range of the ultrasonic
        sensor(s) to trigger the gestures.

    4.  Based on the distance measured by the sensors, the script will
        execute the defined actions.

Note: You can customize the gestures and actions in the Python
script according to your requirements. Refer to the PyAutoGUI
documentation for more information on available functions.



[Troubleshooting:]

    -   If you are not getting accurate distance measurements, make sure the
        ultrasonic sensors are properly connected and facing the right
        direction.

    -   Check the serial port in the Python script and make sure it matches
        the one your Arduino is connected to.

    -   If you encounter any issues with the Arduino IDE or Python
        dependencies, refer to their respective documentation or seek help
        from relevant communities.



[Conclusion:]

Congratulations! You have successfully set up a gesture control system
using Arduino, ultrasonic sensors, and PyAutoGUI. Explore further
possibilities by customizing the gestures and actions to suit your
needs. Have fun experimenting and creating innovative projects with
gesture control!
