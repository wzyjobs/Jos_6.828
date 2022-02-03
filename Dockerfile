FROM ubuntu:16.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt update && apt install -y tcl

# 安装依赖
RUN apt-get -y update
RUN apt-get install -fy --fix-missing git build-essential gcc-multilib gdb-multiarch python2.7 pkg-config zlib1g-dev libglib2.0-dev libpixman-1-dev

RUN apt-get -y install zsh python2.7 vim curl 
CMD ["zsh"]