# minitalk


# UNIX SIGNALS

<br>The objective of the project is to write a program in the form of a client and server, so client can communicate the string passed as a parameter to the server. Server must display received message and if so send back confrmation that the process occurred correctly. The communication between programs is achieved via UNIX signals and bitshifting operations. For instance:

<br>A & 128 >> i (0)

<br>The decimal value of A is 65, that in binary is 01000001. 128 is 10000000. The output of "&" operation is true when both numbers are 1, then SIGUSR1 is sent, otherwise it is false and SIGUSR2 is sent and "i" is incremented inside a while loop. 128 >> i (1) = 01000000 - we compare 2nd bit and so on. Once reaching the last bit "i" is set back to 0.

On the other side the character is built as follows: b = b | 128 >> i. "b" is a static char, that means its equal to 00000000. Anytime SIGUSR1 is received "b" 0 on "i"th position is updated by 1. When 8 signals are sent b character is printed, b and i are set back to 0.

<br>#To run the program:
<br>.git clone the repository to your computer, go to the terminal and type "make".
<br>.after that execute server (./server)
<br>.open new window and run ./client [SERVER PID] and your message

## _XPM_IMAGE_TRANSFER_ BRANCH

<br>Is an updated version of the same program. It sends _charmander.xpm_ via signals and create exact copy named _charmander_copy.xpm_
