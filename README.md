# so_long

This project is about writing a 2D Game in C.
![printscreen](printscreen.png)

### About my Journey
This was the first project in the 42 Curriculum that made me have tons of fun with it. In terms of days, this was a short journey, but just because I was dedicating 16+ hours per day in this little project, and I just did that because I was having a lot of fun in discovering the implications and details about graphics programming. I wasn't able to do most of the features I was aiming to because I needed to keep on progressing in my Common Core, but I promise that I will come back someday and make this game something really playable and fun, at least for me! If you are a 42 Cadet, treat this project with love, it will reward you with knowledge and fun.

### How to play it
Just run the following command (you have to be on Linux)
```bash
git clone https://github.com/PedroDrago/so_long.git && cd so_long && git clone https://github.com/42Paris/minilibx-linux.git minilibx && cd minilibx && ./configure && cd .. && make && ./so_long
```

### Leaktester
In 42 projects it is not acceptable to have any kind of memory leak, and in this project you can have leaks that could be found to discover, so I made a simple script that uses valgrind to check if your so_long has any sort of leaks:
- [so_long_leaktester](https://github.com/PedroDrago/so_long_leaktester)

### Art Sources
I'm a programmer, not an artist, so all the pixel art you see in the game was made by other people who gently provided free assets for anyone who would like to download it, here are the artists that made the arts that I used:


- frog character sprites
    - Artist: [PixelFrogStudio](https://twitter.com/PixelFrogStudio)
    - [Sprites Pack](https://pixelfrog-assets.itch.io/pixel-adventure-1)
- Sushi, Wall, Grass and Door
    - Artists: [Pixel Boy](https://twitter.com/2Pblog1) and [AAA](https://www.instagram.com/challenger.aaa/?hl=fr)
    - [Patreon](https://www.patreon.com/pixelarchipel)
    - [Sprites Pack](https://pixel-boy.itch.io/ninja-adventure-asset-pack)







---

version: 3

# Mandatory Checklist
### Game
- [x] Player goal must be collect all collectibles then escape chosing the shortest route.
- [x] moving with W, A, S, D, in four directions (and arrows).
- [x] Should not be possible to walk into walls.
- [x] Display the current number of movements in every move.
- [x] 2D view.

### Graphic management
- [x] Has to display image in a window.
- [x] Smooth window management: change to other window, minimizing window, etc.
- [x] ESC must close the window and quit the program in clean way.
- [x] Clicking on the cross on the window frame must close the window and quit the program in a clean way.
- [x] Use of images is mandatory.

### Map
- [x] Validate if map is rectangular.
- [x] Validate if the characters are all in the charset.
- [x] Validate if map has only one exit and one starting position.
- [x] Validate if map has atleast one collectible.
- [x] Validate if map is surrounded by walls.
- [x] Validate if there is a valid path in the map (for collecting all collectibles and exiting).
- [x] Map has to have `.ber` extension.
- [x] On any misconfiguration the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.

### Files
- Fix makefile, writing all source files by hand, removing undesired rules.
- Clean and organize texture files

# Bonus Checklist
- [ ] Make player lose when touch an enemy patrol.
- [ ] Add sprite animation.
- [ ] Display movement count directly on screen instead of writing it in the shell.

# My checklist
- [ ] Add a game menu.
    - [ ] Add the option to select between 3 map themes in the game menu.
        1. Frog and grass theme.
        2. Penguin and snow theme.
        3. Lizard and desert theme.
- [ ] Add a "You died" screen.
- [ ] Change door sprite (snow does not fit the theme)
- [ ] Add soundtrack to the game.
- [ ] Add soundeffects to the game.

# Public Repo checklist:
- Remove headers
- Add a screenshot to the README
- Add a how to build and play to the README
    - Create a script that sets everything (minilibx .a, make in it, make in solong etc etc...)
- Add a link to the leaktester to the README
- Add artists links and thanks in the RADME
- Add a depoimento in the README about my creative process in this project
- Delete repository with all commits, and copy files to a brand new repository.

