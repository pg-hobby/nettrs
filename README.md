# nettrs

ネットワーク対戦型テトリスを作りたい

![demo](https://user-images.githubusercontent.com/33386353/97178805-5a962c80-17db-11eb-8062-33f38cb67e8f.gif)

## Description

![structure](https://user-images.githubusercontent.com/33386353/97177621-c7102c00-17d9-11eb-9dcc-a530fd591028.png)

:warning: Currently, the server's destination is build-in (`127.0.0.1:5000`)

## How to Start

To start Game, You need set up a server.

```shell
python3 server.py
```

- :speech_balloon: You can use Docker image prepared.

```shell
docker build -t nettrs .
docker run --rm -u nettrs -v $PWD:/work:ro -it nettrs ./server.py
```

After that, Player execute tetris viewer.

```shell
python3 client.py
```

The game will start when two players connected.

## Usage

| Key   | Action     |
|:------|:-----------|
|`←`   | Move left  |
|`→`   | Move right |
|`↓`   | Soft drop  |
|`↑`   | Hard drop  |
|`Space`| Rotate     |

## Requirement

- [numpy](https://numpy.org/)
- [pygame](https://www.pygame.org/news)
