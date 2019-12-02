# FDF

## What is this project about?
This project is about creating a simple wireframe representation of a landscape linking various points (x, y, z) via segments. The coordinates of the points are given in a file passed as a parameter to the program:

(IMAGE)

Each number corresponds to a point in space:
* The horizontal position corresponds to its axis;
* The vertical position corresponds to its ordinate;
* The value corresponds to its altitude.

## Can I try to run this project at home?
The graphical library used in this project is the MinilibX, it is used in my university for basic graphocs projects and is not present on the repository. So for now it is not usable outside the school 42 in Paris. I will try to add the library to the repository and make it usable outside the university when i get the time to work again on this project.

## What is the structure of the input file?
The exectuble accepts files as input only under a certain set of conditions which are:
* The given map should only be made with alphanumerical character (the letters being those used for the hexadecial colors) or a comma. Every other character is considered wrong and thus invalidates the map.

> "0 0 0 0" is valid;

> "A 0 0 0" is invalid;

> "0 / 0 0" is invalid.

* The points are separated by a single space " ", whitespaces such as tabulations invalidate the map.

* Colors can be given to points by writing them next to the desired point using a comma. The comma should not be separated from the point by any space.

> "0,0xff 0 0 0" is valid, the first point is blue;

> "0 0xff 0 0 0" is invalid;

> "0 ,0xff 0 0 0" is invalid.

## What can I do once the program is launched?
The different key bound are:
* The plus "+" and minus "-" keys are used respetively to increase and reduce the altitude of the points.

* The "P" key is used to switch between the two projections (Isometric or Parallel).

* The "W" and "S" keys are used respectively to move up and down the wireframe.

* The "A" and "D" keys are used respectively to move left and right the wireframe.

* The escape "esc" key is used to close the program.

## Features I'd like to add
* Other projections (conic, ...)
* Wireframe rotations
* Antialiasing
