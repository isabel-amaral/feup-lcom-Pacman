## Project - Pacman

### Project Description

The purpose of this project was to develop a simple **MINIX 3 application** using at least 3 different I/O devcies from the ones covered in the course.

We decided to implement our version of the classic **Pacman** and used the following devices:

- **Timer** - for controlling the game's remaining time to play, pausing/unpausing and bonus time
- **Keyboard** - for the player to control the Pacman's movement by using the keyboard's arrow keys
- **Video Card in Graphics Mode** - for the interactive display of the game's elements
- **Mouse** (extra) - for the player to select the desired option in the menu

### Game Preview

The following screenshots ilustrate the general look of our game.

#### The Game

<p align="center">
  <img src="https://github.com/isabel-amaral/feup-lcom-Pacman/blob/main/proj/docs/images/game.png" />
</p>

#### Paused Game

<p align="center">
  <img src="https://github.com/isabel-amaral/feup-lcom-Pacman/blob/main/proj/docs/images/pause.png" />
</p>

#### Game Over

<p align="center">
  <img src="https://github.com/isabel-amaral/feup-lcom-Pacman/blob/main/proj/docs/images/game_over.png" />
</p>

#### Main Menu

<p align="center">
  <img src="https://github.com/isabel-amaral/feup-lcom-Pacman/blob/main/proj/docs/images/menu.png" />
</p>

#### Rules

<p align="center">
  <img src="https://github.com/isabel-amaral/feup-lcom-Pacman/blob/main/proj/docs/images/rules.png" />
</p>

### Implemented Features

- **Player control** - Pacman is moved with keyboard inputs that are recieved through the respective events
- **Elements creation** - each visual game element was represented using a struct and their positions are statically initialized
- **Elements display** - each visual game element is displayed using the video card's functions and the xpm files created for each
- **Collisions detection** - collisions between the Pacman and the remaining elements (coins, ghosts, maze walls) are verified and the adequate action is taken in each case
- **Ghosts movement** - the ghosts move alone at a constant rate and in the direction that guarantees they become closer to Pacman but avoiding the maze's walls
- **Timer** - each game has a duration of 2 minutes and the remaining minutes and seconds is displayed in the screen during the entire game
- **Pause/unpause** - the space bar may be used to pause or unpause the game, while the game is paused the timer isn't counting down
- **Bonus time** - each game has 5 special coins (red coins) which give the player extra 30 seconds to play when they are catched
- **Score** - the player's score is updated whenever a coin is catched and displayed after the game ends
- **Menu** - there's a functional and interactive menu which allows the player to either play the game, read the rules or exit the application altogether

### Code Structure

The code structure follows the **MVC pattern** and, therefore, contains the following modules:

- **Model** - contains all the code related to the creation of the **game elements** and their respective initialization
- **View** - contains all the code related to the **game's GUI**
- **Controller** - responsible for storing the information about the **game state** and controls which I/O device should be used and in which state

The following additional modules were also used:

- **Devices** - contains all the code developed in the labs related to the devices programming
- **Utils** - some functions used to make the interaction with the I/O devices easier

### Program Development State

There were a few features being considered at the beginning of the project that ended up not being implemented. The initial plan also included using the RTC in order to get some extra points regarding the I/O devices used. 

There's an unfixed bug in the ghosts' movement, which is very inconsistent overall. Sometimes they don't seem to be moving in the direction that will bring them closer to Pacman at all and, while some collisions with the maze's walls are avoided, others are not. This causes some of the walls to be erased after being passed through by the ghosts.

Even so, a complete and functional game was delivered and the project was considered successful.

For a more detailed project report (pt), checkout out the pdf [here](./docs/report.pdf).