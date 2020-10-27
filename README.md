# Harmony Tools

in the future this may contain more music related command line tools

right now it contains a simple console app that can spit out the possible chords generated by using Arvo Part's Tintintabulation technique with a given chord and scale

## example usage
```
./chord-pallet "0 2 4 5 7 9 11" "1 4 8"

C
Cb13
Dm9
Em6
Em
Dbm
Fb13
Fmaj7
G6
Am
Bdim7
Dbm7
```

## build instructions

1. you need cmake
1. `cmake CMakeLists.txt`
1. `make`

## testing instructions
1. do the above in "build instructions"
1. `make test`
