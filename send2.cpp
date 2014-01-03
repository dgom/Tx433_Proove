/*
 Example of using the Tx433_Proove lib.
 Usage: ./send <command>
          or 
		./send <transmitterCode> <channelCode> <command> (de-comment/comment appropriate lines)
 Command is 0 for OFF and 1 for ON
 */

#include "tx433_proove.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the Raspberry Pi GPIO connector
     */
    int PIN = 3;
	
	// The transmitter unique address (you will need to chage this)
	char *transmitterCode = "1010100101101001010101100101011001010101010101010110";
    // The transmitter channel (might need to change this)
	char *channelCode="0101";
	int command  = atoi(argv[1]);
	
    //char* transmitterCode = argv[1];
    //int channelCode = atoi(argv[2]);
    //int command  = atoi(argv[3]);
    
    if (wiringPiSetup () == -1) return 1;
	printf("sending transmitterCode[%s] channelCode[%s] command[%i]\n", transmitterCode, channelCode, command);
	
	// Create an instance of the Proove class
	Tx433_Proove Proove(PIN, transmitterCode, channelCode);
    
    switch(command) {
        case 1:
            Proove.Device_On(1); // Unit no. 1
            break;
        case 0:
            Proove.Device_Off(1); // Unit no. 1
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
	return 0;
}


