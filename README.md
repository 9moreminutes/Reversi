Reversi
=======

Reversi Client/Server Game for CSCE 315 Group I

Compiling
---------

To compile use the command:

`make clean; make`

This uses gcc as the compiler so make sure you have it installed.

Running
-------

To run the server run the command 

`./Reversi <port>`

after compilation. In a new window, use telnet to connect to your local ip address using the port you chose. Example:

`telnet 192.168.1.1 <port>`

You can then use commands (like `HUMAN-AI` to start the game) and get responses.
