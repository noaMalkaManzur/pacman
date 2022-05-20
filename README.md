# pacman
This game is written in c++ obj.

About creaturers of the game:

Ghost:
Game has 3 possible levels
(a) BEST (b) GOOD and (c) NOVICE
BEST - Ghost try to chase the pacman
GOOD - Ghost try to chase the pacman, but occasionally they just change to a random direction and stay with it for a while and then moves before being smart again
NOVICE - Ghost just move on screen with a direction selected randomly 

Fruit-
Is a single char digit between 5 to 9 selected randomly, that appears at random points in time on screen and travels around randomly at a slow pace. 

Loading Screens from files-
The game would look for files in the working directory, with the names pacman_*.screen 
The screen file should be a text file representing the screen, with:
@ - for the position of the pacman (1 and only)
$ - for the initial position of the ghosts (allow any number between 0 to 4)
"#" - for walls
% - for “empty” positions that should not have a breadcrumb
& - for the position where the points and remaining lives information 
