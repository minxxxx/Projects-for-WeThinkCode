# Rubiks

This is an attempt to try and solve a rubik's cube without a strict algorithm.

## Current Progress
The solver has been put on hold for now as I had other opportunities pop up. When I get the chance, the idea is to gather training data by scrambline the solved cube and then using those moves and the implement a neural network to find patterns. The current solver uses a heuristic (Manhattan Distance from where each color should be to where it is) to give a score to a cube. The current "Solver" does a move between 1 and 3 times, checks if it has a better score than the previous score, and if it does not have a better score, undoes those moves. IT repeats that 100 times. This makes the score go down consistently, but is nowhere near actually solving the Puzzle and the finished product usually doesn't resemble a solved Rubik's cube at all.

The Cube.py is currently a working and very nice representation of a Rubik's cube that someone else may find useful in doing their own rubik's cube work.

## Installation
`pip install -r requirements.txt`


## Example

To solve a random cube:
```
>>> from CubeSolver import CubeSolver
c = CubeSolver()
c.solve() # This is not working

>>> print c.cube
      [][][]
      [][][]
      [][][]
[][][][][][][][][]
[][][][][][][][][]
[][][][][][][][][]
      [][][]
      [][][]
      [][][]
      [][][]
      [][][]
      [][][]

# This will print the cube's layout in color

>>> 
```

To make a cube and play around with it:
```

>>> from Cube import Cube
>>> cube = Cube()
>>> print cube
      [][][]
      [][][]
      [][][]
[][][][][][][][][]
[][][][][][][][][]
[][][][][][][][][]
      [][][]
      [][][]
      [][][]
      [][][]
      [][][]
      [][][]

     # This prints in color

>>> cube.R()  # This turns the right side of the cube clockwise
>>> cube.R()
>>> cube.Ri(2) # This should put the cube back in its original position

```

Available moves:  
cube.R(): Turns the right side clockwise  
cube.Ri(): Turns the right side counterclockwise  
cube.L(): Turns the left side clockwise  
cube.Li(): Turns the left side counterclockwise  
cube.B(): Turns the back side clockwise  
cube.Bi(): Turns the back side counterclockwise  
cube.D(): Turns the bottom clockwise  
cube.Di(): Turns the bottom counterclockwise  
cube.F(): Turns the front clockwise  
cube.Fi(): Turns the front counterclockwise  
cube.U(): Turns the top clockwise  
cube.Ui(): Turns the top counterclockwise  
