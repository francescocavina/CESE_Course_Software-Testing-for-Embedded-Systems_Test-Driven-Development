## About this repository

This respository is used for a practical work from the Software Testing for Embedded Systems course (2023). This course belongs to the Master's Degree in Embedded Systems at the Universidad de Buenos Aires (UBA).

Here there is an example of the use of TDD (Test Driven Development) methodology for the development of an LED driver. The following test cases are used to develop this driver:

1. After initialization all LEDs should be off.
2. An individual LED can be turned on.
3. An individual LED can be turned off.
4. Multiple LEDs can be turned on and off.
5. All LEDs can be turned on at once.
6. All LEDs can be turned off at once.
7. The status of an LED can be queried.

## Repository Usage

This repository uses [pre-commit](https://pre-commit.com) for format validation. In order to work with it, you should have installed:

1. pre-commit
2. Clang-format

These tests use [ceedling](http://www.throwtheswitch.org/ceedling). In order to work with them, you should have installed:

1. Ruby
2. Ceedling

To run the unit tests you should run the following command:

```
ceedling
```
