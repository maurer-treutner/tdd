FROM ubuntu:18.04

  
RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libstdc++-7-dev
RUN apt-get install -y cmake
RUN apt-get install -y git
RUN apt-get install -y libboost-test-dev
RUN apt-get install -y python

RUN mkdir -p /project
VOLUME /project

COPY . /project

CMD cd /project && ./build.sh
