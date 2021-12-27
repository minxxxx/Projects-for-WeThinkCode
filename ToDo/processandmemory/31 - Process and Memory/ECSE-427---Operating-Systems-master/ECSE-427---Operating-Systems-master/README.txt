To run the program: 

1- In the terminal, go to the directory where the files are located.
2- Open two tabs and compile the programs: 

	- In one of the tabs type: gcc -o client_producer client_producer.c -lpthread -lrt
	- In the other tab type: gcc -std=gnu99 -o server_consumer server_consumer.c -lpthread -lrt

3- Run the programs: 

	- In one of the tabs first type: ./server_consumer
	- Then, in the second tab type : ./client_producer 2 4
	(where two represents the client_id and 4 represents the number of pages to print) you can change those numbers. 
	Then you can rerun ./client_producer as many times as you wish using the pages and the client id of you choice. 
	The server will run continuously. Until you CTRL-C

4- Look at both tabs to see the outputs for the client and the server



(Genevieve Nantel - 260481768)