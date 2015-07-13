# Base Station

This is the platform for remote monitoring and command of the robot.

## baseStation.py

baseStation.py, inside of the src folder, is the code written for the base station. This program will be used as a pseudo-controller for MAVRIC while in manual mode, providing the ability to control the movements of MAVRIC. While in auto mode, baseStation.py will only be used for the pause button as well as collecting the data from MAVRIC and displaying it on a bar graph (this data will also be displayed in manual mode). All data being transferred from MAVRIC to the base station will be done using an XBee. This being the case, the range of this communication strongly depends on the type of XBee being used. We are currently using a Series 1 XBee and therefore, do not recommend long-range communication. baseStation.py is using multiple imports to perform these tasks:
* os: portable way of using operating system dependent functionality
* sys: provides access to some variables used or maintained by the interpreter
* time: provides access to some variables used or maintained by the interpreter
* fcntl: performs file control and I/O control on file descriptors
* serial: encapsulates the access for the serial port
* matplotlib.pyplot: used to visually graph data

## GUITest.py

GUITest.py, inside of the src folder, is an example of producing a bar graph of our data points. The code for which has already been transferred to baseStation.py. GUITest uses matplotlib.pyplot in order to do the plotting of the bar graph. Documentation for pyplot can be found [here](http://matplotlib.org/api/pyplot_api.html).
