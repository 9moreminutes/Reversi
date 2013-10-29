Reversi
=======

Reversi Client/Server Game for CSCE 315 Group I

Compiling
---------

To compile the server use the command:

`make clean; make`

This uses gcc as the compiler so make sure you have it installed.

Next if you want to use the client, you need to compile the client. This requires that you have Qt4 installed. You can compile by moving to the `/client/` folder and running

`make`

If this fails, you can use the sample prebuilt binary which is located at `/client/client`.

Running
-------

To run the server run the command 

`./Reversi <port>`

In a new terminal window, use telnet to connect to your local ip address using the port you chose. Example:

`telnet 192.168.1.1 <port>`

You can then use commands (like `HUMAN-AI` to start the game) and get responses.

Running using the client
------------------------

The client connects to the server using port 7349 so first you must run

`./Reversi 7349`

next you need to start the client which is located in `/client/` by running

`cd client; ./testing`

the client will then automatically connect to the server and the game will be started. You can click the buttons to make moves (you're black) and click the difficulty menu to change difficulties.


Development Log
---------------

To see a development log, look at the commit messages for this repository on github.com/cloudburst-/Reversi.