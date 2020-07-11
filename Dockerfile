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
RUN set -x && \
    apt-get -y install \
        build-essential \
        cmake \
        libsdl2-dev \
        libsdl2-image-dev \
        libjpeg-dev \
        libpng-dev \
        libtiff-dev \
        libwebp-dev

CMD ["/bin/sh"]
