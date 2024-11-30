# projectile_sim
This program simulates the flight of a projectile based on given variables.\
For flexibility the velocity vector is not reliant on the starting angle.\
Otherwise use:
<pre>
      /|
     / |
  v /  |
   /   |v0y
  /    |
 /     |
/a_____|
   v0x
</pre>
cos(a)=_v0x/v_\
sin(a)=_v0y/v_

Therefore:
_v0x_=cos(a)\*v\
_v0y_=sin(a)\*v

## Dependencies
- Unix like OS
- gcc
- cmake
- libinih-dev
- python3
    - matplotlib
    - pandas
    - sys

To define the variables edit the `sim.ini` file.

To build and run the program type:
```bash
$ ./build.sh
$ ./run.sh <filename>
```

This outputs data to `filename.csv`.

This file was last edited: 2024-11-30

