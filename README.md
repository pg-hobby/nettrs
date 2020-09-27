# nettrs
ネットワーク対戦型テトリスを作りたい

## Usage
1. Build Docker Image
```shell
> cd $<PROJECT_TOPDIR>
> docker build -t nettrs .
```
2. Start Docker Container
```shell
> docker run --rm -u nettrs -v $PWD:/work -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY --name nettrs -it nettrs python3 Nettrs.py
```
