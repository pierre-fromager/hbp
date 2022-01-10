# Human Body Propagation
Hbp is a c++ app to build human body limbs to modelize interactions.

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
mkdir -p build
cd build
cmake configure ..
cmake generate ..
make
```

**hpb** executable will be generated in build folder.  
**hbp_test** executable will be generated in build\test folder.

## Testing

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