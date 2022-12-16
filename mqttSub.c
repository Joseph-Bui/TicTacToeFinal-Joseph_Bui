#include <stdio.h>
#include <stdlib.h>
#include <C:\Program Files (x86)\mosquitto\devel\mosquitto.h>

//main function
int main() 
{
	
	//create local variables
	int connect, id=12;

	//a must call function for mosquitto
	mosquitto_lib_init();

	struct mosquitto *mq;

	//create a new client
	mq = mosquitto_new("test", true, &id);

	//set the connect call back
	mosquitto_connect_callback_set(mq, on_connect);
	mosquitto_message_callback_set(mq, on_message);
	
	//connect to the mosquitto broker
	connect = mosquitto_connect(mq, "host", 1883, 10);

	//Check if connected
	if(connect) 
	{
		//if not connected print message
		printf("Unable to connect with error %d\n", connect);

		return -1;
	}

	//create a new thread to process network traffic
	mosquitto_loop_start(mq);
	printf("Please press enter to terminate\n");
	getchar();

	//stop the looping process
	mosquitto_loop_stop(mq, true);

	//disconnect and destroy the instance to free memory
	mosquitto_disconnect(mq);
	mosquitto_destroy(mq);

	//free up resources used for the library
	mosquitto_lib_cleanup();

	return 0;
}

void on_connect(struct mosquitto *mq, void *obj, int connection)
 {
	printf("Current ID is: %d\n", * (int *) obj);

	//check if the broker is connected
	if(connection)
	{
		//if broker is not connected then print statement
		printf("Error code: %d\n", connection);
		exit(-1);
	}

	//if broker is connected then subscribe
	else
	{
		mosquitto_subscribe(mq, NULL, "test", 0);
	}
	
}

//function that prints a message to the broker
void on_message(struct mosquitto *mq, void *obj, const struct mosquitto_message *message) 
{
	printf("New message with topic %s: %s\n", message->topic, (char *) message->payload);
}