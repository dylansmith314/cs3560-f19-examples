# Errors during git push/pull/merge

When I try to push my comits to GitHub, I got an error

```console
To github.com:OU-CS3560/hw3-git-p1-entire-class-s20-21.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'github.com:OU-CS3560/hw3-git-p1-entire-class-s20-21.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

This is happening when someone else is pushing their commits to GitHub before you do.
Dr. Liu went over this in the lecture on 02/02/2021, you can review also review that. This
document however, will goes over it step by step. You can also read through
this article [https://www.atlassian.com/git/tutorials/using-branches/merge-conflicts](https://www.atlassian.com/git/tutorials/using-branches/merge-conflicts)

If you read the error message carefully, you will notice that Git hint at you to perform pull before you are trying to push again.

```console
$ git pull
```

At this points various situations can happen.

1. Not possible to fast-forward
2. Merge conflict

## Not possible to fast-forward

This will get the new commits by others, and Git will attempt to intelligently merge the new commits with your commits.
Most of the time Git will be able to solve the merge automatically, but a merge conflict can still happen, and Git
will ask you to resolve it. The error message will look similar to this.

```console
remote: Enumerating objects: 49, done.
remote: Counting objects: 100% (49/49), done.
remote: Compressing objects: 100% (35/35), done.
remote: Total 48 (delta 7), reused 37 (delta 1), pack-reused 0
Unpacking objects: 100% (48/48), 517.41 KiB | 2.97 MiB/s, done.
From github.com:OU-CS3560/hw3-git-p1-entire-class-s20-21
   7yylnxo..e5151a4  main       -> origin/main
fatal: Not possible to fast-forward, aborting.
```

From a quick glance, everything seems fine. However, on the last line, Git tells you can there is a fatal error
where Git cannot fast-forward.

If you run `git status`, this will be the result

```console
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 12 different commits each, respectively.
  (use "git pull" to merge the remote branch into yours)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	./

nothing added to commit but untracked files present (use "git add" to track)
```

The main mesage is that

> Your branch and 'origin/main' have diverged.
> and have 1 and 12 different commits each, respectively.
>  (use "git pull" to merge the remote branch into yours)

Git is suggesting that you run `git pull`, but we did run it already and it fail (remember "fatal: Not possible to fast-forward, aborting").

If you run, `git log --graph --all --decorate --oneline`, you will see the diverging commits. Your
result may be different.

```console
* 92kmvyk (HEAD -> main) feat: add new file
| * 7g75om4 (origin/main) feat: add screenshot from machine B
| * k0dm60b feat: add screenshot from machine A
| * mbjbis0 docs: add three more lines
| * m4tf1g2 docs: add favorite color
| * 00vrm9g feat: add assignment3.md
| * weukiox fix: incorrect image
| * m3f1086 fix: delete machine-a-log.jpg
| * roqvbot feat: added screenshots
| * ehyyt0y chore: add three more lines
| * 210scc2 feat: add favorite color
| * q6go3kq fix: remove temporary file from vim
| * egj3bma feat: create a folder and file
|/  
* 7yylnxo init: add readme file
```

One branch is on the left side, and another one is on the right side. From this output, what we need to
do is to merge HEAD with origin/main, we can do that by

```console
$ git merge origin/main
```

If this goes successfully, you will have to just run `git push` (if it fail again, repeat the step again since other students may push
something during the time you are fixing this).

However, it can fail, and we will discuss this on the next section.

## Merge conflict

You are less likely to run into this problem with HW3 since you are not suppose to
editing other student files. When you run into one, Git will complain with the following message:

```console
CONFLICT (add/add): Merge conflict in gb522113/Assignment3.md
Auto-merging gb522113/Assignment3.md
Automatic merge failed; fix conflicts and then commit the result.
```

The "CONFLICT" is the big give away. The first line tells you that there is a merge conflict in a file at `gb522113/Assignment3.md`.
The next line is Git telling us that it attempts to merge content of `gb522113/Assignment3.md` automatically, but the line after Git
sadly inform you that the merge fail, and it wants you to resolve the conflict. There can be more successful auto-merge and/or more
auto-merge that fails.

Let fix this by open the file in your favorite editor, you will see something like this:

```plain
<<<<<<< HEAD
Creating merge conflict
||||||| 7yylnxo
=======
Ruby
Red
Line 0 
puts "Hello World!\n"
tk.END
>>>>>>> origin/main
```

Or this,

```plain
other-content

<<<<<<< HEAD
content-from-head
=======
content-from-origin-main
>>>>>>> origin/main

other-text
```

The different is that there will be no `common-content` and `|||||||` line. 

The main structure are these alien looking marks:

```plain
other-content

<<<<<<< HEAD
content-from-head
||||||| 7yylnxo
common-content
=======
content-from-origin-main
>>>>>>> origin/main

other-text
```

Here are the meaning of all these marking.

1. `<<<<<<<` follows, on the same line, by HEAD or commit id. This indicates the start of your conent on HEAD or on the commit id.
2. `=======` indicates the end of your content and the begining of content from others.
3. `>>>>>>` follows, on the same line, by branch name or commit id. This indicates the end of content by others. 

To resolve a merge conflict, is to decide which content you want to keep: your content, their content, or both. In a team project, we will want to consult with
your teammates, so that you are not deleting their work. I just want to demonstrate the merge conflict, so I will keep their content.
To do that, you remove all the marking and the content you do not want. Here is the end result.

```plain
Ruby
Red
Line 0 
puts "Hello World!\n"
tk.END
```

Make sure that you remove all the marking. There can be more than one of these throughout the file, make sure to look
for them. You can also check if the automatic merges is actually what you want and there is no problem with them.

Now run `git status` again, Git greets you with

```console
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 12 different commits each, respectively.
  (use "git pull" to merge the remote branch into yours)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Changes to be committed:
	new file:   ih405106/Assignment3.md
	new file:   ih405106/machine-a-log.JPG
	new file:   ih405106/machine-b-log.JPG
	new file:   gb522113/machine-a-log.jpg
	new file:   gb522113/machine-b-log.jpg

Unmerged paths:
  (use "git add <file>..." to mark resolution)
	both added:      gb522113/Assignment3.md
```

The first four lines are the message we seen before. The next three lines (after the blank line) indicates that you are solving merge conflict, and
how to conclude or abort it.

The next section is other files that either are new, or get auto-merge successfully.

The last section shows you which files contain the merge conflict. Since we already fixed them, let mark them as solve by running
`git add gb522113/Assignment3.md`.

Run `git status` again, you will see

```console
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 12 different commits each, respectively.
  (use "git pull" to merge the remote branch into yours)

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
	new file:   ih405106/Assignment3.md
	new file:   ih405106/machine-a-log.JPG
	new file:   ih405106/machine-b-log.JPG
	modified:   gb522113/Assignment3.md
	new file:   gb522113/machine-a-log.jpg
	new file:   gb522113/machine-b-log.jpg
```

Now that all merge conflicts are fixed, Git sugesst that you finish the merging (remember we get into a conflict during a merge (after we pulled new update)),
as Git suggested, you run

```console
$ git commit
```

Like any other commit command you run, you can provide message right away with `-m`, otherwise, Git will ask you for one with its default message.

```plain
Merge remote-tracking branch 'origin/main'

# Conflicts:
#       gb522113/Assignment3.md
#
# It looks like you may be committing a merge.
# If this is not correct, please run
#       git update-ref -d MERGE_HEAD
# and try again.


# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# On branch main
# Your branch and 'origin/main' have diverged,
# and have 1 and 12 different commits each, respectively.
#   (use "git pull" to merge the remote branch into yours)
#
# All conflicts fixed but you are still merging.
#
# Changes to be committed:
#       new file:   ih405106/Assignment3.md
#       new file:   ih405106/machine-a-log.JPG
#       new file:   ih405106/machine-b-log.JPG
#       modified:   gb522113/Assignment3.md
#       new file:   gb522113/machine-a-log.jpg
#       new file:   gb522113/machine-b-log.jpg
#            
```

You can just save it and be done, but let take a look. Git tells you in the first commented block
that there is conflicts and you are finishing up a merge.

In the second commented block is the message we see in `git status` with some lines removed.

Write your custom commit message or use the default one then save and exit out of
your editor. If all went well, commit will be created, and what is left is for you to push it up to GitHub by

```console
$ git puish origin main
```

Again, someone can push some new commits up, so these steps may have to be done again.
