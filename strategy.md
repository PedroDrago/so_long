### STRATEGY

- Now the strategy is to resolve movement and stuff like that directly on the map array. And every movement, whe run the render_map() function,
which willd draw an entire new screen for the game based on the stuff on the array. May be this is a dumb idea, but for me this will be easier
to implement.

### Sound
- attack sprite will have 1 square in front of character. So calculation will be character.attacking.position = character.position + 1, and,
we chan check if character.attack.position = enemy then play dying sound, and change map.position.where.enemy was with nothing.
