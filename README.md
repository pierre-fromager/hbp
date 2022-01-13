# Human Body Propagation
Hbp is a c++ app to build human body limbs to modelize interactions.

## Description

Each limb is connected to trunc(as a limb) through a double linked node collection.  
It features to propagate backward and forward (up2u).  
As you may know, double linked node let you connect a prev and a next node, but what happen if you have to connect multiple nodes to a target node ?  
In order to do that you can set a prev on a node attaching this way multiple limbs to a single limb(arms,legs,head->trunc), then use the member backReference to get all neighbour nodes.

## Requirements

No external dependencies required to build app from the makefile.  
Using CMake would require CMake.  
Testing app with Boost would require Boost framework.  

## Main sample

We figure out to sum both limbs surfaces and volumes for given parsed options input.  
You could think about howto modelize a specific limb root to operate so.  
Volumes and surfaces ratios are approximated, use your own datas to match your features.

## Build

### Makefile

```
make
```

**hpb** executable will be generated in root project.

### CMake

```
./build.sh
```

**hpb** executable will be generated in build folder.  
**hbp_test** executable will be generated in build\test folder.

## Testing

Tests are only enable if you build with cmake.  

Just run
```
./test.sh
```

In order to test app we build a static lib first (hbp_lib => libhbp_lib.a).  
Then we run tests suites against this.  

Check boost build hbp_test options :
```
build/test/hbp_test --help
```
Verbose run command
```
build/test/hbp_test -l all
```
Running tests suites with a simple progressbar command would be
```
build/test/hbp_test -i true -p true
```
Sample output
```
Running 12 test cases...
Platform: linux
Compiler: GNU C++ version 6.3.0 20170516
STL     : GNU libstdc++ version 20170516
Boost   : 1.78.0

0%   10   20   30   40   50   60   70   80   90   100%
|----|----|----|----|----|----|----|----|----|----|
***************************************************
```
Essential report command would be
```
build/test/hbp_test --list_content
```
Sample output
```
TestSuiteHumanRatios*
    MaleGetter*
    FemaleGetter*
    MaleWeight*
    MaleSize*
    FemaleWeight*
    FemaleSize*
TestSuiteEllipsoid*
    GetZeroes*
    GetOnes*
    GetTwos*
TestSuiteModelEllipsoid*
    InCsvZeroes*
    InCsvOnes*
    InCsvRamp*
```

Reports can be generated for various format (check --report_format option) to make CI easy.

## Todo

* Integrate surface/volume calc from ellipsoid for limb modelization.
* Externalize and specialize human body callbacks on propagation backward and forward.
* Use assets loader from human body (csv) to assimilate limb's datas as ellipsoid object.
* Introduce thermodynamic calc from datas (surface/volume) on body pulse.
