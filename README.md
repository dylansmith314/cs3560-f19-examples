# CS3560 - Example Project

This repo is used for other students to practice git pull requests.

Example project that uses Doxygen, Makefile, Catch2, Travis CI.
This project is also used for students to practice with git pull requests

This is a simple project that contains some of the tools used in the class. For example,

- .gitignore
- Git with commit message in Commitizen convention ([https://commitizen.github.io/cz-cli/](https://commitizen.github.io/cz-cli/)).
- Makefile
- Doxygen with Netlify
- Catch2
- Travis CI (The idea of integrating this into class is heavily influenced by Mr. Robert Foreman).
- maybe Google Test Framework (using Docker image)
- This repo is also used for students to practice git pull requests

## Git with commit message in Commitizen convention

Some of commit message in this repository are following the Commitizen convention
([https://commitizen.github.io/cz-cli/](https://commitizen.github.io/cz-cli/)).

## Doxygen with Netlify

The `fib` example contains configuration of [Doxygen](http://www.doxygen.nl/) (`fib/Doxygfile`) and [Netlify](https://www.netlify.com/) (`netlify.toml`)
that automatically build doxygen (using `cd fib && make doc`), and publish the generated document
to [https://ou-cs3560-examples.netlify.com/](https://ou-cs3560-examples.netlify.com/).

## How to connect to 3rd Floor Linux Computers from ...

### Windows

1. Open the Command Prompt or Windows PowerShell. It can be opened in various methods:
   - For the Command Prompt, type in WINDOWS-R, then type in "cmd" in the dialog box.
   - Bring up start menu, and serach for "Command Prompt" or "PowerShell"

2. In the window with the command prompt (or powershell), type in the command for ssh:

```console
ssh username@pu1.cs.ohio.edu
```

Don't forget to replace the `username` with your actual username (it is not the same one as the email handle). If you forget your username, or password you can contact the system administrator, Mr. Carl Hawes.

If the error mentioned the ssh command not found, you need to enable OpenSSH client feature by search for "Manage optional features" in the start menu,
and click "Add a feature", then search for "OpenSSH Client", and install it.

For example, here is the output from the using `ssh changliu@pu1.cs.ohio.edu` in command prompt

```console
C:\Users\Chang Liu>ssh changliu@pu1.cs.ohio.edu
The authenticity of host 'pu1.cs.ohio.edu (132.235.1.15)' can't be established.
ECDSA key fingerprint is SHA256:PCIKPlKu35MHGF+zSgDUbEvFRNDN8vapyp7lYVI+O8Q.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'pu1.cs.ohio.edu,132.235.1.15' (ECDSA) to the list of known hosts.
changliu@pu1.cs.ohio.edu's password:


      NEW SERVER CONFIGURATION:

  pu1.cs.ohio.edu has the same configuration as the machines in
  room 307, including tesla video card. Using this machine remotely
  instead of one of the ones in 307 for graphics will avoid
  conflicts with anyone logged in at the workstation.

   pu2.cs.ohio.edu is a nice 16 core ubuntu server with an Intel Xeon CPU
   with 2 threads per core, and  24 gigs of ram

   pu3.cs.ohio.edu  is a very nice ubuntu server with an AMD 32 core
   Processor, 2 treads per core, and 32 gig of ram.


   p1.cs.ohio.edu  and p2.cs.ohio.edu
   are Sun Sparc cpu based machines that run Solaris 10.

   px1.cs.ohio.edu is an x86 based machine running ubuntu.

   tesla2.cs.ohio.edu is an x86 with 2 nvidia cards, one of
   which is a tesla card

   The Solaris machines are nice to check the execution of your
   programs on as the different architectures often expose
   bugs you would not normally see.

  RATHER THAN SSH INTO A WORKSTATION IN THE LABS , PLEASE USE OUR SERVERS.
Last login: Wed Nov 20 13:25:21 2019 from 74.113.47.217
.bash_profile executed.
changliu@pu1:~$ which doxygen
/usr/bin/doxygen
changliu@pu1:~$ doxygen
error: Doxyfile not found and no input file specified!
Doxygen version 1.8.13
...
```
pu[1-3].cs.ohio.edu are the preferred remote servers. odd[?].cs.ohio.edu are the workstations in the 3rd floor lab.

You also have an option to use software like [PuTTY](https://www.putty.org/). To connect click on session on the left side bar, and enter pu[1-3].cs.ohio.edu for "Host Name". Make sure that "Connection Type" is SSH. Then you can click open, PuTTY will prompt you for a username and password.

### MacOS

Follow the same steps for Windows, but use "Terminal" app instead.

### Connect via vscode

By using the extension call Visual Studio Code Remote Development [https://code.visualstudio.com/docs/remote/remote-overview](https://code.visualstudio.com/docs/remote/remote-overview), you can use vscode on your laptop (or from PC in the classroom; see the first extra note) to edit a file on the school server.

You will also have access to GUI for git that vscode has as well. But do not forget to still study which Git command does what since this class is focusing on that.

To have a better experience, you will have to use SSH key authentication where you are not required to type password every time you are logging into the school server. Please see this article for how to do it: [https://www.digitalocean.com/community/tutorials/how-to-configure-ssh-key-based-authentication-on-a-linux-server](https://www.digitalocean.com/community/tutorials/how-to-configure-ssh-key-based-authentication-on-a-linux-server)

This is what I usually have in my ~/.ssh/config for the school server.

![ssh-config](./.github/images/ssh-config.png)

Then in the extension you will see the list of SSH targets.

![ssh-config](./.github/images/ssh-targets-list.png)

Then you can connect to the school server and edit file from within vscode.


## TkInter On macOS

Background: https://www.python.org/download/mac/tcltk/

To use ActiveState's Tcl and Python from python.org
https://stackoverflow.com/questions/53930597/updating-tcl-tk-version-of-homebrew-python3-on-macos
https://www.activestate.com/products/tcl/downloads/

To use Homebrew's tcl-tk and pyenv 
https://stackoverflow.com/questions/58400564/tcl-tk-tkinter-not-installing-via-homebrew-pyenv-on-macos-mojave

## Labels And Their Meanings: 

**Standard Labels:**
- These are standard labels that can be commonly used in repositories to help identify what the pull request or issue needs
- breaking - Introduces a breaking change. 
- good first issue - Indicates a good first issue for first-time contributers.
- help - Indicates that the maintainer wants help in an issue or pull request. 

**Effort Labels:**
- The label effort:<number> indicates the relative effort needed to complete this pull request or issue. 
- These labels use a scale of fibonacci numbers from 1 to 13. 
- Examples: effort: 1, effort: 13, effort: 8

**Priority Labels:**
- These labels let the users know how urgent these issues or pull requests are, giving them a time frame of when they need to be resloved
- These labels start with 'priority' then are followed by the time frame. 
- Examples: priority: now, priority: 2day, priority: soon

**State Labels:**
- These labels describe the decision state of the issue or pull request.
- Examples: state: approved, state: blocked, state: inactive, state: pending
  - state: approved - this means that it is approved to proceed
  - state: blocked - this means that something is blocking this action from happening
  - state: inactive - this means no action is needed or possible, the issue is either fixed or addressed better in other issues
  - state: pending - this means that the action is being done but a few things need to happen first

**Type Labels:**
- This label describes the type of issue or pull request it is. It is structured this way type:<what type it is>.
- Examples: type: bug, type: fix, type: feature, ect...
  - type: bug - this means that something isn't working
  - type: chore - this means that there needs to be reorganizing done of the folder structure and other necessary tasks, but they aren't very impactful to the code
  - type: docs - this means that something related to documentation or information needs addressed
  - type: discussion - this means that there are questions, proposals, and other information that requires discussion
  - type: feature - this means that there is a brand new functionallity, features, pages, workflows, endpoints, ect..
  - type: fix - this means there is are iterations on an extisting feature/s or infrastructure
  - type: security - this means that something is vulnerable or not secure
  - type: testing - this means that this thing is related to the testing process

**Work Labels:**
- These Labels describe the kind of work involved in resolving the issue using Cynefin framework. 
 Cynefin framwork is a framework used in decision making, it offers different domains to help managers to characterize situations and make sense of behavior. 
- Examples : work: complex, work: obvious
  - work: chaotic - this means the situation is chaotic and that novel practices were used
  - work: complex - this means that the situation is complex and that emergent practices were used
  - work: obvious - this means that the situation at hand is obvious and that the best practices were used
  - work: complicatied - this means that the situation at hand is complicated and good practices were used

**Other Labels:**
- These labels don't use a prefix just like the standard labels.
  - semantic-release - this uses the commit messages to determine the type of changes in the codebase, it automatically determines the nest semantic version number      
                     and generates a changelog and publishes the release.
  - greenkeeper - this gives real-time automated dependency updates for npm and GitHub

