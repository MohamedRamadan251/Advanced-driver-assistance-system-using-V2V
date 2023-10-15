import serial
import cv2
from time import sleep
import socket
import json
import picamera
import numpy as np
import threading
import RPi.GPIO as GPIO

# Define the server address and port
SERVER_ADDRESS = '192.168.37.67'  
SERVER_PORT = 5560

ser = serial.Serial ("/dev/ttyS0", 9600)    #Open port with baud rate
count =0
color="undefined"
var=0
new_data=0
old_data=0
color_rec="red"
ser.reset_input_buffer()

motor_channel = (29,31,33,35)  
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(motor_channel, GPIO.OUT)



def receive_data(client_socket):
    global color_rec
    while True:
        try:
            data = client_socket.recv(1024).decode()
            data = json.loads(data)
            if not data:
                print('Server disconnected')
                break

            color_rec = data[0]
            speed = data[1]

            # Do something with the color and speed data
            print(f"Received color: {color_rec}, speed: {speed}")

        except ConnectionResetError:
            print('Server disconnected')
            break





def detect_color(camera):
    global color
    while True:
        frame = np.empty((camera.resolution[1], camera.resolution[0], 3), dtype=np.uint8)
        camera.capture(frame, format='bgr', use_video_port=True)
        hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        height, width, _ = frame.shape

        cx, cy = int(width / 2), int(height / 2)

        pixel_center = hsv_frame[cy, cx]
        hue_value, sat_value, val_value = pixel_center

        color = "Undefined"
        if hue_value < 5:
            color = "RED"
        elif sat_value <= 10 and val_value <= 255:
            color = "WHITE"
        elif val_value <= 50:
            color = "BLACK"
        elif hue_value < 22:
            color = "ORANGE"
        elif hue_value < 33:
            color = "YELLOW"
        elif hue_value < 78:
            color = "GREEN"
        elif hue_value < 131:
            color = "BLUE"
        elif hue_value < 170:
            color = "VIOLET"
        else:
            color = "RED"

        pixel_center_bgr = frame[cy, cx]
        b, g, r = [int(i) for i in pixel_center_bgr]

        #cv2.rectangle(frame, (cx - 220, 10), (cx + 200, 120), (255, 255, 255), -1)
        #cv2.putText(frame, color, (cx - 200, 100), 0, 3, (b, g, r), 5)

        cv2.circle(frame, (cx, cy), 5, (25, 25, 25), 3)

        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1)
        if key == 27:
            break


            
  


def ACW(helper):
 global count
 count=0
 while(count<helper):
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
            sleep(0.005)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.HIGH))
            sleep(0.005)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.HIGH,GPIO.LOW))
            sleep(0.005)
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
            sleep(0.005)
            count+=1


 
 
 def CW(helper):
  global count
  count=0
  while(count<helper):
                
                GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.LOW))
                sleep(0.005)
                GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
                sleep(0.005)
                GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.LOW))
                sleep(0.005)
                GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
                sleep(0.005)
                
                count=count+1
        


def main():
    with picamera.PiCamera() as camera:
        camera.resolution = (640, 480)
        camera.framerate = 24
        sleep(2) 
        color_thread = threading.Thread(target=detect_color, args=(camera,))
        color_thread.daemon = True
        color_thread.start()
        

        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        client_socket.connect((SERVER_ADDRESS, SERVER_PORT))

    
        receive_thread = threading.Thread(target=receive_data, args=(client_socket,))
        receive_thread.start()
 
        #received_data=1
        while True:
            
            received_data = ser.read
            received_data=int.from_bytes(received_data,byteorder="big")
           
            sleep(0.03)
            new_data=received_data
            if(new_data==1 or new_data==6 or new_data==7):
                new_data=256
            elif(new_data==4):
                new_data=320
            elif(new_data==5):
                new_data=192
            if(new_data>old_data):
                ACW(new_data-old_data)
            elif(new_data<old_data):
                CW(old_data-new_data)
            old_data=new_data
            if(received_data==0):
                 if(color_rec==color):
                      ser.write(bytes([speed]))
                      sleep(0.5)
                     
                 else:
                      ser.write(bytes([0]))
                      print("no")
            
             
            sleep(30)
            break
            

if __name__ == '__main__':
    main()


