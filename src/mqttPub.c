#include <stdio.h>
#include <stdlib.h>
#include <C:\Program Files (x86)\mosquitto\devel\mosquitto.h>

int main(){

	//declare required variables
	int connection;
	struct mosquitto * mq;

	//must call function before any other mosquitto functions
	mosquitto_lib_init();

	//Create a enw mosquitto client
	mq = mosquitto_new("test", true, NULL);

	//Connect to the mosquitto broker
	connection = mosquitto_connect(mq, "port", 1883, 60);

	//If unable to connect to broker print message
	if(connection != 0)
	{
		printf("Client could not connect to broker! Error Code: %d\n", connection);

		//close the connection to free memory
		mosquitto_destroy(mq);
		return -1;
	}

	//if able to connect to broker print message
	else
	{
		printf("We are now connected to the broker!\n");
	}

	//publish a message to the broker
	mosquitto_publish(mq, NULL, "test", 6, "Sup", 0, false);

	//disconnect from the broker and destroy that instance to free up memory
	mosquitto_disconnect(mq);
	mosquitto_destroy(mq);

	//free the resources used for the library
	mosquitto_lib_cleanup();

	return 0;
}
