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
- GNU/Linux based distribution
- gcc
- cmake
- python3
    - matplotlib
    - pandas
    - sys

(I used: `Debian GNU/Linux 12.6 (bookworm)`, `gcc 12.2.0`, `cmake 3.25.1`, `Python 3.11.2`)

To define the variables edit the `projectile.cfg` and `environment.cfg` files.

To build and run the program type:
```bash
$ ./build.sh
$ ./run.sh <filename>
```

This outputs data to `filename.csv`.

This file was last edited (dd.mm.yyyy): _30.07.2024_

