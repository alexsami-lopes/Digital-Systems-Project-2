# Digital Systems Project 2

Code tested in 10/04/2023 with the objective to turn on a led, to initialize and to print something in the 16x2 display using the WiringOP library and C programming language on the Orange Pi PC Plus with the other components used in the Digital Systems Project 1.


 #### Access by SSH
      1. Open a terminal on a PC using the same WI-FI that the Orange Pi is connected
      2. Type: ssh user@ip_of_orange_pi_ssh
      3. Type password of the user on the Orange Pi
 ##### Example
      ssh user@10.0.0.100

 
 ### WiringOP
   #### How to install
   ##### On the terminal logged to the Orange Pi by ssh type:
      1. apt-get update
      2. apt-get install -y git
      3. git clone https://github.com/orangepi-xunlong/wiringOP.git
 ## How to download, compile and use Project 2
   #### On the terminal logged to the Orange Pi by ssh type:
    1. git clone https://github.com/alexsami-lopes/Digital-Systems-Project-2.git
    2. cd Digital-Systems-Project-2
    3. make initialize_LCD
