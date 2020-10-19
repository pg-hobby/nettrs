# nettrs
ネットワーク対戦型テトリスを作りたい

![demo](https://user-images.githubusercontent.com/33386353/94367078-2580b680-0117-11eb-870d-7240731f1ac1.gif)

## Usage
### Build with Host
1. Install requirement package
2. Execute server in Docker Container
3. Execute client in Docker Container

### run with Docker
1. Build Docker Image
```shell
$ cd $<PROJECT_TOPDIR>
$ docker build -t nettrs .
```
2. Execute server in Docker Container
```shell
$ docker run --rm -u nettrs -v $PWD:/work:ro -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY -it nettrs ./server.py
```
3. Execute client in Docker Container
```shell
$ docker run --rm -u nettrs -v $PWD:/work:ro -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY -it nettrs ./client.py
```

### run with Docker-Compose
1. Build Docker Image to use Docker-Compose
```shell
$ cd $<PROJECT_TOPDIR>
$ docker-compose up -d
```
2. Execute server in Docker Container
```shell
$ docker-compose exec server ./server.py
```
3. Execute client in Docker Container
```shell
$ docker-compose exec client1 ./client.py
```
* Notice: You can switch `client1` to `client2`

## Requirement
* [numpy](https://numpy.org/)
* [pygame](https://www.pygame.org/news)
