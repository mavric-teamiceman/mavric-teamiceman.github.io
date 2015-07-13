#!/usr/bin/env python
 
"""
    baseStation.py

    This code was written by Ben Foster on team Iceman for the 2015
    senior project at the University of Washington Tacoma. This
    program is meant to read in data from the MAVRIC robot and
    display that data on a multicolored bar graph. This program also
    takes commands from the user and sends them to the MAVRIC.

    Team members: Chad Condon, Keenan Fejeran, Ben Foster, Caleb Horst

"""
 
# imported modules
import os                   # portable way of using operating system dependent functionality
import sys                  # provides access to some variables used or maintained by the interpreter
import time                 # provides various time-related functions
import fcntl                # performs file control and I/O control on file descriptors
import serial               # encapsulates the access for the serial port
import matplotlib.pyplot as pyplot # used to visually graph data
import select               # Used for reading in non-blocking characters from stdin
import termios              # Used for reading in non-blocking characters from stdin
import tty                  # Used for reading in non-blocking characters from stdin
import csv                  # Used for writing data to a csv file

# If you need to change the output file name:
FILE_NAME = "test.csv"

DATA_LENGTH = 35
MAX_DATA = 255
FRAME_WIDTH = 70
FRAME_HEIGHT = 12.5

# Define isData so that we can use it for constantly reading in characters from standard in.
def isData():
    return select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])
old_settings = termios.tcgetattr(sys.stdin)

# Open the serial port
serial = serial.Serial()
serial.port = '/dev/tty.usbserial-A702YQ5S'
serial.baudrate = 9600
serial.timeout = 1
serial.writeTimeout = 1
serial.open()
 
# make stdin a non-blocking file
fcntl.fcntl(sys.stdin, fcntl.F_SETFL, os.O_NONBLOCK)
 
# post startup message to other XBee's and at stdout
serial.writelines("Base Station is up and running.\r\n")
print "Base Station is up and running."
print "Entering loop to read and print messages (Ctrl-C to abort)..."

# Make the plot rewritable
pyplot.ion()

# Initialize x and y axes on plot
x = [i for i in xrange(DATA_LENGTH)]
y = [0 for i in xrange(DATA_LENGTH)]

# Initialize final data with zeroes
data = [0 for i in xrange(DATA_LENGTH)]

# Axis ticks: [xmin, xmax, ymin, ymax]
axes = [0, DATA_LENGTH, 0, MAX_DATA]

# Figure size subject to change
pyplot.figure(figsize=(FRAME_WIDTH, FRAME_HEIGHT))

# Open the csv file to be written to
csvFile = open(FILE_NAME, 'wb')
 
try:
    # Use this for reading in characters from stdin
    tty.setcbreak(sys.stdin.fileno())
    while True:
        # Only read in 34 bytes
        line = serial.read(DATA_LENGTH)

        j = 0
        # Set the characters to ints and store in data
        for c in line:
            data[j] = ord(c)
            j = j + 1

        # If a line was read in
        if line:
            print data

            # Write data out to the csv file
            writer = csv.writer(csvFile, delimiter=',')
            writer.writerow(data)

            # Plot the data
            #pyplot.bar(x,data)
            # Sonars, color will be red, r, there are 8 of them
            x1 = [x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7]]
            data1 = [data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]]
            pyplot.bar(x1, data1, color='r')

            # Temperature, color will be blue, b, there are 2 of them
            x2 = [x[8], x[9]]
            data2 = [data[8], data[9]]
            pyplot.bar(x2, data2, color='y')

            # Light, color will be green, g, there are 3 of them
            x3 = [x[10], x[11], x[12]]
            data3 = [data[10], data[11], data[12]]
            pyplot.bar(x3, data3, color='m')

            # Accel, color will be Cyan, c, there are 3 of them
            x4 = [x[13], x[14], x[15]]
            data4 = [data[13], data[14], data[15]]
            pyplot.bar(x4, data4, color='c')

            # Audio L, color will be magenta, m, there are 7 of them
            x5 = [x[16], x[17], x[18], x[19], x[20], x[21], x[22]]
            data5 = [data[16], data[17], data[18], data[19], data[20], data[21], data[22]]
            pyplot.bar(x5, data5, color='b')

            # Audio R, color will be yellow, y, there are 7 of them
            x6 = [x[23], x[24], x[25], x[26], x[27], x[28], x[29]]
            data6 = [data[23], data[24], data[25], data[26], data[27], data[28], data[29]]
            pyplot.bar(x6, data6, color='g')

            # Bumpers, color will be black, k, there are 4 of them
            x7 = [x[30], x[31], x[32], x[33]]
            data7 = [data[30], data[31], data[32], data[33]]
            pyplot.bar(x7, data7, color='k')

            # Battery voltage, color will be white, w, there is one
            x8 = [x[34]]
            data8 = [data[34]]
            pyplot.bar(x8, data8, color='w', linewidth=5)

                            # data 0 , 1 , 2 , 3 , 4 , 5
            pyplot.xticks(x, ("Sonar 0", "Sonar 1", "Sonar 2", "Sonar 3", "Sonar 4", "Sonar 5",
                            # data 6 , 7 , 8 , 9 , 10 , 11
                            "Sonar 6", "Sonar 7", "Temp Left", "Temp Right", "Light Red", "Light Green", 
                            # data 12 , 13 , 14 , 15 , 16 , 17
                            "Light Blue", "Accel. x", "Accel. y", "Accel. z", "Audio L0", "Audio L1", 
                            # data 18 , 19 , 20 , 21 , 22 , 23
                            "Audio L2", "Audio L3", "Audio L4", "Audio L5", "Audio L6", "Audio R0", 
                            # data 24 , 25 , 26 , 27 , 28 , 29
                            "Audio R1", "Audio R2", "Audio R3", "Audio R4", "Audio R5", "Audio R6", 
                            # data 30 , 31 , 32 , 33 , 34
                            "Bump Right", "Bump R-Right", "Bump R-Left", "Bump Left", "Battery V"), rotation=45)
            pyplot.axis(axes)
            pyplot.suptitle("Sensor Data", fontsize = '36')
            pyplot.draw()
            pyplot.clf()

        # read data from the keyboard (i.e. stdin) and send via the XBee modem
        if isData():
            ch = sys.stdin.read(1)
            serial.write(ch)

# If Ctrl-C is pressed
except KeyboardInterrupt:
    print "*** Ctrl-C keyboard interrupt ***"
    pyplot.ioff()
    pyplot.close('all')
    csvFile.close()
    serial.writelines('p') # Make sure robot stops if base station goes down
    serial.writelines("Base Station is going down.\r\n")
