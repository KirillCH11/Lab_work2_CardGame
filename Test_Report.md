Testing game paths:
1) Ensured each path (Evil, Virtue, Power) has unique text and a distinct final outcome (the final endings differ based on the path).
   - Manual test: I played each path to confirm the correct challenges are triggered and the correct ending scenario is shown.

Testing the combat system and inventory:
1) I checked the random item drop logic in each challenge (the user picks from 3 chests, but the actual item is randomly generated pass/fail).
2) Verified that upgrading/downgrading occurs properly after the dice game with the wizard. The unit test for Rarity also supports correctness.

Testing endings:
1) Each path leads to a different outcome (bad, good, neutral). I verified it changes based on path==1, path==2, path==3 in the final code.
2) Confirmed the game transitions smoothly from scene to scene: 
   - The player faces three challenges, then meets wizard (mini-game or skip), then final battle with the duke. 
   - The code logs or prints appropriate text, verifying interactivity.

User Interface Testing:
1) The console-based interface is simple but straightforward: 
   - The player sees textual prompts (choose 'a'/'d', choose chest #, etc.). 
   - I observed no major confusion points during manual walkthrough.
