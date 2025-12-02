The Pet Care Game is a  interactive simulation where the player takes care of a virtual pet by performing different actions such as feeding, playing, and cleaning.
Each action affects the pet’s hunger, happiness, and cleanliness levels.
If the wrong action is chosen at the wrong time, the pet's condition worsens, making the game more challenging and realistic.

The aim is to keep your pet healthy, happy, and alive for as long as possible.
# How the game works:
 the user has to choose one of the options to win-

⚠️ Wrong choices decrease pet’s stats and if your poinnts comes to zero the game ends and user loses

🔄 Loop-based continuous gameplay till score is 100(win) or 0(lose)

😶‍🌫️ Pet shows random reactions & conditions
 
🧠 Game Logic (How It Works)
1. Pet Stats

The game maintains internal variables for:

hunger

happiness

cleanliness

These change based on your actions.

2. Main Game Loop

The game is built around an infinite loop:

while(true) {
    show menu
    player chooses action
    update pet stats
    show pet status
}


This keeps the game running until the player exits (or pet dies in strict versions).

3. Action Handling

The player chooses between:

1️ Play

Increases mood/happiness

But decreases hunger

Sometimes the game shows “wrong option” if the pet is too hungry or dirty to play

2️ Feed

Decreases hunger

But if over-fed, happiness drops

3️ Clean

Increases hygiene

Sometimes mood decreases (pets often dislike bathing)

4. Random Behaviour

The game uses:

rand() % 3;


to randomly:

Choose wrong reactions

Influence mood

This mimics real pet behaviour.

5. Conditions & Warnings

If the player does the wrong thing:

Playing when pet is starving → hunger decreases further

Feeding when pet wants to play → happiness decreases

Cleaning when pet is already clean → no effect or negative reaction
# Concepts Used (C Language):

This game demonstrates:

while loops

if-else decision making

switch-case menu handling

Random number generation (rand())
Thankyou

Th
Functions for modular code
