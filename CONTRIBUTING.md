# Contributing to class repository

## Overview

This repository is the collection of examples that are used in Ohio University's CS3560 class. For a complete example of a toy project please see `fib/`.
For Makefile related examples, please see `make.example\d+`. For focus example on unittesting for various languages, please see `unittesting.examples`.

## Contributing

First thing that you will notice is that you cannot make any push to the repository directly. This is is usally the case for all opensource project.
What you have to do is fork the repository to your own GitHub account. With this new repository, you will have full control over the
repository including the ability to push commits.

After you finish part or all of the work, it is when the pull request is comming in. To be able to create one, you will need to "compare across fork"
and selec a branch from your repository.

## Technological stack

Currently, the only CI/CD system that is used is netlify. It is used to deploy doxygen documentation to https://ou-cs3560-examples.netlify.app/.

Primary build system used is GNU Make. In some cases (unittesting.examples)
a build system for the language is used
