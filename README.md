# nettrs
ネットワーク対戦型テトリスを作りたい

## 一人用のテトリスから
### Build with Host
1. buildディレクトリ作る
2. cd ./build
3. cmake ../
4. make

### Build with Docker
1. Build Docker Image
```shell
$ cd $<PROJECT_TOPDIR>
$ docker build -t nettrs .
```
2. Execute python script in Docker Container
```shell
$ docker run --rm -u `id -u` -v $PWD:/work -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=unix$DISPLAY --name nettrs -it nettrs python3 Nettrs.py
```

関数の中身何も実装シてないからまだ動かないヨ！！
