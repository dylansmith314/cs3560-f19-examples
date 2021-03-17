# Contributing to class repository

## Overview

This repository is the collection of examples that are used in Ohio University's CS3560 class. For a complete example of a toy project please see `fib/`.
For Makefile related examples, please see `make.example\d+`. For focus examples on unittesting for various languages, please see `unittesting.examples`.

## Contributing

### Forking the repository

First thing that you will notice is that you cannot make any push to the repository directly. This is usually the case for all open-source projects.
What you have to do is fork the repository to your own GitHub account. With this new repository, you will have full control over the
repository including the ability to push commits.

### Adding a new remote that refer to the original repository

We will now refer to OU-CS3560/examples repository as upstream repository, and the forked one will be referred to as origin. To
be able to get new commits from the upstream repository, you can add a new remote

```console
$ git remote add upstream https://github.com/OU-CS3560/examples.git
```

where `upstream` is the name of the new remote and the URL is pointing to the upstream repository. If you run `git remote -v`,
there should now be four lines of names and URLs. Two of the URLs are for `origin`, and the other two are for `upstream`.

To get new commits from upstream repository, you can run

```console
$ git fetch upstream
```

This will only retrieve new commits from the upstream repository. It will not make any update to your local repository. To
actually update your local repository, you can run

```console
$ git merge upstream/master
```

This will merge `master` branch on `upstream` onto current branch on the local repository. You can then push this new commits
to your remote repository (the `origin` on GitHub.com).

### Create a new branch

From last section, you can see that new changes will be merged to master, so it is recommended to create a new branch for any
of the work that you want to work on, and leave master untouched. Otherwise, next time that you are updating your fork, there
will be too many merge conflicts to solve.

At this point you should notice that one branch can only create one pull request, so if you want to work on multiple pull
request, you will need multiple branches.

### Create a pull request

After you finish part or all of the work, it is when the pull request is coming in. To be able to create one, you will need to "compare across fork"
and select a branch from your repository.

For HW9, TA will then goes over your pull request. If the TA request some changes to your pull request, you can create
more commits that address the issues. When you push these new commits to your forked, GitHub should update pull request
automatically.

### Troubleshooting

#### Already made a commit on master branch

And this commit should not be included in the repository.

What you can do is to

1. Create a new branch at your latest commit on master branch.
2. On master branch run `git reset --hard <commit-id>`. For HW9 of Spring 2020-2021, you can replace the
   `commit-id>` with `ae4b482b6eba0d7083fef272f3c3e6eaa335b2c1`. For other cases, replace `<commit-id>` with
   an appropriate one.
3. Retrieve and merge new commits to your forked master branch (as described earlier).

## Technological stack

Currently, the only CI/CD system that is used is netlify. It is used to deploy doxygen documentation to https://ou-cs3560-examples.netlify.app/.

Primary build system used is GNU Make. In some cases (unittesting.examples)
a build system for the language is used
