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
2. Start Docker Container
```shell
$ docker run -it -d --rm -v $PWD:/work --name nettrs nettrs
```
3. Generate Makefile inside Docker Container
```shell
$ docker exec nettrs cmake ..
```
4. Build nettrs inside Docker Container
```shell
$ docker exec nettrs make
```

関数の中身何も実装シてないからまだ動かないヨ！！
