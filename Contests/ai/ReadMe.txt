TECHNICAL CRICKET LEAGUE
is an online AI contest(the first of its kind in Cognizance) in which the participating teams will be playing a game of modified cricket against each other.
 
Rules of the game are:
Each team consists 11 players
It will be a 50-50 over game
In the starting of the match, there will be a toss using random function.
Each player will have certain batting strength before coming to the crease
After hitting, strength of batsman will decrease acc. to the distance of his shot
the batsmen specifies r and theta, the distance and angle where he wants to place his shot.
the field is divided into 5 regions with different runs(see the sample field in attacment)
If batsman's strength decreases to zero, he will be out.
Strength of the batsman at the non-striker end increases with every ball.
Fielders too have certain strength which determines their range of fielding.
fielder's strength decreases if he stops the ball and strength of rest of the fielders increases.
Before every ball the batsman knows the field positions but not the strength of the fielders.
the attachments provided to each participating team will be:
simulator file with the controller and other important functions
common.h having a structure used by both simulator and players
a sample test player 
a copy of rules and explanation of code
the task of each team is to define three functions
setbowler(): it selects the bowler before each over during fielding
fieldset(): sets the position of fielder before each ball during fielding
hit(): returns r and theta where the batsmen wants to place his shot
