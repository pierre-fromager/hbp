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

## Build

### Native

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

Tests are enable only if you build with cmake.  

Just run
```
./test.sh
```

In order to make app testable we build a lib.  
All testable entries will be tested from lib.  

Check boost build hbp_test options :
```
build/test/hbp_test --help
```

Verbose run :

```
build/test/hbp_test -l all
```

Running tests suites with a simple progressbar would be :

```
build/test/hbp_test -i true -p true
```

Essential report would be :

```
build/test/hbp_test --list_content
```

Report can be generated for various format (check --report_format option).