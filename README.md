# nettrs
ネットワーク対戦型テトリスを作りたい

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
$ docker run --rm -u nettrs -v $PWD:/work:ro -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY --name nettrs -it nettrs python3 server.py
```
3. Execute client in Docker Container
```shell
$ docker run --rm -u nettrs -v $PWD:/work:ro -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY --name nettrs -it nettrs python3 client.py
```

### run with Docker-Compose
1. Build Docker Image to use Docker-Compose
```shell
$ cd $<PROJECT_TOPDIR>
$ docker-compose up -d
```
2. Execute server in Docker Container
```shell
$ docker-compose exec server python3 server.py
```
3. Execute client in Docker Container
```shell
$ docker-compose exec client1 python3 client.py
```
* Notice: You can switch `client1` to `client2`

## Requirement
* [numpy](https://numpy.org/)
* [pygame](https://www.pygame.org/news)
