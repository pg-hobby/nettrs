
sudo docker stop nettrs

sudo docker rm nettrs

sudo docker build -t nettrs .

sudo docker run -it -d --rm -v $PWD:/work --name nettrs nettrs

sudo docker exec nettrs cmake ..

sudo docker exec nettrs make
