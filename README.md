# projectile_sim
This program simulates the flight of a projectile based on given variables.

## Dependencies
- GNU/Linux based distribution
- gcc
- cmake
- python3
    - matplotlib
    - csv

I used: `Debian GNU/Linux 12 (bookworm)`, `gcc 12.2.0`, `cmake 3.25.1`, `Python 3.11.2`

To define the variables edit the `src/projectile.h` and `src/environment.h` files.

To build and run the program type:
```bash
$ ./build.sh
$ ./build/projectile_sim filename
```

This outputs data to `filename.csv`.

This file was last edited (dd.mm.yyyy): _21.12.2023_

