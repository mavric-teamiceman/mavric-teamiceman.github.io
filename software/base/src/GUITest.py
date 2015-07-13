import matplotlib.pyplot as pyplot
import random as r
import time
#import cv2

#import plotdata
pyplot.ion()

# Testing string tokenization
#str1 = "255 255 255 255 255 255 255 255 120 98 12 41 87 14 12 42 43 27 18 47 13 93 73 120 91 83 92 124 83 19 83 12 201 214"
str1 = "255,255,255,255,255,255,255,255,120,98,12,41,87,14,12,42,43,27,18,47,13,93,73,120,91,83,92,124,83,19,83,12,201,214"
#str1 = [0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xe3,0x31,0x51,0x32,0x23,0x61,0x51,0x19,0x91,0x13,0x29,0x92,0x01,0x90,0x24,0x41,0x54,0x92,0x19,0x18,0x91,0x83,0x83,0x72,0x81,0x41]
tokens = str1.split(',')
h = [0 for i in xrange(34)]
for i in range(0, 34):
 	h[i] = int(tokens[i])

# Set up x
x = [i for i in xrange(34)]
# Set up y
y = [0 for i in xrange(34)]
# print x
# print y
# print tokens
print h

# Axes, [xmin, xmax, ymin, ymax]
axes = [0, 34, 0, 255]
#pyplot.title("Example Title",loc='center',fontsize='36')
pyplot.figure(figsize=(20,10))
#pyplot.axis(v)
#pyplot.bar(x,y)
#pyplot.show()

# try:
#  	while True:      
#  		y = [r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255), r.randint(0,255), r.randint(0,255),
#  			 r.randint(0,255)]

# 		pyplot.bar(x,y)
# 		pyplot.axis(axes)
# 		pyplot.title("Example Title",loc='center',fontsize='36')
# 		pyplot.draw()
# 		pyplot.clf()
# 		#time.sleep(1)
# except KeyboardInterrupt:
# 	pyplot.ioff()
# 	pyplot.close()
# 	print "*** Ctrl-C keyboard interrupt ***"