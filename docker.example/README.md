# Dockerize Flask Application

## Building the image

``` shellsession
$ docker build -t flask-app .
```

## Using the image

``` shellsession
$ docker run -it --rm -p 5000:5000 flask-app:latest 
```

To start an interactive shell instead of running the web application server, running

``` shellsession
$ docker run -it --rm -p 5000:5000 --entrypoint /bin/bash flask-app:latest
```

## Exercises

- Use nginx to serve the static files. This requires
  a. docker-compose
  b. nginx container
  c. share volume between container.
