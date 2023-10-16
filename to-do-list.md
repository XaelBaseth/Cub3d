<h1>Main menu</h1>
<img src=https://github.com/XaelBaseth/Cub3d/blob/main/README/main_menu.png>
The main menu should be available only if the player doesn't add the level name parameter (so only with ``./cub3d``)

- Play button shows a level selection menu. Maybe do an unlocking level system (booleans that are true when the player reaches the end of a level).
- Controls button shows the controls, probably just a fullscreen image with the esc key to go back.
- Quit button that actually quits the game!

  <h1>Save system</h1>
  To let the player unlock the levels as he wants.
  
  Useful only for our levels. If a player adds a level, he won't be able to save its lock state. But he still can start the game with the new level name as parameter ``./cub3d new_level.cub``.

  A simple file with the unlocked levels booleans.
