## Create an archive

```console
$ tar cvf archive.tar *.md *.cc
```
To zip archive while creating it

```console
$ tar czvf archive.tar.gz *.md *.cc
```

To zip archive after creating it without `z` option.

```console
$ gzip archive.tar
```

## List table of content

```console
$ tar tvf archive.tar
```

## Extract

```console
$ tar xvf archive.tar

```
