/*
brainComm.cpp

A demonstration "brain" for the MAVRIC robot. Manages the data streams between 
a microcontroller and a radio transmitter that operate over serial ports.

This demonstration uses Raspberry Pi serial ports connected to 
a Tiva Microcontroller and an XBee radio.

By Team ICEMAN:
Chad Condon, Keenan Fejeran, Ben Foster, Caleb Horst

Senior Project class of 2015

*/

//imports
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <wiringSerial.h>

//defines
#define NOT_OPEN -1
#define BAUD_RATE 9600

#define TIVA_DATA_SIZE 35
#define XBEE_BUFFER_SIZE 10

//defines for tiva commands
#define PAUSE 0
#define MOTOR_L 1
#define MOTOR_R 2
#define AUTONOMY_MODE 6

//defines some common speed values for the Tiva
#define MOTOR_SLOW 25
#define MOTOR_MEDIUM 50
#define MOTOR_FAST 100

//Added to a motor speed to make it reverse.
//0-127 is forward, 128-255 is reverse.
#define REVERSE_MOTOR_OFFSET 128

//Globals

//Serial ports
char XbeePort[] = "/dev/ttyAMA0"; 
char TivaPort[] = "/dev/ttyACM0";

int xbee_port;
int tiva_port;

unsigned char tiva_buffer[TIVA_DATA_SIZE];
unsigned char xbee_buffer[XBEE_BUFFER_SIZE];

//Thread bookkeeping
pthread_mutex_t tiva_mutex;
pthread_mutex_t xbee_mutex;


//Internal state flags
bool pauseFlag = false;

/*
int openPort(char buff[])

Open a port serial and return a file descriptor. Also sets the baud rate and other options.
*/
int openPort(char buff[]) {
	// Open port
	int returnMe = open(buff, O_RDWR | O_NOCTTY | O_NDELAY );

	// Check if port actually opened
	if (returnMe == -1)
	{
		//ERROR - CAN'T OPEN SERIAL PORT
		printf("Error - Unable to open UART.  Ensure it is not in use by another application\n");
	}

	//CONFIGURE THE UART
	//The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
	//	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
	//	CSIZE:- CS5, CS6, CS7, CS8
	//	CLOCAL - Ignore modem status lines
	//	CREAD - Enable receiver
	//	IGNPAR = Ignore characters with parity errors
	//	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
	//	PARENB - Parity enable
	//	PARODD - Odd parity (else even)
	struct termios options;
	tcgetattr(returnMe, &options);
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;		//Set baud rate
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(returnMe, TCIFLUSH);
	tcsetattr(returnMe, TCSANOW, &options);

	return returnMe;
}

/* 
void printBytes(unsigned char buffer[], int length)

print each byte of an array as a decimal followed by a space.
 */
void printBytes(unsigned char buffer[], int length) {
	for(  int i = 0; i<length; i++) {
		printf("%d ", buffer[i]);
	}

	printf("\nLength of array: %d\n", length);
}

/*
void *transmit(void *arguments)

A thread that transmits data over each serial port. The current data buffer from the Tiva is sent to the XBee,
and the latest XBee command (if it exists) is sent to the Tiva.
*/
void *transmit(void *arguments) {
	
	if (xbee_port == NOT_OPEN) {
		pthread_exit(NULL);
	}

	while(true) {
		
		sleep(1);

		if (tiva_port != NOT_OPEN) {
			//tiva->rpi->xbee transmit
			
			//start critical section
			pthread_mutex_lock(&tiva_mutex);
			
			//printf("Attempting to write to xbee\n");
			write(xbee_port, tiva_buffer, TIVA_DATA_SIZE);

			//write(xbee_port, xbee_post, 67);
			pthread_mutex_unlock(&tiva_mutex);
			//end critical section

		}
	
	}
}

/*
void *readXBee(void *arguments)

A thread that reads from the XBee port and decodes commands from the serial data.
*/
void *readXBee(void *arguments) {
	int bytesAvail;
	int bytesRead;
	char cmd[2];
	bool paused = false;
	
	//a binary flag to represent the operating mode of the robot:
	//false - means it is listening to the RPi hosted brain. 
	//true - means it is operating using only Tiva based instincts.
	bool autonomy_mode = false;
	
	while(xbee_port != NOT_OPEN) {
		bytesAvail = serialDataAvail(xbee_port);
		
		if(bytesAvail > 0) {
			pthread_mutex_lock(&xbee_mutex); 
			bytesRead = read(xbee_port, (void*)xbee_buffer, 1);
			pthread_mutex_unlock(&xbee_mutex);
			//printf("bytes from read: %i\n", bytesAvail);
			//printBytes(xbee_buffer, bytesAvail);
			cmd[0] = 0;
			cmd[1] = 0;
			
			//Process commands
			switch(xbee_buffer[0]) {
				//Pause
				case ' ' :
				case 'p' :
					//printf("Pause command recieved %i\n", xbee_buffer[0]);
					
					//printf("pause\n");
					cmd[0] = PAUSE;
					
					if (!paused) {
						cmd[1] = 1;
						paused = true;
					} else {
						cmd[1] = 0;
						paused = false;
					}
					
					//printf("attempting to write [%i,%i] to tiva\n", cmd[0], cmd[1]);
					
					write(tiva_port, (void*)cmd, 2);
					//write(xbee_port, (void*)cmd, 2);
					
					break;
				
				//Toggle autonomy mode: RPi (brain) control / Tiva (instinct) control
				case 't' :
					//printf("    mode toggle\n");
					cmd[0] = AUTONOMY_MODE;
					
					if (!autonomy_mode) {
						cmd[1] = 1;
						autonomy_mode = true;
					} else {
						cmd[1] = 2;
						autonomy_mode = false;
					}
					
					write(tiva_port, cmd, 2);
					break;
				
				//Forward
				case 'w' :
					//printf("Forward command recieved %i \n", xbee_buffer[0]);
					
					//printf("             forward\n");
					cmd[0] = MOTOR_L;
					cmd[1] = 50;
					write(tiva_port, cmd, 2);
					
					cmd[0] = MOTOR_R;
					write(tiva_port, cmd, 2);
					
					break;
					
				//Pivot left (counter clockwise)
				case 'a' :
					//printf("                       pivot left\n");
					cmd[0] = MOTOR_L;
					cmd[1] = REVERSE_MOTOR_OFFSET + MOTOR_SLOW;
					write(tiva_port, cmd, 2);
					
					cmd[0] = MOTOR_R;
					cmd[1] = MOTOR_SLOW;
					write(tiva_port, cmd, 2);
					
					break;
					
				//Reverse	
				case 's' :
					//printf("           reverse\n");
					cmd[0] = MOTOR_L;
					cmd[1] = REVERSE_MOTOR_OFFSET + MOTOR_SLOW;
					write(tiva_port, cmd, 2);
					
					cmd[0] = MOTOR_R;
					write(tiva_port, cmd, 2);
					break;
					
				//Pivot right (clockwise)
				case 'd' :
					//printf("     pivot right\n");
					cmd[0] = MOTOR_L;
					cmd[1] = MOTOR_SLOW;
					write(tiva_port, cmd, 2);
					
					cmd[0] = MOTOR_R;
					cmd[1] = REVERSE_MOTOR_OFFSET + MOTOR_SLOW;
					write(tiva_port, cmd, 2);

					break;	
					
				default :
					//printf("Unknown command recieved: %i\n", xbee_buffer[0]);
					break;
			} //end switch
			
		}
		
	} //end while
} //end readXBee

/*
void *readTiva(void *arguments)

A thread to read serial data from the Tiva serial port.
*/
void *readTiva(void *arguments) {
	
	int tiva_length; //stores how many characters were read in
	
	//threadArgs *args = (threadArgs*) arguments;
	//int tiva = args->tiva;

	//drain/initialize the semaphore

	while(tiva_port != NOT_OPEN) {
		/*semaphore take*/
		
		
		//sleep(1);
		
		//read tiva port
		tiva_length = serialDataAvail(tiva_port);

		
		if (tiva_length >= TIVA_DATA_SIZE) {
			pthread_mutex_lock(&tiva_mutex); 
			for (int i = 0; i<TIVA_DATA_SIZE; i++) {
				tiva_buffer[i] = serialGetchar(tiva_port);
			}
			pthread_mutex_unlock(&tiva_mutex);
			
			serialFlush(tiva_port);
			//printBytes(tiva_buffer, tiva_length);
		}
		
		//copy from the buffer into the brain slots
		
		//signal brain to run (semaphore give)
		//sem_post(&readToBrain);
		
	} //end while
	
	//Should never get here. If it does the port wasn't open when the thread began.
	printf("Error: Tiva Port not open\n");
} //end readTiva

/* A dummy brain thread, taking the place of the adaptrode code. */
void *brain(void *arguments) {
	while(true){
		/*semaphore take*/
		

		pthread_mutex_lock(&tiva_mutex);
		//brain stuff
		//printf("Brain thought about stuff.\n");
		
		// You can 

		pthread_mutex_unlock(&tiva_mutex);
		
		//optional sleep
		sleep(1);
		//signal transmit (semaphore give)
		//sem_post(&brainToTransmit);
		//sleep(3);
	}
}

/*
int main(void)

Demonstration main for the MAVRIC project, by team ICEMAN.

Opens serial ports, initializes threads and mutexes.
*/
int main(void) {

	printf("\n**********************************************\n");
	printf("********* MAVRIC ROBOT - TEAM ICEMAN *********\n");
	printf("**********************************************\n");
	
	//Open serial ports to tiva and xbee
	xbee_port = openPort(XbeePort);
	tiva_port = openPort(TivaPort);

	printf("\nOpened ports: %d %d\n", xbee_port, tiva_port);
	
	//Create threads
	pthread_t brainThread;
	pthread_t readTiva_thread;
	pthread_t readXBee_thread;
	pthread_t transmit_thread;
	
	//Initialize mutexes
	pthread_mutex_init(&tiva_mutex, 0);
	pthread_mutex_init(&xbee_mutex, 0);

	//TODO: Remove arguments from threads, as all their references are now global.
	pthread_create(&brainThread, NULL, &brain, NULL);
	pthread_create(&readTiva_thread, NULL, readTiva, NULL);
	pthread_create(&readXBee_thread, NULL, readXBee, NULL);
	pthread_create(&transmit_thread, NULL, transmit, NULL);

	//Now that threads are started, main can sleep forever.
	while(true) pause();
	
}
