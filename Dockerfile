FROM ubuntu:20.04
LABEL maintainer "LeavaTail <starbow.duster@gmail.com>"

# CMake woring directory
WORKDIR /work/build

# timezone setting
ENV DEBIAN_FRONTEND=noninteractive
RUN set -x && \
    apt-get update && \
    apt-get -y install \
         tzdata
ENV TZ=Asia/Tokyo 

# Install build dependencies
RUN apt-get -y install \
        python3 \
        python3-pip \
        libsdl-dev \
        libsdl-image1.2-dev \
        libsdl-mixer1.2-dev \
        libsdl-ttf2.0-dev \
        libsmpeg-dev \
        libportmidi-dev \
        libavformat-dev \
        libswscale-dev \
        libgd3 \
        libgd-dev && \
    pip3 install numpy \
        pygame

RUN useradd -ms /bin/bash nettrs
CMD ["/bin/sh"]
