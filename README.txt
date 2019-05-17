This program contains a server that solves various of search problems in a grid graph in parallel.

The server asks the user for a matrix (when each cell contains a number representing the weight of the current vertex), a start point and a goal point.
And then, he finds the shortest path from the start to the goal.

In order to provide the best answer to the user, A-Star algorithm was chosen to be implemented in the server's side, following a series of empirical experiments on several search algorithms such as BFS, DFS, Best-First-Search and A-Star.
In order to run the program, a port number for the server should be provided as a command line argument.
The server will run until "stop" is sent.