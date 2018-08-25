# NNetCpp
Framework for artificial neural networks in C++. NNetCpps main purpose is to allow testing of different algorithms and architectures related to neural networks.

Directory | Description
----------|------------
examples | Runnable examples of nets with training data
src | NNetCpp source code
tests | Test suites

## Documentation
The documentation is available [online](https://joelnir.github.io/NNetDocs/index.html). A pdf version as well as the website files can be found in the [documentation repository](https://github.com/joelnir/NNetDocs). Docs are always up to date with master branch.

Generating documentation locally (html + pdf) requires:
* Doxygen
* texlive (for pdf)

Generate documentation with
```Bash
make docs
```

## Building
The main program can be built using g++

```Bash
make
```

## Testing
NNetCpp features tests written using the google test framework. To run tests locally google test must be installed on the system. 

Run all tests with

```Bash
make test
```
