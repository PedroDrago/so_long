# Mandatory Checklist

### Game
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
- [ ] Add soundtrack to the game.
- [ ] Add soundeffects to the game.

# Public Repo checklist:
- Delete libft directory
    - Add libft used functions source code to src.
    - Add these functions to the header.
- Remove headers
- Add a screenshot to the README
- Add a how to build and play to the README
    - Create a script that sets everything (minilibx .a, make in it, make in solong etc etc...)
- Add a link to the leaktester to the README
- Add artists links and thanks in the RADME
- Add a depoimento in the README about my creative process in this project
- Delete repository with all commits, and copy files to a brand new repository.

### Art Sources
- Font: https://opengameart.org/content/sharp-retro-font

### Frog
- Linces: https://creativecommons.org/publicdomain/zero/1.0/
- Artist: https://twitter.com/PixelFrogStudio

### Ninja pack
- Linces: https://creativecommons.org/publicdomain/zero/1.0/
- Artist: https://twitter.com/2Pblog1 and https://www.instagram.com/challenger.aaa/?hl=fr
- Patreon: https://www.patreon.com/pixelarchipel
